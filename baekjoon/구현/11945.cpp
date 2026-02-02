#include <iostream>
#include <string>

using namespace std;
int N, M;
string s[11];

// 뜨거운 붕어빵
int main(){
    cin >> N >> M;
    for(int i =0; i < N; i++){
        cin >> s[i];
    }

    for(int i = 0; i < N; i++){
        for(int j = M-1; j >= 0; j--){
            cout << s[i][j];
        }
        cout << "\n";
    }

    return 0;
}