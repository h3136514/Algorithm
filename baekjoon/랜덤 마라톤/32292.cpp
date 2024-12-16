// 구현, 문자열, 브루트포스
#include <iostream>
#include <string>

using namespace std;
int T, N;
string str;

// ABB to BA (Easy)
int main(){
    cin >> T;
    while(T--){
        cin >> N;
        cin >> str;
        while(true){
            int idx = str.find("ABB");
            if(idx == -1)
                break;
            else
                str.replace(idx, 3, "BA");
        }

        cout << str << "\n";
    }

    return 0;
}