# https://school.programmers.co.kr/learn/courses/30/lessons/92343?language=python3
from collections import defaultdict

graph = defaultdict(list)
infos = []
answer = 1

# DFS 함수: 현재 노드, 양의 수, 늑대의 수, 앞으로 갈 수 있는 노드 목록
def dfs(currenNode, sheep, wolf, nextNodes):
    global answer
    if infos[currenNode] == 0:
        sheep += 1
    else:
        wolf += 1
        
    if sheep > wolf:
        answer = max(answer, sheep)
    else: # 늑대가 양보다 많거나 같아지면 잡아먹히므로 탐색 종료 (백트래킹)
        return
    
    # 다음 탐색을 위한 '후보 노드 리스트' 업데이트
    # 현재까지 가지고 있던 후보들 중에서 '나(current_node)'는 방문했으니 빼고,
    # '나의 자식 노드들'을 새로운 후보로 추가해 줍니다.
    tmpNodes = []
    for v in nextNodes:
        if v != currenNode:
            tmpNodes.append(v)
        
    for child in graph[currenNode]:
        tmpNodes.append(child)
    
    # 업데이트된 후보 노드들 중 하나를 골라 다시 DFS 탐색
    for v in tmpNodes:
        dfs(v, sheep, wolf, tmpNodes)


def solution(info, edges):
    global infos, graph
    infos = info
    n = len(edges)
    
    # 트리 구성 (단방향)
    for i in range(n):
        u = edges[i][0]
        v = edges[i][1]
        graph[u].append(v)
    
    dfs(0, 0, 0, [0])
    
    return answer