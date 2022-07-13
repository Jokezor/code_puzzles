def one_away(first, second):
    found_diff = False
    ind_1 = 0
    ind_2 = 0

    s1 = first if len(first) < len(second) else second
    s2 = secon if len(first) < len(second) else first

    while ind_1 < len(s1) and ind_2 < len(s2):
        if s1[ind_1] != s2[ind_2]:
            if found_diff:
                return False
            found_diff = True

            if len(s1) == len(s2):
                ind_1 += 1
        else:
            ind_1 += 1
        ind_2 += 1
    return True



print(one_away("pale", "ple"))
