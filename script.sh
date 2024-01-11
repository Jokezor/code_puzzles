for i in `seq 1 10`; do
    # prints the current test number
    # I like to do this so I can see progress is being made
    echo $i 

    ./ferris_gen $i $i > input.txt
    ./segment_tree < input.txt > output.txt
    ./set < input.txt > answer.txt

    diff output.txt answer.txt || break
done
