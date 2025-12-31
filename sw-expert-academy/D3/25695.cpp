#include <iostream>
#include <map>

using namespace std;
int T, A, B, C, X, Y, Z;
map<int, int> m;

// 세 정수
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> T;
    while(T--){
        cin >> X >> Y >> Z;
        m[X]++, m[Y]++, m[Z]++;

        if(m.size() == 1){
            A = X, B = X, C= X;
        }else if(m.size() == 3){
            A = -1, B = -1, C= -1;
        }else{
            int bigNum, smallNum;
            for(auto a : m){
                if(a.second == 2){
                    bigNum = a.first;
                }else{
                    smallNum = a.first;
                }
            }

            if(bigNum > smallNum){
                bool check = false;
                if(X == bigNum  && Z == bigNum){
                    A = bigNum, B = smallNum, C= smallNum;
                }else if(X == bigNum  && Y == bigNum){
                    A = smallNum, B = bigNum, C= smallNum;
                }else{
                    A = smallNum, B = smallNum, C= bigNum;
                }
            }else{
                A = -1, B = -1, C= -1;
            }
        }

        cout << A << " " << B << " " << C <<"\n";

        m.clear();
    }   

    return 0;
}