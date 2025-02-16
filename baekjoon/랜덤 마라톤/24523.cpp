// 구현, 자료구조
#include <iostream>
#include <vector>

using namespace std;
int N, num;
vector<int> v, r;

// 내 뒤에 나와 다른 수
int main(){
    cin >> N;
    v.resize(N);
    r.resize(N, -1);

    for(int i = 0; i < N; i++){
        cin >> v[i]; 
    }

    // 뒤에서 부터 탐색
    int cnt = -1;
    for(int i = N - 2; i >= 0; i--){
        if(v[i] != v[i+1]){
            cnt = i+2;  // 인덱스는 0으로 시작하므로(+1)
        }

        r[i] = cnt;
    }

    for(int i = 0; i < r.size(); i++)
        cout << r[i] << " ";
    cout << "\n";

    return 0;
}