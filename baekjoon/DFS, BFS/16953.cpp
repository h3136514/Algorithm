
#include <iostream>
#include <string>
#include <queue>

using namespace std;
queue<pair<string, long long>> q;
string A, B;
long long longB, lenB, result;

long long bfs(string start) {
    q.push({start, 1});

    while(!q.empty()) {
        string nextStr = q.front().first;
        long long cnt = q.front().second;
        long long nextInt = stoll(nextStr); // string => long long형
        q.pop();
        // 현재값이 B보다 크면 넘어감
        if(nextInt > longB)
            continue;
        
        if(longB == nextInt)
            return cnt;
        
        string iStr;
        // 자리수가 적을 때만(계산 줄이기, 안해도 되긴 함)
        if(nextStr.size() < lenB ) {
            // 2. 1을 수의 가장 오른쪽에 추가한 경우
            iStr = nextStr + '1';
            q.push({iStr, cnt+1});
        }
        // 1. 2를 곱한 경우
        long long iX = nextInt*2;
        iStr = to_string(iX); // int => string형
        q.push({iStr, cnt+1});
    }

    return -1;
}

// 정수 A를 B로 바꾸려고 한다. 가능한 연산은 다음과 같은 두 가지이다.(1.2를 곱한다, 2.1을 수의 가장 오른쪽에 추가한다.)
int main() {
    cin >> A >> B;
    lenB = B.size(); //B의 길이 
    longB = stoll(B);     // string => long long형

    result = bfs(A);
    cout << result << "\n";

    return 0;
}

// (int형 자료형을 고려해서 B -> A 로 반대로 탐색하는것도 나쁘지 않았을 것 같다.)