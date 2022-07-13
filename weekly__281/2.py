# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
        value = 0
        current = head
        iterating_head = head

        while current.next:
            current = current.next
            value += current.val

            if current.val == 0:
                iterating_head.val = value
                iterating_head = iterating_head.next
                value = 0

        iterating_head.next = None
        return head


assert Solution().mergeNodes([0,3,1,0,4,5,2,0]) == [4, 11]