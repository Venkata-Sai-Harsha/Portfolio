#!/usr/bin/bash
case $# in
0) set `date`: m=$2; y=$6 ;;
1) m1=$(echo $1 | cut -d'-' -f1); m2=$(echo $1 | cut -d'-' -f2); set 'date'; y=$6 ;;
2) m1=$(echo $1 | cut -d'-' -f1); m2=$(echo $1 | cut -d'-' -f2); y=$2 ;;
*) m1=$1; m2=$2; y=$3 ;;
esac

case $m1 in
jan*|Jan*) m1=1 ;;
feb*|Feb*) m1=2 ;;
mar*|Mar*) m1=3 ;;
apr*|Apr*) m1=4 ;;
may*|May*) m1=5 ;;
jun*|Jun*) m1=6 ;;
jul*|Jul*) m1=7 ;;
aug*|Aug*) m1=8 ;;
sep*|Sep*) m1=9 ;;
oct*|Oct*) m1=10 ;;
nov*|Nov*) m1=11 ;;
dec*|Dec*) m1=12 ;;
[1-9]|10|11|12) ;;
*)   y=$m1; m1="" ;;
esac

case $m2 in
jan*|Jan*) m2=1 ;;
feb*|Feb*) m2=2 ;;
mar*|Mar*) m2=3 ;;
apr*|Apr*) m2=4 ;;
may*|May*) m2=5 ;;
jun*|Jun*) m2=6 ;;
jul*|Jul*) m2=7 ;;
aug*|Aug*) m2=8 ;;
sep*|Sep*) m2=9 ;;
oct*|Oct*) m2=10 ;;
nov*|Nov*) m2=11 ;;
dec*|Dec*) m2=12 ;;
[1-9]|10|11|12) ;;
*)   y=$m2; m2="" ;;
esac

cal $m1 $y
cal $m2 $y