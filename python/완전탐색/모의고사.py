#https://school.programmers.co.kr/learn/courses/30/lessons/42840?language=python3
def solution(answers):
    answer = []
    drop1 = [1, 2, 3, 4, 5]
    drop2 = [2, 1, 2, 3, 2, 4, 2, 5]
    drop3 = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]
    score = [0, 0, 0]
    n = len(answers)
    
    for i in range(n):
        if drop1[i % len(drop1)] == answers[i]:
            score[0] += 1
        if drop2[i % len(drop2)] == answers[i]:
            score[1] += 1
        if drop3[i % len(drop3)] == answers[i]:
            score[2] += 1
    
    # 최고 점수를 찾는다
    max_score = max(score)
    
    # enumerate를 쓰면 i에는 인덱스(0, 1, 2)가, s에는 점수가 들어옴
    for i, s in enumerate(score):
        if s == max_score:
            answer.append(i+1)
    
    return answer