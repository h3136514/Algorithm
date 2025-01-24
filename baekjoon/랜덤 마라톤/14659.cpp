// 그리디
#include <iostream>

using namespace std;
int N, num[30001], maxCnt;

// 한조서열정리하고옴ㅋㅋ
int main(){
    cin >> N;
    
    for(int i = 0; i < N; i++)
        cin >> num[i];
    
    for(int i = 0; i < N; i++){

        int cnt = 0;
        for(int j = i+1; j < N; j++){
            if(num[i] < num[j])
                break;

            cnt++;        
        }

        maxCnt = max(maxCnt, cnt);
    }

    cout << maxCnt << "\n";

    return 0;
}