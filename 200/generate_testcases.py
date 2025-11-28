import random


"""
Should output something like:
N
A1 A2 ... AN
"""
def generate_test_cases(t):
    file_name = "tests.txt"

    n_high = 1e5

    with open(file_name, "w+") as f:
        f.write(f"{t}\n")
        for _ in range(t):
            n = random.randint(1, n_high)


            f.write(f"{n}\n")

            # Now to add a.
            for i in range(n):
                f.write(f"{random.randint(1, 1000000000)} ")
            f.write("\n")


        

if __name__ == '__main__':
    generate_test_cases(100)
