#!/bin/sh

DEF_COLOR="\033[0;39m"
RED="\033[0;91m"
GREEN="\033[0;92m"
YELLOW="\033[0;93m"

EXEC="../RPN"
TOTAL=0
SUCCESS=0
FAILED=0

compare() {
	TOTAL=$(expr $TOTAL + 1)
    echo -n "$EXEC \"$1\"";
    OUTPUT=$($EXEC "$1")
    if [ "$OUTPUT" = "$2" ]; then
		SUCCESS=$(expr $SUCCESS + 1)
        echo "\t✅ => $OUTPUT"
    else
		FAILED=$(expr $FAILED + 1)
        echo "\t❌ expected $2 but got $OUTPUT"
    fi
}

compare "8 9 * 9 - 9 - 9 - 4 - 1 +" "42"
compare "7 7 * 7 -" "42"
compare "1 2 * 2 / 2 * 2 4 - +" "0"
compare "(1 + 1)" "ERROR"

echo
if [ $TOTAL = $SUCCESS ]; then
	echo "✅ All test pass $SUCCESS/$TOTAL"
else
	echo "❌ $FAILED/$TOTAL test FAILED"
fi
