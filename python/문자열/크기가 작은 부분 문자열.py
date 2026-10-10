def solution(t, p):
    answer = 0
    length = len(p)
    p_num = int(p)

    for i in range(len(t) - length + 1):
        if int(t[i:i + length]) <= p_num:
            answer += 1
    return answer