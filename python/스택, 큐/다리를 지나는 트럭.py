from collections import deque

def solution(bridge_length, weight, truck_weights):
    q = deque() # 큐에는 (트럭이 다리를 빠져나갈 시간, 트럭 무게) 튜플을 저장
    currentTime = 1
    currentWeight = 0
    
    for w in truck_weights:
        while True:
            # 현재 시간에 이미 다리를 다 건넌 트럭이 있다면 빼주기
            if q and q[0][0] == currentTime:
                exitT, exitW = q.popleft()
                currentWeight -= exitW
            # 새 트럭 진입 조건: "다리 위 트럭 수 < 다리 길이" AND "무게 합 <= 견디는 무게"
            if len(q) < bridge_length and currentWeight + w <= weight:
                q.append((currentTime+bridge_length, w))
                currentWeight += w
                currentTime += 1 #다음 트럭을 위해 1초 증가
                break
            else: #당장 진입할 수 없다면, 가장 맨 앞 트럭이 빠져나갈 시간으로
                currentTime = q[0][0] 
                
    return q[-1][0] # 마지막 트럭 빠져나가는 시간