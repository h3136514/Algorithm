# https://school.programmers.co.kr/learn/courses/30/lessons/49191?language=python3

def solution(n, results):
    answer = 0
    
    # 1. 2차원 리스트 초기화
    dp = [[0] * (n + 1) for _ in range(n + 1)]
    
    # 2. 초기 경기 결과 기록 (a가 b를 이김)
    for a, b in results:
        dp[a][b] = 1
        
    # 3. 플로이드-워셜 알고리즘 핵심 로직
    # k: 거쳐가는 선수, i: 승자, j: 패자
    for k in range(1, n + 1):
        for i in range(1, n + 1):
            for j in range(1, n + 1):
                # i가 k를 이기고, k가 j를 이겼다면 -> i는 j를 이긴다!
                if dp[i][k] == 1 and dp[k][j] == 1:
                    dp[i][j] = 1
                    
    # 4. 정확하게 순위를 매길 수 있는 선수 찾기
    for i in range(1, n + 1):
        count = 0
        for j in range(1, n + 1):
            # 내가 이겼거나(dp[i][j]), 내가 졌거나(dp[j][i]) 승패 관계를 아는 경우
            if dp[i][j] == 1 or dp[j][i] == 1:
                count += 1
                
        # 나를 제외한 모든 선수(n-1명)와의 승패를 안다면 순위 확정 가능
        if count == n - 1:
            answer += 1
            
    return answer