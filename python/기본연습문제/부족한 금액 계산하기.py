def solution(price, money, count):
    answer = 0
    sum = 0
    for i in range(count):
        sum += price + price*i
    if money < sum :
        answer = sum - money
    
    return answer