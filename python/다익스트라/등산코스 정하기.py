#https://school.programmers.co.kr/learn/courses/30/lessons/118669?language=python3
import heapq
from collections import defaultdict

def solution(n, paths, gates, summits):
    answer = [-1, -1]
    
    # 다익스트라 탐색을 위한 최소 힙 (우선순위 큐)
    min_heapq = []
    
    # 지점 번호가 1부터 n까지이므로 크기를 n+1로 설정 (인덱스 에러 방지)
    gate = [False for _ in range(n+1)]
    summit = [False for _ in range(n+1)]
    
    # 해당 지점까지 도달하는 데 필요한 '최소 intensity'를 저장하는 배열 (-1은 미방문)
    dp = [-1 for _ in range(n+1)]
    
    # 1. 모든 출입구를 다익스트라의 시작점으로 설정
    for i in gates:
        gate[i] = True
        # [현재까지의 intensity 최댓값, 현재 노드 번호]
        heapq.heappush(min_heapq, [0, i])
        dp[i] = 0 # 출발지의 intensity는 0
    
    # 2. 산봉우리를 빠르게 확인하기 위해 boolean 배열에 체크
    for i in summits:
        summit[i] = True
        
    # 3. 양방향 그래프 구성
    graph = defaultdict(list)
    for u, v, i in paths: # 여기서 i는 이동 시간(가중치)
        graph[u].append([v, i])
        graph[v].append([u, i])
        
    # 4. 다익스트라 탐색 시작
    while min_heapq:
        currentIntensity, currentV = heapq.heappop(min_heapq)
        
        # [핵심 로직 1] 산봉우리에 도착한 경우
        # 힙(Heap) 특성상 intensity가 가장 작은 것부터 팝업되고, 
        # intensity가 같다면 노드 번호가 작은 것부터 팝업됨.
        # 따라서 제일 처음 만난 산봉우리가 무조건 정답이므로 탐색 종료!
        if summit[currentV]:
            answer[0] = currentV
            answer[1] = currentIntensity
            break
        
        # 이미 더 작은 intensity로 해당 노드에 방문한 적이 있다면 스킵
        if dp[currentV] != -1 and dp[currentV] < currentIntensity:
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