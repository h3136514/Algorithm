# https://school.programmers.co.kr/learn/courses/30/lessons/136798
def solution(number, limit, power):
    answer = 0
    num = [0] * (number + 1)
    
    for i in range(1, number + 1):
        for j in range(i, number + 1, i):
            num[j] += 1
            
            
    for i in range(1, number + 1):
        if num[i] > limit:
            answer += power
        else:
            answer += num[i]
            
    return answer