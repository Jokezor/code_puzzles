from sys import stdin


class Solution:

    def solve(self):
        self.forgotten_episode()

    @staticmethod
    def forgotten_episode():
        n = int(input())
        watched_episodes = set(map(int, stdin.readline().rstrip().split()))

        for i in range(1, n+1):
            if i not in watched_episodes:
                print(i)


Solution().solve()
