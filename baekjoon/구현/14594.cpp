#include <iostream>
#include <vector>

using namespace std;
int N, M, x, y, CNT;
vector<int> v;

int main(){
    cin >> N;
    v.resize(N+1, 1);   // 오른쪽 변 유무 표시(1: 벽이 있음, 2: 벽이 없음)
    cin >> M;

    for(int i = 0; i < M; i++){
        cin >> x >> y;
        for(int j = x; j < y; j++)
            v[j] = 0;
    }

    for(int i = 1; i <= N; i++){
        if(!v[i])
            continue;
        
        CNT++;
    }

    cout << CNT << "\n";

    return 0;
}