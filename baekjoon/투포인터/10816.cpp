#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
int N, M, num;
unordered_map<int, int> m;
vector<int> result;

// 숫자 카드 2
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> num;
        m[num]++;
    }

    cin >> M;
    for(int i = 0; i < M; i++){
        cin >> num;
        result.push_back(m[num]);
    }

    for(int i = 0; i < M; i++){
        cout << result[i] << " ";
    }
    cout << "\n";

    return 0;
}