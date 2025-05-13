#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;
int T, N, sum = 1;
string name, kind;
unordered_map<string, int> m;

// 패션왕 신해빈
int main(){
    cin >> T;
    while(T--){
        cin >> N;
        for(int i = 0; i < N; i++){
            cin >> name >> kind;
            m[kind]++;
        }
        if(m.size() == 0)
            cout << "0\n";
        else if(m.size() == 1)
            cout << m.begin()->second << "\n";
        else{
            for(auto k : m){
                sum *= (k.second + 1);
            }
            sum -= 1;   // 아무것도 선택안한 경우 제외
            cout << sum << "\n";
        }

        sum = 1;
        m.clear();
    }
    return 0;
}