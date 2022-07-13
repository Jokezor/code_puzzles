file = open("13_input.txt", 'r')
numbers = [int(line.strip()) for line in file.readlines()]

print(str(sum(numbers))[0:10])