import sys

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

    def order_up(self):
        return self._order_up(self.root)

    def _order_up(self, node):
        if node is None:
            return []
        return self._order_up(node.left) + [node.data] + self._order_up(node.right)

input_data = sys.stdin.read().split()
bst = BinarySearchTree()

for num_str in input_data:
    num = int(num_str)
    if num == 0:
        break
    bst.insert(num)

elements = bst.order_up()
for i in elements:
    print(i)