def solution(x, n):
    answer = []
    for i in range(n):
        answer.append(i * x + x)
        
    return answer