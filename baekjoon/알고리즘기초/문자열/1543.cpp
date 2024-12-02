#include <iostream>
#include <string>

using namespace std;
int CNT, idx;
string str, target;

// 문서 검색
int main(){
    getline(cin, str);
    getline(cin, target);

    
    for(int i = 0; i < str.size(); i++){
        if(str.size()- i < target.size())
            break;

        int cnt = 0;
        for(int j = 0; j < target.size(); j++){
            if(str[i+j] == target[j])
                cnt++;
        }
        
        if(cnt == target.size()){
            i += target.size() -1;
            CNT++;
        }
        
    }

    cout << CNT <<"\n";

    return 0;
}