// 자료 구조, 해시맵
#include <iostream>
#include <map>

using namespace std;
int N, x, y, CNT;
map<int, int> X, Y;

// 평행선
int main(){
    cin >> N;
    
    for(int i = 0; i < N; i++){
        cin >> x >> y;
        X[x]++;
        Y[y]++;
    }

    for(auto a : X){
        if(a.second >= 2)
            CNT++;
    }

    for(auto a : Y){
        if(a.second >= 2)
            CNT++;
    }

    cout << CNT << "\n";

    return 0;
}