# https://school.programmers.co.kr/learn/courses/30/lessons/42839?language=python3

import math
num = [False]*10000000
visitied = [False] * 9
answer = 0
target = ""

# 에라토스테네스의 체 (소수 판별)
def isPrime(N):
    num[0] = True
    num[1] = True
    for i in range(2, int(math.sqrt(N+1))):
        if num[i]:
            continue
        for j in range(i+i, N+1, i):
            if num[j]:
                continue
            num[j] = True

# 백트래킹 (자리수별 숫자 조합)            
def dfs(s, cnt):
    global answer
    if cnt == len(s):
        num_int = int(s)
        if not num[num_int]:
            answer += 1
            num[num_int] = True
        return
    
    for i in range(len(target)):
        if visitied[i]:
            continue
        
        visitied[i] = True
        dfs(s+target[i], cnt)
        visitied[i] = False
        

def solution(numbers):
    global target
    isPrime(9999999)
    
    target = numbers
    
    for i in range(1, len(target)+1):
        dfs("", i)
    
    
    return answer