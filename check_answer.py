with open("output_test_real.txt", "r") as f:
    real_output = f.read()

with open("output_test.txt", "r") as f:
    my_output = f.read()


with open("input_test.txt", "r") as f:
    test_cases = f.read().splitlines()


my_answer = [int(c) for c in my_output.splitlines()]
real_answer = [int(c) for c in real_output.splitlines()]


for i in range(len(my_answer)):
    diff = my_answer[i] - real_answer[i]
    if diff != 0:
        print(
            f"Wrong answer on test_case {i}, {test_cases[i]}: {my_answer[i]}, real answer: {real_answer[i]}"
        )
