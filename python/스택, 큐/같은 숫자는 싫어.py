#https://school.programmers.co.kr/learn/courses/30/lessons/12906?language=python3
from collections import deque

def solution(arr):
    answer = []
    q = deque()
    for i in arr:
        qSize = len(q)
        if qSize == 0 or q[qSize-1] != i:
            q.append(i)
    while q:
       answer.append(q.popleft())
    
    return answer