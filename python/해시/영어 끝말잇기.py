# https://school.programmers.co.kr/learn/courses/30/lessons/12981?language=python3
def solution(n, words):
    answer = []
    word = {}
    cnt = 0
    
    endChar = ''
    for i in words:
        if (i in word) or (endChar != '' and endChar != i[0]): # 이미 있는 단어거나 끝말잇기가 틀렸을 때
            answer.append(cnt % n + 1)
            answer.append(cnt//n + 1)
            break
                   
        word[i] = True
        endChar = i[len(i)-1]
        cnt += 1
        
    # 탈락자가 생기지 않는다면
    if len(answer) == 0:
        answer.append(0)
        answer.append(0)
        
    return answer