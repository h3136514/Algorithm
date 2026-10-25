# https://school.programmers.co.kr/learn/courses/30/lessons/181842

def solution(str1, str2):
    answer = 0
    s1 = len(str1)
    s2 = len(str2)
    
    for i in range(s2-s1+1):
        if str1 == str2[i:i+s1]:
            answer = 1
            break
            
    return answer