#https://school.programmers.co.kr/learn/courses/30/lessons/43163
from collections import deque

def solution(begin, target, words):
    answer = 0
    n = len(words)
    visitied = [51 for _ in range(n)]
    q = deque()
    q.append([begin, 0])
    
    while q:
        currentWord, currentCnt = q.popleft()
        
        if currentWord == target:
            answer = currentCnt
            break;
        
        for j in range(n):
            cnt = 0
            for i in range(len(currentWord)):
                if words[j][i] != currentWord[i]:
                    cnt += 1
            if cnt == 1 and currentCnt + 1 < visitied[j]:
                visitied[j] = currentCnt + 1
                q.append([words[j], currentCnt + 1])
                
    
    return answer