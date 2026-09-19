answer = 0
    
def solution(n):
    ls = list(str(n))
    ls.sort(reverse = True)
    answer =  int("".join(ls))
    return answer