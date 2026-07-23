# https://school.programmers.co.kr/learn/courses/30/lessons/1844
from collections import deque


def solution(maps):
    answer = -1
    N = len(maps)   # y축 길이 (행)
    M = len(maps[0])    # x축 길이 (열)
    
    # 상하좌우 이동을 위한 좌표
    diretions = [(1, 0), (0, 1), (-1, 0), (0, -1)]
    
    visitied = [[False]*M for _ in range(N)] #[[False for _ in range(M)] for _ in range(n) ]
    q = deque()
    q.append([0, 0, 1])
    visitied[0][0] = True;
    
    while q:
        currentX, currentY, currentCnt = q.popleft()
        
        if currentX == M - 1 and currentY == N - 1:
            answer = currentCnt
            break
        
        for x, y in diretions:
            ix = currentX + x
            iy = currentY + y
            icurrentCNt = currentCnt+1
            if 0 <= ix < M and 0 <= iy < N and maps[iy][ix] == 1 and not visitied[iy][ix]:
                visitied[iy][ix] = True
                q.append([ix, iy, icurrentCNt])
    
    return answer