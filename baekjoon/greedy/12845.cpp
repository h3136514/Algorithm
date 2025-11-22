#include <iostream>
#include <vector>

using namespace std;
int N;
long long sum;
vector<int> v;

// 모두의 마블
int main(){
    cin >> N;
    v.resize(N);
    for(int i = 0; i < N; i++){
        cin >> v[i];
    }

    while(v.size() > 1){
        int idx = 0, maxNum = 0;
        for(int i = 0; i < v.size(); i++){
            if(maxNum < v[i]){
                maxNum = v[i];
                idx = i;
            }
        }

        if(maxNum == 0)
            break;

        int smallIdx = 0;
        if(idx == 0){
            smallIdx = 1;
        }else if(idx == v.size()-1){
            smallIdx = v.size()-2;
        }else{
            if(v[idx -1] < v[idx+1]){
                smallIdx = idx-1;
            }else{
                smallIdx = idx+1;
            }
        }

        sum += v[idx] + v[smallIdx];
        v.erase(v.begin() + smallIdx);
    }

    cout << sum << "\n";
}