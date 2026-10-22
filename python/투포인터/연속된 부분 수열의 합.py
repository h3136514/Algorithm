# https://school.programmers.co.kr/learn/courses/30/lessons/178870?language=python3

def solution(sequence, k):
    answer = [0, 0]
    s, e = 0, 0
    n = len(sequence)
    minL = n
    
    total = sequence[0]
    while s <= e:
        if total == k:
            if e-s < minL:
                minL = e-s
                answer[0], answer[1] = s, e
            total -= sequence[s]
            s += 1
            continue
        
        if total < k:
            e += 1
            if e >= n:
                break
            total += sequence[e]
        else:
            total -= sequence[s]
            s += 1
    
    return answer