#https://school.programmers.co.kr/learn/courses/30/lessons/17681
def solution(n, arr1, arr2):
    answer = []
    visited = [[0]*n for _ in range(n)] #2차원 배열 만들기
    
    for i in range(n):
        cnt = 0
        while arr1[i] > 0:
            if arr1[i] % 2 == 1:
                visited[i][cnt] = 1
            cnt += 1
            arr1[i] //= 2
    
    for i in range(n):
        cnt = 0
        while arr2[i] > 0:
            if arr2[i] % 2 == 1:
                visited[i][cnt] = 1
            cnt += 1
            arr2[i] //= 2
    
    # 암호화된 배열 만들기
    for i in range(n):
        s = ""
        for j in range(n-1, -1, -1): #역순으로 출력
            if visited[i][j] == 1:
                s += "#"
            else:
                s += " "
        
        answer.append(s)
                
    return answer

# 다른 풀이

2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
def solution(n, arr1, arr2) :
    result = []

    for j in range(0,len(arr1)) :
        ret = ''
        num = arr1[j] | arr2[j]

        for i in range(0, n) :
            if num % 2 == 0 :
                ret = ' ' + ret

            else : 
                ret = '#' + ret

            num = int(num / 2)

        result.append(ret)

    return result