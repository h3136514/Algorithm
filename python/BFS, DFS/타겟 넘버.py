https://school.programmers.co.kr/learn/courses/30/lessons/43165
def DFS(total, idx, numbers, target):
    if idx == len(numbers):
        if(total == target):
            return 1
        return 0
    
    return DFS(total+numbers[idx], idx+1, numbers, target) + DFS(total-numbers[idx], idx+1, numbers, target)

def solution(numbers, target):
    answer = DFS(0, 0, numbers, target)
    return answer