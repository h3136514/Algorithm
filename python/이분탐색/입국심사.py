#https://school.programmers.co.kr/learn/courses/30/lessons/43238?language=python3
def solution(n, times):
    max_time = max(times) * n
    answer = max_time
    s = 1
    e = max_time
    
    while s <= e:
        mid = (s+e)//2
        
        cnt = 0
        for tim in times:
            cnt += mid//tim
        
        if cnt >= n:
            answer = min(answer, mid)
            e = mid - 1
        else:
            s = mid + 1
    
    return answer