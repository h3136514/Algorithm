// 구현
#include <iostream>
#include <string>

using namespace std;
bool S[21];
int M, x;
string str;

// 집합
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> M;
    for(int i = 0; i < M; i++){
        cin >> str;
        if(str == "all"){
            for(int j = 1; j <= 20; j++)
                S[j] = true;
        }else if(str == "empty"){
            for(int j = 1; j <= 20; j++)
                S[j] = false;
        }else{
            cin >> x;
            if(str == "add")
                S[x] = true;
            else if(str == "remove")
                S[x] = false;
            else if(str == "check"){
                if(S[x])
                    cout << "1\n";
                else
                    cout << "0\n";
            }else if(str == "toggle"){
                if(S[x])
                    S[x] = false;
                else
                    S[x] = true;
            }
        }
    }

    return 0;
}