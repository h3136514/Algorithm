def solution(n):
    answer = []
    while n > 0 :
        answer.append(n % 10)
        n //= 10    # 일의 자리를 버리고 한 자리 줄임
        
    return answer