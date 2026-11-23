from collections import deque

def get_moves(x, y):
    res = []
    for dx, dy in [(-2, -1), (-2, 1), (-1, -2), (-1, 2), (1, -2), (1, 2), (2, -1), (2, 1)]:
        nx, ny = x + dx, y + dy
        if 0 <= nx < 8 and 0 <= ny < 8:
            res.append((nx, ny))
    return res

h1, h2 = input().split()
x1, y1 = ord(h1[0]) - ord('a'), int(h1[1]) - 1
x2, y2 = ord(h2[0]) - ord('a'), int(h2[1]) - 1

q = deque([(x1, y1, x2, y2, 0)])
visited = {(x1, y1, x2, y2)}
ans = -1

while q:
    cx1, cy1, cx2, cy2, d = q.popleft()
    if cx1 == cx2 and cy1 == cy2:
        ans = d
        break
    for nx1, ny1 in get_moves(cx1, cy1):
        for nx2, ny2 in get_moves(cx2, cy2):
            if (nx1, ny1, nx2, ny2) not in visited:
                visited.add((nx1, ny1, nx2, ny2))
                q.append((nx1, ny1, nx2, ny2, d + 1))

print(ans)