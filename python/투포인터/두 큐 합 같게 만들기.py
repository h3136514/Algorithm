# https://school.programmers.co.kr/learn/courses/30/lessons/118667?language=python3

def solution(queue1, queue2):
    answer = -1
    n = len(queue1)
    arr = queue1 + queue2
    total = sum(arr)
    
    if total % 2 :
        return -1
    
    target = total//2
    current_sum = sum(queue1)
    s, e = 0, n
    
    for cnt in range(4*n + 1):
        if current_sum == target:
            answer = cnt
            break
            
        if current_sum < target:
            current_sum += arr[e % (2*n)]
            e += 1
        else:
            current_sum -= arr[s % (2*n)]
            s += 1
    
    return answer