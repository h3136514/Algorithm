
def solution(arr):
    answer = []
    
    if len(arr) <= 1:
        answer.append(-1)
    else:
        smallest = min(arr)
        for i in arr:
            if i > smallest:
                answer.append(i)
        
    return answer