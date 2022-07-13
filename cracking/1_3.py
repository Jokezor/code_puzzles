def urlify(str1, str_length):
    return str1[0:str_length].replace(' ', '%20')

print(urlify("Mr John Smith    ", 13))
