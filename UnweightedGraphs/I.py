from collections import deque

n = int(input())
x1, y1 = map(int, input().split())
x2, y2 = map(int, input().split())

moves = [(-2, -1), (-2, 1), (-1, -2), (-1, 2), (1, -2), (1, 2), (2, -1), (2, 1)]

queue = deque([(x1, y1)])
parent = {(x1, y1): None}

while queue:
    x, y = queue.popleft()
    if (x, y) == (x2, y2):
        break
    for dx, dy in moves:
        nx, ny = x + dx, y + dy
        if 1 <= nx <= n and 1 <= ny <= n and (nx, ny) not in parent:
            parent[(nx, ny)] = (x, y)
            queue.append((nx, ny))

path = []
curr = (x2, y2)
while curr is not None:
    path.append(curr)
    curr = parent[curr]
path.reverse()

print(len(path) - 1)
for px, py in path:
    print(px, py)
