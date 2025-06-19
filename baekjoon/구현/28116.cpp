#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
vector<int> moves;
unordered_map<int, int> A, idxs;
int N, num, idx;

// 선택 정렬의 이동 거리
int main(){
    cin >> N;
    moves.resize(N+1);
    for(int i = 1; i <= N; i++){
        cin >> num;
        A[i] = num;
        idxs[num] = i;
    }

    for(int i = 1; i <= N-1; i++){
        num = A[i];
        idx = idxs[i];
        if(i == num)
            continue;
        int differ = idx - i;
        moves[i] += differ, moves[num] += differ;

        A[idx] = num;
        idxs[num] = idx;
    }

    for(int i = 1; i <= N; i++){
        cout << moves[i] << " ";
    }
    cout << "\n";

    return 0;
}