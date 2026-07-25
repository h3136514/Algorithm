# https://school.programmers.co.kr/learn/courses/30/lessons/42586?language=python3
def solution(progresses, speeds):
    answer = []
    ago = 0
    cnt = 0
    N = len(progresses)
    
    for i in range(N):
        day = (100 - progresses[i]) // speeds[i]
        if day*speeds[i] != 100 - progresses[i]:
            day += 1
       
        if ago == 0:
            ago = day;
        elif ago < day:
            ago = day;
            answer.append(cnt)
            cnt = 1
            continue
        cnt += 1
    
    answer.append(cnt)
    
        
    return answer