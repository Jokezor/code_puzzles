
def solution():
    a,b,c = map(int, input().split(" "))

    # Need same parity.
    #if ((a & 1) != (b&1)):
    #    return -1

    # guesstimate n by and b instead, then do the test on the d candidate.
    n = (max(a,b) - min(a,b))*2

    d = max(1, (c + n//2)%(n+1));

    if max(c, d) != (min(c, d) + n/2):
        return -1

    return d

def main():
    t = int(input())
    for _ in range(0,t):
        print(solution())

if __name__ == '__main__':
    main()
