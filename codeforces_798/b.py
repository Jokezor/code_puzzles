from sys import stdin
import heapq

t = int(input())


while t:
    n = int(input())

    permutation = list(map(int, stdin.readline().rstrip().split()))

    new_permutation = []
    heap = permutation[:]
    heapq.heapify(heap)

    for i in range(n):
        smallest = heapq.heappop(heap)
        if smallest == permutation[i]:
            try:
                next_smallest = heapq.heappop(heap)
                # Add it back in.
                heapq.heappush(heap, smallest)
                smallest = next_smallest
            except IndexError:
                # Then we should add in the smallest
                pass
            new_permutation.append(smallest)
        else:
            new_permutation.append(smallest)

    if n == 1:
        print(-1)
    else:
        if new_permutation[-1] == permutation[-1]:
            temp = new_permutation[-1]
            new_permutation[-1] = new_permutation[-2]
            new_permutation[-2] = temp

        print(" ".join([str(x) for x in new_permutation]))

    t -= 1


print("Hej thera")

