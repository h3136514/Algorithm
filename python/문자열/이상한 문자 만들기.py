#https://school.programmers.co.kr/learn/courses/30/lessons/12930

def solution(s):
    answer = ''
    cnt = 0
    for i in s:
        if i == ' ':
            cnt = 0
            answer += ' '
            continue
            
        if cnt % 2 == 0:
            answer += i.upper() #대문자
        else:
            answer += i.lower() #소문자
        cnt += 1
            
    return answer