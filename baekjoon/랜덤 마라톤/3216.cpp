// 그리디
#include <iostream>
#include <vector>

using namespace std;
int N, D, V, sumD, sumV;
vector<pair<int, int>> v;

// 다운로드 
int main(){
    cin >> N;
    v.resize(N);

    for(int i = 0; i < N; i++){
        cin >> v[i].first >> v[i].second;
    }

    sumD = v[0].first;
    sumV = v[0].second;

    for(int i = 1; i < N; i++){
        if(sumD >= v[i].second){
            sumD -= v[i].second;
            sumD += v[i].first;
        }else{
            sumV += v[i].second - sumD;
            sumD = v[i].first;
        }
    }

    cout << sumV << "\n";

    return 0;
}