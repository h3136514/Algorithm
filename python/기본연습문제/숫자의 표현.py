def solution(n):
    answer = 0
    for i in range(1, n+1):
        summ = 0
        while (summ < n):
            summ += i
            i += 1
        if summ == n:
            answer += 1
            
    return answer