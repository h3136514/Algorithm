// 수한, 문자열, 브루트포스
#include <iostream>
#include <string>

using namespace std;
int F;
string N, r;
bool check;

// 나누기
int main(){
    cin >> N;
    cin >> F;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            string str = N;
            N[N.size()-1] = (j + '0');
            N[N.size()-2] = (i + '0');
            if(stoll(N)%F == 0){
                r += N[N.size()-2];
                r += N[N.size()-1];

                check = true;
                break;
            }
        }

        if(check)
            break;
    }

    cout << r << "\n";

    return 0;
}