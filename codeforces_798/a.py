from sys import stdin

t = int(input())

for i in range(t):
    n, m, k = list(map(int, stdin.readline().rstrip().split()))

    a = list(stdin.readline().rstrip())
    b = list(stdin.readline().rstrip())

    a.sort(reverse=True
    b.sort(reverse=True)
    c = []
    m -= 1
    n -= 1
    a_k = k
    b_k = k

    while m != -1 and n != -1:
        if a[n] <= b[m]:
            if a_k > 0:
                c.append(a[n])
                n -= 1
                a_k -= 1
                b_k = k
            else:
                c.append(b[m])
                m -= 1
                b_k -= 1
                a_k = k
        else:
            if b_k > 0:
                c.append(b[m])
                m -= 1
                b_k -= 1
                a_k = k
            else:
                c.append(a[n])
                n -= 1
                a_k -= 1
                b_k = k

    print("".join(c))
