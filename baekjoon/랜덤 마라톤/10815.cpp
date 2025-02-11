// 자료구조
#include <iostream>
#include <vector>

using namespace std;
int N, M, a, num[20000001];
vector<int> V;

// 숫자 카드
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a;
        num[a+10000000] = 1;
    }
    cin >> M;
    for(int i = 0; i < M; i++){
        cin >> a;
        V.push_back(a+10000000);
    }

    for(int i = 0; i < V.size(); i++){
        if(num[V[i]])
            cout << "1 ";
        else
            cout << "0 ";
    }
    cout << "\n";

    return 0;
}