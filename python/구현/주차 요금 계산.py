# https://school.programmers.co.kr/learn/courses/30/lessons/92341

from collections import defaultdict

def solution(fees, records):
    base_time, base_fee, unit_time, unit_fee = fees
    in_time = {}                    # 차량번호 -> 입차 시각(분)
    total_time = defaultdict(int)   # 차량번호 -> 누적 주차 시간(분)

    for record in records:
        t, num, status = record.split()
        minute = int(t[:2]) * 60 + int(t[3:])

        if status == "IN":
            in_time[num] = minute
        else:
            total_time[num] += minute - in_time.pop(num)

    # 출차 기록이 없는 차량은 23:59 출차로 간주
    end = 23 * 60 + 59
    for num, minute in in_time.items():
        total_time[num] += end - minute

    answer = []
    for num in sorted(total_time):   # 차량번호가 작은 순
        time = total_time[num]
        if time <= base_time:
            answer.append(base_fee)
        else:
            extra = (time - base_time + unit_time - 1) // unit_time  # 올림
            answer.append(base_fee + extra * unit_fee)

    return answer