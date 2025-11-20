#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, CNT = 4;
vector<int> v;

// 올바른 배열
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> N;
    v.resize(N);
    for(int i = 0; i < N; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    for(int i = 0; i < v.size(); i++){
        int s = v[i];
        int e = s + 4;

        int cnt = 1;
        for(int j = i + 1; j < v.size(); j++){
            if(j > i+4){
                break;
            }

            if(v[j] > e){
                break;
            }

            cnt++;
        }
        
        CNT = min(CNT, 5 - cnt);
    }
    
    cout << CNT << "\n";

    return 0;
}