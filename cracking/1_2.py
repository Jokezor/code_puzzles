def check_permutation(str1, str2):
    if len(str1) != len(str2):
        return False

    str1_set = set()
    str2_set = set()

    for c in str1:
        str1_set.add(c)

    for c in str2:
        str2_set.add(c)

    return str1_set == str2_set
    

def check_permutation_sorting(str1, str2):
    if len(str1) != len(str2):
        return False

    str1_sorted = sorted(str1)
    str2_sorted = sorted(str2)

    return str1_sorted == str2_sorted
    

print(check_permutation("jeh", "hej"))
print(check_permutation_sorting("hej", "jeh"))
