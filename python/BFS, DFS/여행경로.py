#https://school.programmers.co.kr/learn/courses/30/lessons/43164
def solution(tickets):
    # 알파벳 순으로 앞서는 경로를 찾기 위해 미리 티켓을 정렬
    tickets.sort()
    
    N = len(tickets)
    visited = [False for _ in range(N)]
    answer = []
    
    def dfs(airport, path):
        # 모든 티켓을 다 사용했다면 그 경로가 정답
        if len(path) == N + 1:
            return path
        
        for i in range(N):
            # 출발지가 현재 공항이고, 아직 쓰지 않은 티켓인 경우
            if tickets[i][0] == airport and not visited[i]:
                visited[i] = True  # 방문 처리
                
                # 다음 공항으로 재귀 호출 (경로에 추가)
                res = dfs(tickets[i][1], path + [tickets[i][1]])
                
                # 정답을 찾았다면 더 이상 탐색하지 않고 그대로 리턴
                if res: 
                    return res
                
                # 정답을 못 찾고 막혔다면 백트래킹(원상복구) 후 다음 티켓 탐색
                visited[i] = False 
                
        return None

    # 시작은 항상 ICN
    return dfs("ICN", ["ICN"])