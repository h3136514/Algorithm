// 구현, 문자열, 브루트포스
#include <iostream>
#include <string>

using namespace std;
int CNT;
string ago, cur;
bool check = true;

// 단어 사다리
int main(){
    while(true){
        cin >> cur;
        if(cur == "#"){
            if(CNT > 0){
                if(check)
                    cout << "Correct\n";
                else
                    cout << "Incorrect\n";
                
                check = true;
                CNT = 0;
            }else
                break;
            
            continue;
        }else
            CNT++;
        
        
        if(CNT == 1)
            ago = cur;
        else{
            if(ago.size() != cur.size())
                check = false;
            else{
                int differ = 0;
                for(int i = 0; i < ago.size(); i++){
                    if(ago[i] != cur[i])
                        differ++;
                }

                if(differ != 1)
                    check = false;
            }
            ago = cur;
        }
    }

    return 0;
}