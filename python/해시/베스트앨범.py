# https://school.programmers.co.kr/learn/courses/30/lessons/42579?language=python3

import heapq
from collections import defaultdict

def solution(genres, plays):
    answer = []
    n = len(genres)
    map_genre = defaultdict(int)
    map_play = defaultdict(list)
    
    for i in range(n):
        map_genre[genres[i]] += plays[i]
        map_play[genres[i]].append([plays[i], -i])
    
    q = []
    for name, cnt in map_genre.items():
        heapq.heappush(q,[-cnt, name]) # 속한 노래가 많이 재생된 장르를 먼저 수록하기 위해
    
    # 장르별 최대 2개 수록(기준에 따라)
    while q:
        total, name = heapq.heappop(q)
        map_play[name].sort(reverse = True)
        
        cnt = 0
        for play, idx in map_play[name]:
            if cnt == 2:
                break
            answer.append(-idx)
            cnt += 1
        
    
    return answer