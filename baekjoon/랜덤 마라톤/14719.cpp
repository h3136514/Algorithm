#include <iostream>
#include <stack>

using namespace std;
int H, W, baseNum, CNT, num[500];
stack<int> s;

// 빗물
int main(){
    cin >> H >> W;
    for(int i = 0; i < W; i++)
        cin >> num[i];
    
    baseNum = num[0];
    for(int i = 1; i < W; i++){
        // 블록의 길이가 기준 불럭보다 커지거나 같아지는 경우 확인
        if(baseNum <= num[i]){
            while(!s.empty()){
                CNT += baseNum - s.top();
                s.pop();
            }

            baseNum = num[i];
            continue;
        }

        s.push(num[i]);
    }

    // 블록의 길이가 계속 작거나 같아지는 경우 확인
    if(!s.empty()){
        baseNum = 0;
        while(!s.empty()){
            if(baseNum <= s.top()){
                baseNum = s.top();
            }else{
                CNT += baseNum - s.top();
            }

            s.pop();
        }
    }


    cout << CNT << "\n";

    return 0;
}