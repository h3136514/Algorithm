# https://school.programmers.co.kr/learn/courses/30/lessons/86053?language=python3

# 최악의 경우
# 걸리는 최소시간(왕복) : 2 
# 금 따로 은 따로(한도시에 금,은만 있을경우) : 2
# 광물의 최대무게 : 10**9
# 도시의 최대개수 : 10**5
INF = (10**9) * (10**5) * 4

def solution(a, b, g, s, w, t):
    answer = INF
    start = 0
    end = INF
    
    while start <= end:
        mid = (start+end)//2
        g_sum, s_sum, total = 0, 0, 0 # 지금까지 옮긴 금, 은, 금+은 
        
        for gold, silver, weight, time in zip(g, s, w, t):
            cnt = mid // (time*2)   # 주어진 시간 내 이동할 수 있는 총 횟수
            if mid % (time*2) >= time:   # 시간이 남으면 편도 한 번 더
                cnt += 1
                
            possible = cnt * weight # 운반할 수 있는 총량
            
            g_sum += min(gold, possible)
            s_sum += min(silver, possible)
            total += min(gold + silver, possible)
        
        if total >= a+b and g_sum >= a and s_sum >= b:  # 제한시간 내에 다 옮겼다면
            end = mid -1
            answer = min(answer, mid)
        else:   # mid 시간 내로 부족하단 의미이므로 start 수정
            start = mid + 1
    
    return answer