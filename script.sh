for i in `seq 2 1000`; do
    # prints the current test number
    # I like to do this so I can see progress is being made
    echo $i 

    ./gen $i $i > input.txt
    ./my_sol < input.txt > output.txt
    ./sol < input.txt > answer.txt

    diff output.txt answer.txt || break
done
