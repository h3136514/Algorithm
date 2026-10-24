# (y1, x1)에서 시작하는 n x n 영역을 시계방향 90도 회전
for i in range(n):
    for j in range(n):
        copyA[y1 + j][x1 + n - i - 1] = A[y1 + i][x1 + j]
        
# 달팽이 회전
from collections import deque

offset_X = [-1, 0, 1, 0]   # 왼쪽, 아래, 오른쪽, 위 (반시계)
offset_Y = [0, 1, 0, -1]

def snail(startX, startY):
    id = 3
    num = 1
    cnt = 0
    checked = False
    q = deque()
    color = board[startY][startX - 1]



# 달팽이 회전
dx = [-1, 0, 1, 0]   # 좌, 하, 우, 상
dy = [0, 1, 0, -1]

def snail(n):                    # n은 홀수
    x = y = n // 2               # 중심에서 시작
    d, dist = 0, 1               # 방향, 이동 거리
    order = []                   # 달팽이 순서로 방문한 좌표

    while True:
        for _ in range(2):       # 같은 거리를 2번 이동
            for _ in range(dist):
                x += dx[d]
                y += dy[d]
                if not (0 <= x < n and 0 <= y < n):
                    return order # 범위를 벗어나면 끝
                order.append((x, y))   # 여기서 원하는 처리
            d = (d + 1) % 4      # 방향 전환
        dist += 1                # 방향 2번 바꿀 때마다 거리 +1