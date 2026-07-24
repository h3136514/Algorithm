#https://school.programmers.co.kr/learn/courses/30/lessons/42746?language=python3

def solution(numbers):
    answer = ''
    #숫자들을 문자열(str)로 변환해서 리스트에 담기(문자열 상태여야 앞에서부터 한 글자씩 아스키코드로 비교할 수 있음)
    list_str = [str(num) for num in numbers]
    
    #문자열을 3번 반복해서 비교(숫자는 최대 1,000 이하이므로 최소 1자리의 숫자가 최대 3자리인 다른 숫자들과 비교가능)
    list_str.sort(key = lambda x : x*3, reverse=True)
    
    #정렬된 문자열 리스트를 하나의 문자열로 이어 붙이기
    answer = "".join(list_str)
    return answer