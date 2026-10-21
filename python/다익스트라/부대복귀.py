# https://school.programmers.co.kr/learn/courses/30/lessons/132266

import heapq
from collections import defaultdict

INF = 987654321

def solution(n, roads, sources, destination):
    answer = []
    q = []
    graph = defaultdict(list)
    dp = [INF] *(n+1)
    
    for a, b in roads:
        graph[a].append(b)
        graph[b].append(a)
    
    # 시작점(도착점을 시작점으로, 양방향이므로 가능)
    dp[destination] = 0
    heapq.heappush(q, [0, destination])
    
    while q:
        currentCost, currentV = heapq.heappop(q)
        if dp[currentV] < currentCost:
            continue
        
        for v in graph[currentV]:
            icost = currentCost + 1
            if dp[v] > icost:
                dp[v] = icost
                heapq.heappush(q, [icost, v])
    
    # 부대원에 최단시간 대입
    for v in sources:
        if dp[v] == INF:
            answer.append(-1)
        else:
            answer.append(dp[v])
    
    return answer