from collections import defaultdict

def solution(s):
    answer = []
    hash_map = defaultdict(lambda: -1)  # 글자별 마지막 등장 위치 (없으면 -1)

    for i, ch in enumerate(s):
        if hash_map[ch] == -1:
            answer.append(-1)
        else:
            answer.append(i - hash_map[ch])
        hash_map[ch] = i  # 마지막 위치 갱신

    return answer