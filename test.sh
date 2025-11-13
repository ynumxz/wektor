#!/usr/bin/env bash
set -euo pipefail

echo "Running tests..."
echo

# Path to executable
prog="./main"

# Check that the program exists
if [ ! -x "$prog" ]; then
  echo "Error: $prog not found or not executable."
  exit 1
fi

# Find all input files (sorted numerically)
inputs=(tests/in*)
if [ ${#inputs[@]} -eq 0 ]; then
  echo "No input files found in 'tests/'."
  exit 1
fi

# Track overall pass/fail
all_passed=true
test_count=0

for infile in "${inputs[@]}"; do
  test_count=$((test_count + 1))
  num="${infile##*in}"           # Extract suffix number (e.g., in1 → 1)
  outfile="tests/out${num}"      # Expected output file

  echo "Test #$num:"
  echo "  Input: $infile"
  echo "  Expected output: $outfile"

  if [ ! -f "$outfile" ]; then
    echo "  ❌ Missing expected output file: $outfile"
    all_passed=false
    echo
    continue
  fi

  # Run program with redirected input, capture stdout
  output="$($prog < "$infile" 2> /dev/null)"
  exit_code=$?

  # Check exit status
  if [ $exit_code -eq 0 ]; then
    echo "  ✅ Program exited with status 0"
  else
    echo "  ❌ Program exited with non-zero status: $exit_code"
    all_passed=false
  fi

  # Read expected output
  expected_output="$(< "$outfile")"

  # Compare outputs (string comparison)
  if [ "$output" == "$expected_output" ]; then
    echo "  ✅ Output matches expected"
  else
    echo "  ❌ Output differs"
    echo "----- Expected -----"
    echo "$expected_output"
    echo "------ Got ---------"
    echo "$output"
    echo "--------------------"
    all_passed=false
  fi

  echo
done

if [ "$all_passed" = true ]; then
  echo "🎉 All $test_count tests passed."
  exit 0
else
  echo "❌ Some tests failed."
  exit 1
fi
