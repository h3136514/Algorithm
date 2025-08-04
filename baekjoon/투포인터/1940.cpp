#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int N, M, startIdx, endIdx, CNT;
vector<int> v;

// 주몽
int main(){
    cin >> N;
    cin >> M;

    v.resize(N);
    endIdx = N -1;
    for(int i = 0; i < N; i++)
        cin >> v[i];

    sort(v.begin(), v.end());

    while(startIdx < endIdx){
        if(v[startIdx] + v[endIdx] == M){
            CNT++;
            endIdx--;
            startIdx++;
        }else if(v[startIdx] + v[endIdx] < M)
            startIdx++;
        else
            endIdx--;
    }

    cout << CNT << "\n";
    
    return 0;
}