# https://school.programmers.co.kr/learn/courses/30/lessons/17686

import heapq

def solution(files):
    answer = []
    q = []
    for idx, file in enumerate(files):
        HEAD = ""
        NUMBER = ""
        check_str, check_num = False, False
        for i in file:
            if check_str and check_num:
                break
            
            if not check_str:
                if i.isdigit():
                    check_str = True
                    NUMBER += i
                else:
                    HEAD += i
            else:
                if not i.isdigit():
                    check_num = True
                    continue
                else:
                    NUMBER += i
        HEAD_Str = HEAD.upper() # 대문자 변환(소문자는 lower())
        NUMBER_Num = int(NUMBER)
        heapq.heappush(q, (HEAD_Str, NUMBER_Num, idx))
    
    while q:
        currentStr, currentNum, currentIdx = heapq.heappop(q)
        answer.append(files[currentIdx])
        
        
    return answer