# https://school.programmers.co.kr/learn/courses/30/lessons/118669?language=python3

import heapq
from collections import defaultdict

def solution(n, paths, gates, summits):
    answer = [n, 10000001]
    
    min_heapq = []  # 다익스트라 탐색을 위한 최소 힙 (우선순위 큐)
    
    gate = [False] * (n+1)
    summit = [False] * (n+1)
    dp = [-1 for _ in range(n+1)] # 해당 지점까지 도달하는 데 필요한 '최소 intensity'를 저장하는 배열 (-1은 미방문)
    
    # 모든 출입구를 다익스트라의 시작점으로 설정
    for i in gates:
        gate[i] = True
        # [현재까지의 intensity 최댓값, 현재 노드 번호]
        heapq.heappush(min_heapq, [0, i]) # 출발지의 intensity는 0
        dp[i] = 0
    
    # 산봉우리를 빠르게 확인하기 위해 boolean 배열에 체크
    for i in summits:
        summit[i] = True 
    
    # 양방향 그래프 구성
    graph = defaultdict(list)
    for u, v, i in paths:
        graph[u].append([v, i])
        graph[v].append([u, i])
    
    # 다익스트라 탐색 시작
    while min_heapq:
        currentIntensity, currentV = heapq.heappop(min_heapq)
        # 이미 찾은 최솟값보다 커지면 더 볼 필요 없음
        if answer[1] < currentIntensity:
            break
            
        # 이미 더 작은 intensity로 해당 노드에 방문한 적이 있다면 스킵
        if dp[currentV] != -1 and dp[currentV] < currentIntensity:
            continue
        
        if summit[currentV]:
            if currentIntensity < answer[1]:
                answer = [currentV, currentIntensity]
            elif currentIntensity == answer[1]:
                answer[0] = min(answer[0], currentV)
            continue
        
        # 인접한 노드들 탐색 (v: 다음 노드, i: 다음 노드로 가는 데 걸리는 시간)
        for v, i in graph[currentV]:
            # 출입구로는 다시 돌아갈 필요가 없으므로 스킵
            if gate[v]:
                continue
            
            # 경로 상의 최대 시간이 그 경로의 intensity가 됨
            ii = max(i, currentIntensity)
            
            # 다음 노드를 한 번도 방문하지 않았거나, 기존보다 더 작은 intensity로 도달할 수 있다면 갱신
            if dp[v] == -1 or dp[v] > ii:
                dp[v] = ii
                heapq.heappush(min_heapq, [ii, v])
    
    return answer