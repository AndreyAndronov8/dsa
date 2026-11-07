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

    def _get_height(self, node):
        if node is None:
            return 0
        return 1 + max(self._get_height(node.left), self._get_height(node.right))

    def is_balanced(self):
        return self._is_balanced(self.root)

    def _is_balanced(self, node):
        if node is None:
            return True
        left_height = self._get_height(node.left)
        right_height = self._get_height(node.right)
        if abs(left_height - right_height) > 1:
            return False
        return self._is_balanced(node.left) and self._is_balanced(node.right)

input_data = input().split()
bst = BinarySearchTree()

for num_str in input_data[:-1]:
    bst.insert(int(num_str))

if bst.is_balanced():
    print("YES")
else:
    print("NO")
