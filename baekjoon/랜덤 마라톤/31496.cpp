// 구현, 문자열
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;
int N, num, sum;
string str, target;
unordered_map<string, int> m;

// 자작나무가 없소~
int main(){
    cin >> N >> target;
    for(int i = 0; i < N; i++){
        cin >> str >> num;
        m[str] = num;
    }

    for(auto word : m){
        string s = "";
        for(int i = 0; i < word.first.size(); i++){
            if(word.first[i] == '_'){
                if(s == target){
                    sum += word.second;
                    s = "";
                    break;
                }

                s = "";
            }else
                s += word.first[i];
        }

        if(s == target)
            sum += word.second;
    }
    
    cout << sum << "\n";

    return 0;
}