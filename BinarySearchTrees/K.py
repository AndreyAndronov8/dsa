class Node:
    def __init__(self, key):
        self.data = key
        self.left = None
        self.right = None

class BinarySearchTree:
    def __init__(self):
        self.root = None

    def insert(self, key):
        if self.root is None:
            self.root = Node(key)
        else:
            curr_node = self.root
            while True:
                if key < curr_node.data:
                    if curr_node.left is None:
                        curr_node.left = Node(key)
                        break
                    curr_node = curr_node.left
                elif key > curr_node.data:
                    if curr_node.right is None:
                        curr_node.right = Node(key)
                        break
                    curr_node = curr_node.right
                else:
                    break

    def next_element(self, key):
        curr_node = self.root
        ans = -1
        while curr_node is not None:
            if curr_node.data >= key:
                ans = curr_node.data
                curr_node = curr_node.left
            else:
                curr_node = curr_node.right
        return ans

n = int(input())
bst = BinarySearchTree()

last_next = False
y = 0

for _ in range(n):
    op, i = input().split()
    i = int(i)
    
    if op == '+':
        if last_next:
            i = (i + y) % 10**9
        bst.insert(i)
        last_next = False
    elif op == '?':
        y = bst.next_element(i)
        print(y)
        last_next = True