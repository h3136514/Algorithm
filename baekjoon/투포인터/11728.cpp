// 정렬(현재코드), 투포인터
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, M, num;
vector<int> V;

// 배열 합치기
int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> num;
        V.push_back(num);
    }
    for(int i = 0; i < M; i++){
        cin >> num;
        V.push_back(num);
    }

    sort(V.begin(), V.end());

    for(int i = 0; i < V.size(); i++){
        cout << V[i] << " ";
    }
    cout << "\n";

    return 0;
}
