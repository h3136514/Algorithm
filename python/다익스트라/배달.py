# https://school.programmers.co.kr/learn/courses/30/lessons/12978?language=python3

import heapq
from collections import defaultdict

def solution(N, road, K):
    answer = 0
    dp = [500001]*(N+1)
    graph = defaultdict(list)
    
    for a, b, c in road:
        graph[a].append([b, c])
        graph[b].append([a, c])
    
    min_q = []
    heapq.heappush(min_q, [0, 1])
    dp[1] = 0
    
    while min_q:
        currentCost, currentV = heapq.heappop(min_q)
        if currentCost > K:
            break
        
        for u, cost in graph[currentV]:
            icost = currentCost + cost
            if dp[u] > icost:
                dp[u] = icost
                heapq.heappush(min_q, [icost, u])
    
    for i in range(1, N+1):
        if dp[i] <= K:
            answer += 1
    return answer