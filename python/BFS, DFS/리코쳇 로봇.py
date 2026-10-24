# https://school.programmers.co.kr/learn/courses/30/lessons/169199

from collections import deque

N, M = 0, 0
def check(x, y):
    return 0 <= x < M and 0 <= y < N

def solution(board):
    global N, M
    
    answer = -1
    N = len(board)
    M = len(board[0])
    visitied =[[False]*(M+1) for _ in range(N+1)]
    dir = [(1,0), (-1, 0), (0, 1), (0, -1)]
    RX, RY = 0, 0
    q = deque()
    
    #로봇위치 좌표 찾기
    for i in range(N):
        for j in range(M):
            if board[i][j] == "R":
                RX, RY = j, i
                break    
    
    q.append([RX, RY, 0])
    visitied[RY][RX] = True
    while q:
        currentX, currentY, currentCnt = q.popleft()
        if board[currentY][currentX] == "G":
            answer = currentCnt
            break
        
        for i in range(4):
            ix, iy = currentX, currentY
            while True:
                tmpx, tmpy = ix + dir[i][0], iy + dir[i][1]
                if check(tmpx, tmpy) and board[tmpy][tmpx] != "D":
                    ix, iy = tmpx, tmpy
                else:
                    break
                    
            if not visitied[iy][ix]:
                visitied[iy][ix] = True
                q.append([ix, iy, currentCnt + 1])
    
    
    return answer