#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, num, target, idx, visitied[201];
vector<int> v[2];

// 카드 캡터 상근이
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> num;
        visitied[num] = 1;
        v[0].push_back(num);
    }

    for(int i = 1; i <= 2*N; i++){
        if(visitied[i])
            continue;
        
        v[1].push_back(i);
    }

    sort(v[0].begin(), v[0].end());
    sort(v[1].begin(), v[1].end());

    while (true){
        if(v[0].empty() || v[1].empty())
            break;
        
        if(target == 0){
            target = v[idx][0];
            v[idx].erase(v[idx].begin());
        }else{
            bool check = false;
            for(int i = 0; i < v[idx].size(); i++){
                if(v[idx][i] > target){
                    target = v[idx][i];
                    v[idx].erase(v[idx].begin() + i);
                    check = true;
                    break;
                }
            }

            if(!check){
                target = 0;
            }
        }
        
        idx = (idx == 0) ? 1 : 0;
    }

    cout << v[1].size() << "\n";
    cout << v[0].size() << "\n";

    return 0;
}
