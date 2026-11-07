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

    def order_down(self):
        return self._order_down(self.root)

    def _order_down(self, node):
        if node is None:
            return []
        return self._order_down(node.right) + [node.data] + self._order_down(node.left)

input_data = input().split()
bst = BinarySearchTree()

for num_str in input_data[:-1]:
    bst.insert(int(num_str))

elements = bst.order_down()
print(elements[1])