STRESS=$1
P1=$2
P2=$3
while [ 1 ]; do
    ./$STRESS > input
    ./$P1 < input > o1
    ./$P2 < input > o2
    diff o1 o2 > d
    if [ -s d ]; then
        break
    fi
done
