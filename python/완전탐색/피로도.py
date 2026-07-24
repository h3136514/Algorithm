# https://school.programmers.co.kr/learn/courses/30/lessons/87946?language=python3
from itertools import permutations

def solution(k, dungeons):
    answer = 0
    
    #던전을 방문할 수 있는 모든 순서(경우의 수)를 구합니다.
    # 예: (A, B, C), (A, C, B), (B, A, C) ...
    for p in permutations(dungeons):
        cnt = 0
        currentH = k
        
        for a, b in p:
            #해당 순서대로 던전을 하나씩 방문
            if currentH >= a:
                currentH -= b
                cnt += 1
            else:    # 피로도가 부족하면 이 순서는 여기서 끝
                break
                
        answer = max(answer, cnt)
    return answer

# 백트래킹 방법
answer = 0
N = 0
visited = []


def dfs(k, cnt, dungeons):
    global answer
    if cnt > answer:
        answer = cnt

    for j in range(N):
        if k >= dungeons[j][0] and not visited[j]:
            visited[j] = 1
            dfs(k - dungeons[j][1], cnt + 1, dungeons)
            visited[j] = 0


def solution(k, dungeons):
    global N, visited
    N = len(dungeons)
    visited = [0] * N
    dfs(k, 0, dungeons)
    return answer