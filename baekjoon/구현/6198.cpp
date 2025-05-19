// 자료구조, 스택
#include <iostream>
#include <vector>
#include <stack>

using namespace std;
int N, h;
long long sum;
stack<pair<int, int>> s;
vector<int> v;

// 옥상 정원 꾸미기
int main(){
    cin >> N;
    v.resize(N);
    for(int i = 0; i < N; i++){
        cin >> v[i];
    }

    s.push({v[0], 0});
    for(int i = 1; i < N; i++){
        while(!s.empty()){
            if(s.top().first <= v[i]){  // 빌딩이 가려지면
                sum += (i - s.top().second -1);
                s.pop();
            }else
                break;
        }

        s.push({v[i], i});
    }

    // 나머지 볼수 있는 빌딩 높이 계산
    while(!s.empty()){
        sum += (N - s.top().second -1);
        s.pop();      
    }

    cout << sum << "\n";

    return 0;
}