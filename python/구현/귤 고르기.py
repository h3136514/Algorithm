from collections import Counter

def solution(k, tangerine):
    answer = 0
    counter = Counter(tangerine)
    counter = sorted(counter.values())
    
    cnt = 0
    while cnt < k:
        cnt += counter.pop()
        answer += 1
        
    return answer

# defaultdict 사용
from collections import defaultdict

def solution(k, tangerine):
    count = defaultdict(int)
    for t in tangerine:
        count[t] += 1

    answer = 0
    for c in sorted(count.values(), reverse=True):
        k -= c
        answer += 1
        if k <= 0:
            break

    return answer