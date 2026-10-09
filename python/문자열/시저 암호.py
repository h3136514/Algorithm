def solution(s, n):
    answer = ''   # 문자열 그대로

    for ch in s:
        if ch.isupper():
            answer += chr((ord(ch) - ord('A') + n) % 26 + ord('A'))
        elif ch.islower():
            answer += chr((ord(ch) - ord('a') + n) % 26 + ord('a'))
        else:
            answer += ch

    return answer