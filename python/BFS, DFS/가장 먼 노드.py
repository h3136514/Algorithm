# https://school.programmers.co.kr/learn/courses/30/lessons/49189

from collections import defaultdict, deque

def solution(n, edge):
    answer = n-1
    maxDist = 0
    visitied = [False for _ in range(n+1)]
    q = deque()
    graph = defaultdict(list)
    
    for u, v in edge:
        graph[u].append(v)
        graph[v].append(u)
    
    q.append([0, 1])
    visitied[1] = 1;
    while q:
        dist, v = q.popleft()
        if dist > maxDist:
            maxDist = dist
            answer = 1
        elif dist == maxDist and v != 1:
            answer += 1
        
        for u in graph[v]:
            if visitied[u]:
                continue
            visitied[u] = True
            q.append([dist+1, u])
    
    return answer