#https://school.programmers.co.kr/learn/courses/30/lessons/42748?language=python3

def solution(array, commands):
    answer = []
    
    for command in commands:
        i = command[0]
        j = command[1]
        k = command[2]
        slice_array = array[i-1:j]
        slice_array.sort()
        
        answer.append(slice_array[k-1])
    
    return answer