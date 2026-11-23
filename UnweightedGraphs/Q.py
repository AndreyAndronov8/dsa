from collections import deque

n, m = map(int, input().split())
labirint = []
for i in range(n):
    labirint.append(list(map(int, input().split())))

directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]

queue = deque([(0, 0, 0)])

visited = {(0, 0)}

flag = False

while queue:
    row, col, dist = queue.popleft()
        
    for dr, dc in directions:
        nrow, ncol = row, col
        
        while 0 <= nrow + dr < n and 0 <= ncol + dc < m and labirint[nrow + dr][ncol + dc] != 1:
            nrow, ncol = nrow + dr, ncol + dc

            if labirint[nrow][ncol] == 2:
                print(dist + 1)
                flag = True
                break
                
        if (nrow, ncol) not in visited:
            visited.add((nrow, ncol))
            queue.append((nrow, ncol, dist + 1))
            
        if flag:
            break
    
    if flag:
        break