def binary_search(A, left, right):

    if right < left:
        return -1

    middle = left + (right - left) // 2

    if A[middle] == middle:
        print(middle)
        return middle

    # Search the right part of the array
    if A[middle] < middle:
        right_index = max(middle+1, A[middle])
        return binary_search(A, right_index, right)

    if A[middle] > middle:
        left_index = min(middle-1, A[middle])
        return binary_search(A, left, left_index)


def magic_index(A):
    return binary_search(A, 0, len(A) - 1)


list_1 = [1, 1, 3]
list_2 = [1, 0, 2]
assert magic_index(list_1) == 1
assert magic_index(list_2) == 2

