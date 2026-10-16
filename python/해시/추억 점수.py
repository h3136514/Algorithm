def solution(name, yearning, photo):
    answer = []
    m = {}
    
    for i in range(len(name)):
        m[name[i]] = yearning[i]
    
    for names in photo:
        total = 0
        for i in names:
            if i in m:
                total += m[i]
        answer.append(total)
        
    return answer