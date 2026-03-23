#include <iostream>
#include <string>

using namespace std;
int T, r, c, cnt;
string s[400], tmp, a = ">o<", b= "vo^";

// 사탕 박사 고창영
int main(){
    cin >> T;
    while(T--){
        cin >> r >> c;
        for(int i = 0; i < r; i++){
            cin >> s[i];
        }

        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                tmp += s[i][j];
                if(tmp == a)
                    cnt++;
                if(tmp.size() == 3)
                    tmp.erase(0, 1);
            }
            tmp ="";
        }
        
        for(int i = 0; i < c; i++){
            for(int j = 0; j < r; j++){
                tmp += s[j][i];
                if(tmp == b)
                    cnt++;
                if(tmp.size() == 3){
                    tmp.erase(0, 1);
                }
            }
            tmp ="";
        }

        cout << cnt << "\n";
        cnt = 0;
        tmp = "";
    }

    return 0;
}