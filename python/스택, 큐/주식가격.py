# https://school.programmers.co.kr/learn/courses/30/lessons/42584?language=python3

from collections import deque

def solution(prices):
    n = len(prices)
    answer = [0 for _ in range(n)]
    q = deque()
    
    for idx, price in enumerate(prices):
        while True:
            if len(q) == 0 or q[-1][0] <= price:
                break
            p, i = q.pop()
            answer[i] = idx -i
            
        q.append((price, idx))
        
    while q:
        p, i = q.popleft()
        answer[i] = n-1-i
            
    return answer