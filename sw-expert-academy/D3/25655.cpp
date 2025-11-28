#include <iostream>
#include <string>

using namespace std;
int T, X;
string s;

// 유치원생은 쉽게 푸는 문제
int main(){
    cin >> T;
    while(T--){
        cin >> X;
        if(X == 1){
            s ="0";
        }else{
            if(X % 2 == 1)
                s += "4";

            for(int i = 0; i < X/2; i++)
                s += "8";
        }

        cout << s << "\n";
        s = "";
    }

    return 0;
}