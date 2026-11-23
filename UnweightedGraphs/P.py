from collections import deque

n, m = map(int, input().split())
labirint = []
for i in range(n):
    labirint.append(list(map(int, input().split())))

directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]

queue = deque([(0, 0, 0)])

labirint[0][0] = -1

ans = -1

while queue:
    row, col, dist = queue.popleft()
    
    if row == n - 1 and col == m - 1:
        ans = dist
        break
        
    for dr, dc in directions:
        nrow, ncol = row + dr, col + dc
        if 0 <= nrow < n and 0 <= ncol < m and labirint[nrow][ncol] == 0:
            labirint[nrow][ncol] = -1
            queue.append((nrow, ncol, dist + 1))

print(ans)