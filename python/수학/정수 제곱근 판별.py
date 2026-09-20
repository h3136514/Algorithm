#https://school.programmers.co.kr/learn/courses/30/lessons/12934?language=python3

from math import sqrt

def solution(n):
    
    if sqrt(n) % 1:     #소수점 아래 자리만 남게 됨(소수점이 있음 = 완전제곱수가 아님)
        answer = -1
    else:
        answer = (sqrt(n)+1)**2
        
    return answer