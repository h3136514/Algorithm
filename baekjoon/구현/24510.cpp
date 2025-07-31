#include <iostream>
#include <string>

using namespace std;
int N, CNT;
string c, tmp;

// 시간복잡도를 배운 도도
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> c;
        
        int cnt = 0;
        tmp ="";
        for(int j = 0; j < c.size(); j++){
            if(c[j] == 'f')
                tmp ="f";
            else if(c[j] == 'w')
                tmp ="w";
            else if(c[j] == 'r' || c[j] == 'e'){
                tmp += c[j];
                if(tmp == "for" || tmp == "while")
                    cnt++;
                tmp ="";
            }else
                tmp += c[j];
        }

        CNT = max(CNT, cnt);
    }

    cout << CNT << "\n";

    return 0;
}