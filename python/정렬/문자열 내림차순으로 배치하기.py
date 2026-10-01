#https://school.programmers.co.kr/learn/courses/30/lessons/12917
def solution(s):
    rs = sorted(s, reverse = True) # s = list(s) 한다음 해도 됨
    answer = "".join(rs)
    
    return answer

# 다른 답
#   return ''.join(sorted(s, reverse=True))