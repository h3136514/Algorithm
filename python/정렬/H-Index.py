# https://school.programmers.co.kr/learn/courses/30/lessons/42747?language=python3

def solution(citations):
    answer = len(citations)
    citations.sort()
    
    for i in citations:
        if i >= answer:
            break
        answer -= 1
        
    return answer