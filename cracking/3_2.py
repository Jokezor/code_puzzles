class Node:

    def __init__(self, val):
        self.val = val
        self.next = None


class MinStack:

    def __init__(self):
        self.head = Node(None)
        self.min_stack = Node(None)

    def push(self, val):
        new_node = Node(val)

        new_node.next = self.head
        self.head = new_node

        if self.min_stack.val:
            if val <= self.min_stack.val:
                new_min = Node(val)
                new_min.next = self.min_stack
                self.min_stack = new_min
        else:
            new_min = Node(val)
            new_min.next = self.min_stack
            self.min_stack = new_min

    def pop(self):
        val = self.head.val

        if self.head.val == self.min_stack.val:
            self.min_stack = self.min_stack.next

        if self.head.next:
            self.head = self.head.next

        return val

    def min(self):
        return self.min_stack.val

    def top(self):
        return self.head.val


test_stack = MinStack()
test_stack.push(1)
test_stack.push(3)
test_stack.pop()
test_stack.pop()
print(test_stack.min())
print(test_stack.top())
