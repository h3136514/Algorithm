#https://school.programmers.co.kr/learn/courses/30/lessons/12909?language=python3

from collections import deque

def solution(s):
    answer = True
    stack = deque()
    for a in s:
        n = len(stack)
        
        if n != 0 and a == ')' and stack[n-1] == '(':
            stack.pop()
        elif a =='(':
            stack.append(a)
        else:
            answer = False
            break
        
    if len(stack) != 0:
        answer = False
            
   

    return answer