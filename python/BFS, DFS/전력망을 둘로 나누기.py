# https://school.programmers.co.kr/learn/courses/30/lessons/86971?language=python3

from collections import defaultdict, deque

def solution(n, wires):
    answer = n
    visitied = [False] * (n+1)
    q = deque()
    graph = defaultdict(list)
    
    for idx, value in enumerate(wires):
        u = value[0]
        v = value[1]
        graph[u].append([idx, v])
        graph[v].append([idx, u])
    
    for i in range(len(wires)):
        cnt = 1
        visitied[1] = True
        q.append(1)
        while q:
            currentV = q.popleft()
            
            for idx, iv in graph[currentV]:
                if idx == i or visitied[iv]:    # 잘린 전선 or 방문 송전탑
                    continue
                visitied[iv] = True
                cnt += 1
                q.append(iv)
        
        # 두 전력망의 개수의 차이 최솟값 확인
        answer = min(answer, abs(n-cnt*2))
        # 방문 초기화
        for j in range(1, n+1):
            visitied[j] = False
    
    return answer