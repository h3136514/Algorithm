#include <iostream>

using namespace std;
int N, M, cnt = 1, num[150], visitied[150];

// 죽음의 게임
int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> num[i];
    }

    int idx = 0;
    visitied[0] = 1;
    while(true){
        int next = num[idx];
        if(next == M){
            cout << cnt << "\n";
            break;
        }

        if(visitied[next]){
            cout << "-1\n";
            break;
        }

        visitied[next] = 1;
        cnt++;
        idx = next;
    }

    return 0;
}