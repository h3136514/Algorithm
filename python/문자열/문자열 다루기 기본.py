# https://school.programmers.co.kr/learn/courses/30/lessons/12918?language=python3

def solution(s):
    answer = True
    n = len(s)
    if n != 4 and n != 6:
        return False
    
    for i in s:
        if not i.isdigit():
            answer = False
            break
    
    return answer