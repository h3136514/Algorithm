# https://school.programmers.co.kr/learn/courses/30/lessons/42578
from collections import defaultdict 

def solution(clothes):
    answer = 1
    hash_map = defaultdict(int)
    
    for clothe in clothes:
        hash_map[clothe[1]] += 1
    
    for k, v in hash_map.items():
        answer *= (v+1)
    
    answer -= 1    # 아무것도 안입는 경우 제외
        
    return answer