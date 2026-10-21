# https://school.programmers.co.kr/learn/courses/30/lessons/42884?language=python3

import heapq

def solution(routes):
    answer = 0
    startR = -30001
    endR = -30001
    q = []
    for s, e in routes:
        heapq.heappush(q, [s, e])
        
    while q:
        currentS, currentE = heapq.heappop(q)
        
        if startR <= currentS and currentE <= endR:  # 카메라가 범위안에 있을 때(끝범위 갱신)
            endR = currentE
        elif endR < currentS: # 카메라 범위를 벗어나면(전체 범위 갱신)
            answer += 1
            startR = currentS
            endR = currentE
        else: # 카메라가 겹치는 부위가 있을 때(시작범위 갱신)
            startR = currentS
    
    return answer


# 다른 풀이(끝점을 기준으로 정렬)
def solution(routes):
    routes.sort(key=lambda x: x[1])
    answer = 0
    camera = -30001
    for s, e in routes:
        if s > camera:
            answer += 1
            camera = e
    return answer
