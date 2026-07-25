# https://school.programmers.co.kr/learn/courses/30/lessons/64062?language=python3
def solution(stones, k):
    answer = 0
    # 건널 수 있는 최소 인원 1명, 최대 인원은 가장 큰 돌의 숫자
    s, e = 1, max(stones)
    while s <= e:
        mid = (s+e) // 2    # 이번에 건너볼 인원 수
        
        cnt = 0
        check = True
        for stone in stones:
            if stone < mid:
                cnt += 1
            else:
                cnt = 0
            
            if cnt >= k :   # 못 밟는 돌이 연속으로 k개 이상 나오면 mid명은 못 건넘!
                check = False
                break
                
        if check:
            answer = mid
            s = mid + 1
        else:
            e = mid - 1
            
    return answer