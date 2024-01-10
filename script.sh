for i in `seq 199990 200000`; do
    # prints the current test number
    # I like to do this so I can see progress is being made
    echo $i 

    ./ferris_gen $i $i > input.txt
    ./my_version < input.txt > output.txt
    ./sol < input.txt > answer.txt

    diff output.txt answer.txt || break
done
