# https://school.programmers.co.kr/learn/courses/30/lessons/67259?language=python3

import heapq

INF = 987654321

def solution(board):
    answer = INF
    direction =[(1, 0), (0, 1), (-1, 0), (0, -1)]
    n = len(board)
    # dp[y][x][d] : (x, y)에 d 방향으로 도착했을 때의 최소 비용
    dp = [[[INF]*4 for _ in range(n)] for _ in range(n)]
    min_heap = []
    
    # 시작점은 방향이 없으므로 4방향 모두 비용 0으로 시작 (코너 비용 방지)
    for d in range(4): 
        dp[0][0][d] = 0
        heapq.heappush(min_heap, [0, 0, 0, d])
    
    while min_heap:
        currentCost, currentX, currentY, currentDir =  heapq.heappop(min_heap)
        
        if dp[currentY][currentX][currentDir] < currentCost:
            continue
            
        for i in range(4):
            ix = currentX + direction[i][0]
            iy = currentY + direction[i][1]
            icost = currentCost + 100
            
            if not(0 <= ix < n and 0 <= iy < n) or board[iy][ix] == 1:
                continue
                
            if currentDir % 2 != i % 2: # 직각으로 꺾이면 코너 비용
                icost += 500
            
            if dp[iy][ix][i] > icost:
                dp[iy][ix][i] = icost
                heapq.heappush(min_heap, [icost, ix, iy, i])
                
    for i in range(4):
        answer = min(answer, dp[n-1][n-1][i])
        
    return answer