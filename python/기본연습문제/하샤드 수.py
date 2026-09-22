def solution(x):
    answer = False
    st = str(x)
    a = 0
    for i in range(len(st)):
        a += int(st[i])
    
    if x%a == 0:
        answer = True
        
    return answer