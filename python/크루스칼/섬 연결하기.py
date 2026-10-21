# https://school.programmers.co.kr/learn/courses/30/lessons/42861?language=python3

import heapq
parent = []

def find(a):
    if parent[a] == a:
        return a
    parent[a] = find(parent[a])
    return parent[a]

def unionSet(a, b):
    rootA = find(a)
    rootB = find(b)
    
    if rootA != rootB:
        parent[rootB] = rootA

def solution(n, costs):
    global parent
    answer = 0
    cnt = 0 # 간선 수
    q = []
    
    for i in range(n):  # 초기 자기자신을 가리킴
        parent.append(i);
    
    for a, b, c in costs:
        heapq.heappush(q, [c, a, b])
    
    while q:
        currentCost, currentA, currentB = heapq.heappop(q)
        if cnt == n-1: # 모든 섬이 연결됨
            break
            
        if find(currentA) != find(currentB):
            answer += currentCost
            unionSet(currentA, currentB)
            cnt += 1
    
    return answer