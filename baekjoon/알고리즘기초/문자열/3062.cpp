#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int T;
string a, b;

// 수 뒤집기
int main(){
    cin >> T;
    while(T--){
        cin >> a;
        b = a;
        reverse(b.begin(), b.end());
        int sum = stoi(a) + stoi(b);
        string st = to_string(sum);

        bool check = true;
        for(int i = 0; i < st.size()/2; i++){
            if(st[i] != st[st.size()-1-i]){
                check = false;
                break;
            }
        }

        if(check)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
