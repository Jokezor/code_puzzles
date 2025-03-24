
def solution():
    a,b,c = map(int, input().split(" "))

    # guesstimate n by and b instead, then do the test on the d candidate.
    n = (max(a,b) - min(a,b))*2

    if n < max(a, b, c):
        return -1

    d = (c + n//2);

    if d > n:
        d %= n
        d = max(1, d)

    if max(c, d) != (min(c, d) + n/2) or d in {a, b, c}:
        return -1

    return d

def main():
    t = int(input())
    for _ in range(0,t):
        print(solution())

if __name__ == '__main__':
    main()
