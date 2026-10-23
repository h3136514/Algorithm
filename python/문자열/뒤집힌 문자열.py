# https://school.programmers.co.kr/learn/courses/30/lessons/120822?language=python3

def solution(my_string):
    answer = my_string[::-1]
    return answer

# 다른 풀이 (리스트 변환후)
def solution(my_string):
    my_list = list(my_string)
    my_list.reverse()

    answer = ''.join(my_list)
    return answer