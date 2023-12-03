for i in `seq 1 10`; do
    # prints the current test number
    # I like to do this so I can see progress is being made
    echo $i 

    ./C_gen $i > input.txt
    ./C_mine < input.txt > output.txt
    ./C_bruteforce < input.txt > answer.txt

    diff output.txt answer.txt || break
done
