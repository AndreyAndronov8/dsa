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

    def order_up_not_leaves(self):
        return self._order_up_not_leaves(self.root)

    def _order_up_not_leaves(self, node):
        if node is None:
            return []
        if node.right is None or node.left is None:
            return self._order_up_not_leaves(node.left) + self._order_up_not_leaves(node.right)
        return self._order_up_not_leaves(node.left) + [node.data] + self._order_up_not_leaves(node.right)

input_data = input().split()
bst = BinarySearchTree()

for num_str in input_data[:-1]:
    bst.insert(int(num_str))

leaves = bst.order_up_not_leaves()
for x in leaves:
    print(x)
