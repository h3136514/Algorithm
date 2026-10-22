# https://school.programmers.co.kr/learn/courses/30/lessons/340212?language=python3

def solution(diffs, times, limit):
    answer = max(diffs)
    n = len(diffs)
    s, e = 1, 1000000000000000
    
    while s <= e:
        mid = (s+e)//2
        
        pre, total = 0, 0  # 이전퍼즐 소요시간, 전체 소요시간
        for idx in range(n):
            if diffs[idx] <= mid:
                total += times[idx]
            else:
                total += (times[idx] + pre)* (diffs[idx]-mid) + times[idx]
            pre =times[idx]
        
        if total > limit: #제한시간안에 못 풀때
            s = mid +1
        else:
            answer = min(answer, mid)
            e = mid - 1
        
    return answer