# https://school.programmers.co.kr/learn/courses/30/lessons/72413?language=python3

import heapq
from collections import defaultdict

answer = 0
N = 0
dp = []
graph = defaultdict(list)
INF = 987654321

def init():
    global dp
    dp = [INF]*(N+1)

def dijsktra(start):
    global dp
    dp[start] = 0
    min_heap = []
    heapq.heappush(min_heap, [0, start])
    
    while min_heap:
        currentCost, currentV = heapq.heappop(min_heap)
        
        if dp[currentV] < currentCost:
            continue
        
        for iv, f in graph[currentV]:
            idist = f + currentCost
            if dp[iv] > idist:
                dp[iv] = idist
                heapq.heappush(min_heap, [idist, iv])

def solution(n, s, a, b, fares):
    global N, answer, graph
    N = n
    sum = [0]*(n+1)
    for c, d, f in fares:
        graph[c].append([d, f])
        graph[d].append([c, f])
    
    init()
    dijsktra(s)
    for i in range(N+1):
        sum[i] = dp[i]
    answer = sum[a] + sum[b]
    
    for i in range(N+1):
        if i == s:
            continue
            
        init()
        dijsktra(i)
        answer = min(answer, sum[i] + dp[a] + dp[b])
    
    return answer