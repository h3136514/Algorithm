#include <iostream>
#include <vector>

using namespace std;
int T, N, ago = 0, cnt = 1, num[1001];
vector<int> v;

// 유레카 이론
int main(){
    while(true){
        int tmp = ago + cnt;
        if(tmp > 1000)
            break;
        v.push_back(tmp);
        ago = tmp;
        cnt++;
    }
    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < v.size(); j++){
            if(v[i] + v[j] > 1000){
                break;
            }
            for(int k = 0; k < v.size(); k++){
                if(v[i] + v[j] + v[k] > 1000){
                    break;
                }
                int idx = v[i] + v[j] + v[k];
                num[idx] = 1;
            }
        }
    }

    cin >> T;
    while(T--){
        cin >> N;
        cout << num[N] << "\n";
    }

    return 0;
}