#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int N, M, X, Y, h, num, sub, cnt;
string schoolNum;
vector<int> v;

int main(){
    cin >> N >> M >> X >> Y;
    cin >> schoolNum >> h;

    for(int i = 0; i < N-1; i++){
        cin >> schoolNum >> num;
       
        if(schoolNum.substr(0,4) != "2024")
            continue;
        
        int score = (Y - (X-num)) < 0 ? 0 : (Y - (X-num));
        v.push_back(num + score);
    }

    sort(v.rbegin(), v.rend());

    if(v.size() >= M){
        num = v[0];
        cnt = 1;
        sub = 1;

        for(int i = 1; i < v.size(); i++){
            if(num == v[i]){
                sub++;
                continue;
            }
            
            cnt += sub;
            sub = 1;

            if(cnt >= M){
                if(cnt == M)
                    num = v[i];
                break;
            }
            
            num = v[i];
        }
    }

    if(h+Y >= num){
        cout << "YES\n";
        if(cnt < M || h >= num)
            cout << "0\n";
        else
            cout << num-h << "\n";
    }else
        cout << "NO\n";

    return 0;
}