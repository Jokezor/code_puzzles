def is_string_rotation(s1, s2):
    return s1 in f"{s2}{s2}"


print(is_string_rotation("waterbottle", "erbottlewate"))
