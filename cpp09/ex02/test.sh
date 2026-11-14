#!/usr/bin/env bash
# test.sh - correctness and error-handling tests for PmergeMe.
# Every sorted output is compared against the system's `sort -n` with diff,
# so a test passes only if the result is exactly right, not "looks sorted".
#
# Usage (from ex02/):  make && ./test.sh

set -u

BIN=./PmergeMe
PASS=0
FAIL=0

# Scratch files live outside the repository and are removed on exit.
TMP=$(mktemp -d)
trap 'rm -rf "$TMP"' EXIT

if [ ! -x "$BIN" ]; then
	echo "PmergeMe not found: run 'make' first." >&2
	exit 1
fi

ok() { PASS=$((PASS + 1)); echo "[OK] $1"; }
ko() { FAIL=$((FAIL + 1)); echo "[KO] $1"; }

# Random input generators: shuf on Linux, jot on macOS.
rand_unique() { # $1 = count, $2 = max
	if command -v shuf >/dev/null; then shuf -i 1-"$2" -n "$1"
	else jot - 1 "$2" | sort -R | head -n "$1"; fi
}
rand_dupes() { # $1 = count, $2 = max
	if command -v shuf >/dev/null; then shuf -r -i 1-"$2" -n "$1"
	else jot -r "$1" 1 "$2"; fi
}

# check_sort NAME ARGS...
# Expects: exit 0, exactly 4 output lines, "After:" identical to sort -n.
check_sort() {
	local name=$1; shift
	"$BIN" "$@" > "$TMP/out" 2> "$TMP/err"
	local rc=$?
	sed -n 's/^After: *//p' "$TMP/out" | tr -s ' ' '\n' | sed '/^$/d' > "$TMP/got"
	printf '%s\n' "$@" | tr -s ' ' '\n' | sed '/^$/d' | sort -n > "$TMP/exp"
	if [ "$rc" -eq 0 ] && [ "$(wc -l < "$TMP/out")" -eq 4 ] \
		&& diff -q "$TMP/exp" "$TMP/got" > /dev/null; then
		ok "$name"
	else
		ko "$name (exit=$rc)"
	fi
}

# check_error NAME ARGS...
# Expects: exit != 0, nothing on stdout, a line starting with "Error" on stderr.
check_error() {
	local name=$1; shift
	"$BIN" "$@" > "$TMP/out" 2> "$TMP/err"
	local rc=$?
	if [ "$rc" -ne 0 ] && [ ! -s "$TMP/out" ] && grep -q '^Error' "$TMP/err"; then
		ok "$name"
	else
		ko "$name (exit=$rc)"
	fi
}

echo "== Correctness (compared with sort -n)"
check_sort "subject example"            3 5 9 7 4
check_sort "8 distinct values"          42 7 13 1 99 5 23 8
check_sort "1 element"                  42
check_sort "2 elements"                 2 1
check_sort "3 elements"                 3 1 2
check_sort "single quoted argument"     "3 5 9 7 4"
check_sort "0 and INT_MAX"              0 2147483647 0
check_sort "3000 already sorted"        $(seq 1 3000)
check_sort "3000 reverse sorted"        $(seq 3000 -1 1)
check_sort "3000 identical values"      $(yes 7 | head -n 3000)
check_sort "3000 alternating dupes"     $(for i in $(seq 1 1500); do echo 5 1; done)
check_sort "3000 random unique"         $(rand_unique 3000 100000)
check_sort "3000 random with dupes"     $(rand_dupes 3000 1000)

# Sizes 1..64 cross several Jacobsthal group boundaries (3, 5, 11, 21, 43)
# and both parities (odd leftover / no leftover).
sizes_ok=1
for n in $(seq 1 64); do
	"$BIN" $(rand_dupes "$n" 20) > "$TMP/out" 2>&1 || { sizes_ok=0; break; }
	sed -n 's/^Before: *//p' "$TMP/out" | tr -s ' ' '\n' | sed '/^$/d' | sort -n > "$TMP/exp"
	sed -n 's/^After: *//p'  "$TMP/out" | tr -s ' ' '\n' | sed '/^$/d' > "$TMP/got"
	diff -q "$TMP/exp" "$TMP/got" > /dev/null || { sizes_ok=0; break; }
done
[ "$sizes_ok" -eq 1 ] && ok "random sizes 1..64 with dupes" || ko "random sizes 1..64 (failed at n=$n)"

echo
echo "== Error handling (Error on stderr, exit != 0)"
check_error "no arguments"
check_error "negative number"           -1 2
check_error "explicit plus sign"        +5
check_error "letters"                   1a
check_error "decimal"                   1.5
check_error "INT_MAX + 1"               2147483648
check_error "empty argument"            ""
check_error "valid + empty argument"    3 ""

echo
echo "== Evaluation sheet commands (timing is informational)"
echo "-- shuf -i 1-1000 -n 3000 (no repeats: yields only 1000 values)"
"$BIN" $(rand_unique 3000 1000) | tail -n 2
echo "-- 3000 values with duplicates (equivalent to jot -r 3000 1 1000)"
"$BIN" $(rand_dupes 3000 1000) | tail -n 2

echo
echo "== Result: $PASS passed, $FAIL failed"
[ "$FAIL" -eq 0 ]
