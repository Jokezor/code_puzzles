for i in `seq 1 100`; do
    # prints the current test number
    # I like to do this so I can see progress is being made
    echo $i 

    ./ferris_gen $i 4 5 > input.txt
    ./ferris < input.txt > output.txt
    ./ferris_naive < input.txt > answer.txt

    diff output.txt answer.txt || break
done
