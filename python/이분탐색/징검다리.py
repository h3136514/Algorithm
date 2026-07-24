#https://school.programmers.co.kr/learn/courses/30/lessons/43236?language=python3
def solution(distance, rocks, n):
    answer = 0
    s = 0
    e = distance
    rockLen = len(rocks)
    
    rocks.sort()
    while s <= e:
        mid = (s+e)//2
        cnt = 0
        pre = 0
        
        for rock in rocks:
            if rock - pre < mid:
                cnt += 1
                continue
            pre = rock
        
        if distance - pre < mid:
            cnt += 1
        
        if cnt > n:
            e = mid - 1
        else:
            answer = max(answer, mid)
            s = mid + 1
        
        
    return answer