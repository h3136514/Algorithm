#https://school.programmers.co.kr/learn/courses/30/lessons/1845
from collections import defaultdict

def solution(nums):
    answer = 0
    N = len(nums)
    pocketMon = defaultdict(int)
    for num in nums:
        pocketMon[num] += 1
        
    if len(pocketMon) >= N/2:
        answer = N/2
    else:
        answer = len(pocketMon)
        
    return answer