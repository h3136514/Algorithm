#https://school.programmers.co.kr/learn/courses/30/lessons/42577
def solution(phone_book):
    # 1. C++의 unordered_map 역할을 하는 딕셔너리 생성
    hash_map = {}
    
    # 2. 모든 전화번호를 해시맵에 저장 (값은 1로 고정)
    for phone in phone_book:
        hash_map[phone] = 1
    
    # 3. 각 전화번호의 접두어가 해시맵에 있는지 확인
    for phone in phone_book:
        prefix = ""
        for number in phone:
            prefix += number
            
            # 접두어가 해시맵에 존재하고, 자기 자신이 아닐 경우
            if prefix in hash_map and prefix != phone:
                return False
        
    return True