#include <string>
#include <vector>

using namespace std;
int answer = 0;

int solution(vector<string> babbling) {
    for(auto s : babbling){
        string tmp = "";
        string ago = "";
        bool check = true;
        for(int i = 0; i < s.size(); i++){
            tmp += s[i];
            if(tmp.size() < 2){
                continue;
            }
            
            if(tmp.size() == 2){
                if(tmp == "ye"){
                    if(ago == "ye"){
                        check = false;
                        break;
                    }
                    ago = "ye";
                    tmp = "";
                }else if(tmp == "ma"){
                     if(ago == "ma"){
                        check = false;
                        break;
                    }
                    ago = "ma";
                    tmp = "";
                }
            }else{
                if(tmp == "aya"){
                    if(ago == "aya"){
                        check = false;
                        break;
                    }
                    ago = "aya";
                    tmp = "";
                }else if(tmp == "woo"){
                    if(ago == "woo"){
                        check = false;
                        break;
                    }
                    ago = "woo";
                    tmp = "";
                }else{
                    check = false;
                    break;
                }
            }
        }
        if(tmp.size() == 0 && check)
            answer++;
    }

    return answer;
}