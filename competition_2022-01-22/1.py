class Solution:
    def minimumCost(self, cost: list[int]) -> int:
        # Always buy the two most expensive candies, then the third most expensive we can take for free.
        total_cost = 0

        cost.sort()

        while cost:
            if cost:
                total_cost += cost.pop()
            if cost:
                total_cost += cost.pop()

            # The third is free
            if cost:
                cost.pop()

        print(total_cost)
        return total_cost


cost1 = [1,2,3]
cost2 = [6,5,7,9,2,2]
cost3 = [5,5]

assert Solution().minimumCost(cost=cost1) == 5
assert Solution().minimumCost(cost=cost2) == 23
assert Solution().minimumCost(cost=cost3) == 10
