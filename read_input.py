# Testing to make a custom import function to make it faster to get inputs to test my solution

class Solution:
    def read_input(self, formats):
        text_file = f'{__file__.split(".py")[0]}_input.txt'
        self.input = open(text_file)

        input = []
        for format in formats:
            new_line = format(self.input.readline().strip())
            print(new_line)
            if format == list[list[int]]:
                print([i.strip("[]").split(", ") for i in new_line])
            input.append(new_line)
        print(input)
        return input


Solution().read_input(formats=[int, list[list[int]], int, int])
