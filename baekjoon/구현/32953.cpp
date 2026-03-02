#include <iostream>
#include <map>

using namespace std;
int N, M, K, num, cnt;
map<int, int> m;

// 회상
int main(){
    cin >> N >> M;
    while(N--){
        cin >> K;
        for(int i = 0; i < K; i++){
            cin >> num;
            m[num]++;
        }
    }

    for(auto student : m){
        if(student.second >= M)
            cnt++;
    }

    cout << cnt << "\n";

    return 0;
}