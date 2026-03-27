#include <iostream>
#include <string>

using namespace std;
int N, M, idx;
string target, s;

// Send me the money
int main(){
    cin >> N >> M;
    cin >> target;
    for(int i = 0; i < M; i++){
        cin >> s;
        bool check = false;
        idx = 0;

        for(int j = 0; j < s.size(); j++){
            if(s[j] == target[idx]){
                idx++;
            }

            if(idx >= N){
                check = true;
                break;
            }
        }
        if(check){
            cout << "true\n";
        }else
            cout << "false\n";
    }

    return 0;
}