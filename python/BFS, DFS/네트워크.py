# https://school.programmers.co.kr/learn/courses/30/lessons/43162
from collections import deque

def solution(n, computers):
    answer = 0
    visitied = [False for _ in range(n)]
    q = deque()
    
    for i in range(n):
        if not visitied[i]:
            q.append(i)
            visitied[i] = True
            answer += 1
            
            while q:
                v = q.popleft()
                for j in range(n):
                    if v == j or computers[v][j] == 0 or visitied[j]:
                        continue
                    else:
                        visitied[j] = True
                        q.append(j)
    
    return answer