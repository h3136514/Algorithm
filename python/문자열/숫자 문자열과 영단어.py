def solution(s):
    m = {
        "zero": "0", "one": "1", "two": "2", "three": "3", "four": "4",
        "five": "5", "six": "6", "seven": "7", "eight": "8", "nine": "9",
    }
    
    for i in range(10):
        m[str(i)] = str(i)

    strAnswer = ""
    tmp = ""
    for ch in s:
        tmp += ch
        if tmp in m:
            strAnswer += m[tmp]
            tmp = ""

    return int(strAnswer)