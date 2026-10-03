# https://school.programmers.co.kr/learn/courses/30/lessons/12941?language=python3

def solution(A,B):
    answer = 0
    A.sort()
    B.sort(reverse = True)
    
    for idx, num in enumerate(A):
        answer += A[idx]*B[idx]
    
    return answer