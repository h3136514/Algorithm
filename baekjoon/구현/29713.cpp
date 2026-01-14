#include <iostream>
#include <string>

using namespace std;
int N, cnt, alpha[26];
string s, target ="BRONZESILVER";

//브실이의 띠부띠부씰 컬렉션
int main(){
    cin >> N;
    cin >> s;
    for(int i = 0; i < N; i++){
        int idx = s[i] - 65;
        alpha[idx]++;
    }

    while(true){
        bool check = false;
        for(int j = 0; j < target.size(); j++){
            int idx = target[j] - 65;
            if(alpha[idx] == 0){
                check = true;
                break;
            }
            alpha[idx]--;
        }

        if(check){
            break;
        }
        cnt++;
    }

    cout << cnt << "\n";

    return 0;
}