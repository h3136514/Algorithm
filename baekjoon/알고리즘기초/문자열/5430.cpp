#include <iostream>
#include <string>
#include <deque>

using namespace std;
int T, N, D;
bool dir = true; 
string str, P, tmp, result;
deque<string> dq;

// 초기화
void init(){
    dir = true; // 정반향
    tmp = "";
    D = 0;
    result = "[";
    while(!dq.empty())
        dq.pop_back();
}

// AC
int main(){
    cin >> T;
    while(T--){
        cin >> P;
        cin >> N;
        cin >> str;

        init(); 
        for(int i = 1; i < str.size()-1; i++){
            if(str[i] == ','){
                dq.push_back(tmp);
                tmp = "";
            }else
                tmp += str[i];
        }
        dq.push_back(tmp);

        // 함수 수행 (R(순서 뒤집기), D(첫번째 수 버리기))
        for(int i = 0; i < P.size(); i++){
            if(P[i] == 'R')
                dir = (dir == true) ? false : true;
            else{
                D++;
                if(D > N)
                    break;
                
                if(dir)
                    dq.pop_front();
                else
                    dq.pop_back();
            }
        }
        if(D > N){  // 배열보다 많은 수를 삭제
            cout << "error\n";
            continue;
        }

        // 문자열 츨력
        while(!dq.empty()){
            if(dir){
                result += dq.front();
                dq.pop_front();
            }else{
                result += dq.back();
                dq.pop_back();
            }
            // 마지막 원소가 아니라면
            if(!dq.empty())
                result += ",";
        }
        result += "]";

        cout << result << "\n";
    }

    return 0;
}