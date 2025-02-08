// 구현, 문자열
#include <iostream>
#include <string>

using namespace std;
int N, num, returnRing[101], CNT = 1;
string name[101];
char a;

// 초기화
void init(){
    for(int i = 1; i <= N; i++)
        returnRing[i] = 0;
}

// 귀걸이
int main(){
    while(true){
        cin >> N;
        if(N == 0)
            break;

        cin.ignore();   // getline을 위해 버퍼를 지워준다.(안해주면 시간초과)

        for(int i = 1; i <= N; i++){
            getline(cin, name[i]);
        }

        for(int i = 0; i < N*2-1; i++){
            cin >> num >> a;
            returnRing[num]++;
        }
        
        for(int i = 1; i <= N; i++){
            if(returnRing[i] == 1){
                cout << CNT << " " << name[i] << "\n";

                break;
            }
        }

        CNT++;
        init();
    }

    return 0;
}