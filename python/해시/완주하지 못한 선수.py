#https://school.programmers.co.kr/learn/courses/30/lessons/42576
from collections import defaultdict

def solution(participant, completion):
    answer = ''
    player = defaultdict(int)
    
    for name in participant:
        player[name] += 1
        
    for name in completion:
        player[name] -= 1
        if player[name] == 0 :
            del player[name]
            
    for name, cnt in player.items():
        answer = name
        
    return answer