#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
int N, A, num[1000001];
long long result = 1;
vector<int> v;

// 에라토스테네스의 체 (소수 확인)
void primeNumber(int n) {
    num[1] = 1;
    for (int i = 2; i <= sqrt(n); i++) {
        if (num[i])
            continue;
        for (int j = i + i; j <= n; j += i) {
            if (num[j])
                continue;
            num[j] = 1;
        }
    }
}

// 유클리드호제법 (최대 공약수)
long long gcd(long long a, long long b) {
    if (!b)
        return a;
    return gcd(b, a % b);
}

// 최소 공배수
long long llm(long long a, long long b) {
    return a * b / gcd(a, b);
}

// 소수 최소 공배수
int main() {
    primeNumber(1000000);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A;
        if (num[A])
            continue;

        v.push_back(A);
    }

    for (int i = 0; i < v.size(); i++) {
        result = llm(result, v[i]);
    }

    result = (result == 1) ? -1 : result;

    cout << result << "\n";

    return 0;
}