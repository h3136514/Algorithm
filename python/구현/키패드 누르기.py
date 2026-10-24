# https://school.programmers.co.kr/learn/courses/30/lessons/67256

from collections import defaultdict

def solution(numbers, hand):
    answer = ''
    lx, ly, rx, ry = 0, 3, 2, 3
    location = defaultdict(list)
    
    num = 0
    for i in range(3):
        for j in range(3):
            num += 1
            location[num].append([j, i])
    location["*"].append([0, 3])
    location[0].append([1, 3])
    location["#"].append([2, 3])
    
    for i in numbers:
        x, y = location[i][0][0], location[i][0][1]
        if i == 1 or i == 4 or i == 7:
            lx, ly = x, y
            answer += "L"
        elif i == 3 or i == 6 or i == 9:
            rx, ry = x, y
            answer += "R"
        else:
            distR = abs(x-rx) + abs(y-ry)
            distL = abs(x-lx) + abs(y-ly)
            use =""
            if distR > distL:
                use = "left"
            elif distR < distL:
                use = "right"
            else:
                use = hand
                
            if use == "left":
                lx, ly = x, y
                answer += "L"
            else:
                rx, ry = x, y
                answer += "R"
    
    return answer