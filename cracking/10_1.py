def merge(a, b, last_a, last_b):
    index_a = last_a
    index_b = last_b
    index_merged = last_b + last_a + 1

    while index_b >= 0:
        if index_a >= 0 and a[index_a] > b[index_b]:
            a[index_merged] = a[index_a]
            index_a -= 1
        else:
            a[index_merged] = b[index_b]
            index_b -= 1
        index_merged -= 1


A = [1,2,3,0,0,0]
B = [1,2,3]
merge(A, B, 2, 2)
print(A)

