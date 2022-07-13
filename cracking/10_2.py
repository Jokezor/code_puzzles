from collections import defaultdict


def group_anagrams(array):

    anagrams = defaultdict(list)

    for ind, s in enumerate(array):
        anagrams["".join(sorted(s))].append(s)

    index = 0
    for key, val in anagrams.items():
        for s in val:
            array[index] = s
            index += 1


    print(array)



anagram_array = ['anetj', 'tjena', 'ann', 'jeh', 'nna', 'nan', 'hej', 'jenat']
group_anagrams(anagram_array)

