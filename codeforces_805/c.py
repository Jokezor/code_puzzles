from sys import stdin
 
 
def solve():
    skip = input()
    # create an indices hashmap and compare the target to source
    n, k = list(map(int, stdin.readline().rstrip().split()))
 
    stations = list(map(int, stdin.readline().rstrip().split()))
    min_indices = {}
    max_indices = {}
    
    for ind, station in enumerate(stations):
        if station not in min_indices:
            min_indices[station] = ind
        max_indices[station] = ind
 
    for query in range(k):
        not_possible = False

        start, end = list(map(int, stdin.readline().rstrip().split()))
 
        if end not in max_indices or start not in min_indices:
            not_possible = True
        
        if not_possible:
            print("NO")
        else:
            end_index = max_indices[end]
            start_index = min_indices[start]
     
            if end_index <= start_index:
                print("NO")
            else:
                print("YES")
 
 
def main():
    t = int(input())
 
    for i in range(t):
        solve()
 
    return 0
 
 
main()
