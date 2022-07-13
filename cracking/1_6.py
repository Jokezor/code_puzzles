def string_compression(string):
    string_list = []
    count = 1

    for ind in range(1, len(string)):
        if string[ind] != string[ind-1]:
            string_list.append(f'{string[ind-1]}{count}')
            count = 0
        count += 1

        if ind == len(string) - 1:
            string_list.append(f'{string[ind]}{count}')

    compressed_string = "".join(string_list)

    return compressed_string if len(compressed_string) < len(string) else string


print(string_compression("aabcccccaaa"))

