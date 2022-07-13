from functools import reduce
import collections

class Solution:
    def minimumLengthEncoding(self, words: list[str]) -> int:
        # This is equivalent to knowing the most overlapping substring. 
        Trie = lambda: collections.defaultdict(Trie)
        trie = Trie()
        result = 0

        nodes = []
        
        for i, word in enumerate(words):
            current_trie = trie
            print(word, current_trie[i])
            for c in word[::-1]:
                current_trie = current_trie[c]
            nodes.append(current_trie)
        
        for i, word in enumerate(words):
            print(nodes[i])
            if len(nodes[i]) == 0:
                result += len(word) + 1

        return result

print(Solution().minimumLengthEncoding(["me", "time", "bell"]))
