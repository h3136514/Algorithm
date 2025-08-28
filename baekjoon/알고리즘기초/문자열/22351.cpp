#include <iostream>
#include <string>

using namespace std;
int N, a, b;
string s, tmp;
bool check = false;

// 수학은 체육과목 입니다 3
int main(){
    cin >> s;
    for(int i = 1; i <= 999; i++){
        tmp = to_string(i);
        if(tmp == s){
            a = i;
            b = i;
            check = true;
            break;
        }

        for(int j = i + 1; j <= 999; j++){
            tmp += to_string(j);
            if(s.size() < tmp.size())
                break;
            
            if(tmp == s){
                a = i;
                b = j;
                check = true;
                break;
            }
        }

        if(check)
            break;
    }

    cout << a << " " << b << "\n";

    return 0;
}