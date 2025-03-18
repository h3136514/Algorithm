// 그리디
#include <iostream>
#include <vector>

using namespace std;
int M, N, pl = 0, mi = 0, maxNum;
vector<int> v, relationships, result;

// 악보는 거들 뿐
int main() {
    cin >> M;
    v.resize(M);
    result.resize(M);
    for(int i = 0; i < M; i++)
        cin >> v[i];
    
    // M이 1인 경우는 항상 N=1
    if (M == 1) {
        cout << 1 << "\n";
        return 0;
    }

    // 이전 음과의 관계를 저장 (1: 상승, -1: 하강, 0: 유지)
    relationships.resize(M - 1);
    for(int i = 1; i < M; i++){
        if(v[i-1] == v[i])
            relationships[i-1] = 0;
        else if(v[i-1] < v[i])
            relationships[i-1] = 1;
        else
            relationships[i-1] = -1;
    }

    for(int i = 1 ; i < M; i++){
        if(relationships[i-1] == 1){
            maxNum = max(maxNum, ++pl);
            mi = 0;
        }else if(relationships[i-1] == -1){
            maxNum = max(maxNum, ++mi);
            pl = 0;
        }
    }

    if(maxNum == 0)
        N = 1;
    else{
        N = maxNum + 1;
    }

    cout << N << "\n";

    return 0;
}