def main():
    # 1000번째 항까지 미리 계산
    A = [1, 1]
    for i in range(2, 1001):
        m_fire = set()
        for k in range(1, i // 2 + 1):
            m_fire.add(2 * A[i - k] - A[i - 2 * k])
        c = 1
        while c in m_fire:
            c += 1
        A.append(c)

    T = int(input())
    for _ in range(T):
        n = int(input())
        print(A[n])


if __name__ == "__main__":
    main()