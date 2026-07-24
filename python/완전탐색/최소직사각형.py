#https://school.programmers.co.kr/learn/courses/30/lessons/86491?language=python3

def solution(sizes):
    smallMax = 0
    bigMax = 0
    answer = 0
    for x in sizes:
        x.sort()
        smallMax = max(smallMax, x[0])
        bigMax = max(bigMax, x[1])
        
    answer = smallMax * bigMax
    
    return answer