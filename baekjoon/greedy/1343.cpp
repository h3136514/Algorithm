#include <iostream>
#include <string>

using namespace std;
int sum;
string s, r;

// 폴리오미노
int main(){
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '.'){
            if(sum != 0){
                if(sum % 2 != 0){
                    sum = -1;
                    break;
                }else{
                    if(sum/4 > 0){
                        for(int j = 0; j < sum/4; j++){
                            r += "AAAA";
                        }

                        sum %= 4;
                    }

                    if(sum > 0)
                        r += "BB";
                }
                sum = 0;
            }
            
            r += '.';
        }else
            sum++;
    }

    if(sum == -1 || sum % 2 != 0){
        cout << "-1\n";
    }else{
        if(sum/4 > 0){
            for(int j = 0; j < sum/4; j++){
                r += "AAAA";
            }

            sum %= 4;
        }
        if(sum > 0)
            r += "BB";

        cout << r << "\n";
    }

    return 0;
}