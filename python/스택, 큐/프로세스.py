# https://school.programmers.co.kr/learn/courses/30/lessons/42587?language=python3
from collections import deque

def solution(priorities, location):
    answer = 0
    cnt = 0
    q = deque()
    for idx, num in enumerate(priorities):
        q.append([idx, num])
        
    priorities.sort(reverse = True)
    while q:
        idx, num = q.popleft()
        if priorities[cnt] == num:
            if idx == location:
                answer = cnt+1
                break;
            cnt += 1
        else:
            q.append([idx, num])
    
    
    return answer