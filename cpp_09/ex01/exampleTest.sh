#!/bin/sh

DEF_COLOR="\033[0;39m"
RED="\033[0;91m"
GREEN="\033[0;92m"
YELLOW="\033[0;93m"

exec="./RPN"

compare() {
    echo "$exec \"$1\"";
    output=$($exec "$1")
    if [ "$output" = "$2" ]; then
        echo "✅ \"$1\" = $output"
    else
        echo "❌ expected $2 but got $output"
    fi
    echo
}

compare "8 9 * 9 - 9 - 9 - 4 - 1 +" "42"

compare "7 7 * 7 -" "42"

compare "1 2 * 2 / 2 * 2 4 - +" "0"

compare "(1 + 1)" "ERROR"
