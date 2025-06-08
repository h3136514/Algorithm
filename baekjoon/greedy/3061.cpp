// 정렬
#include <iostream>

using namespace std;
int T, N, num[1001], idx, CNT;

// 사다리
int main(){
    cin >> T;
    while(T--){
        cin >> N;
        for(int i = 1; i <= N; i++){
            cin >> num[i];
        }

        for(int i = 1; i <= N; i++){
            if(num[i] == i)
                continue;
            
            for(int j = i+1; j <= N; j++){
                if(num[j] == i){
                    idx = j;
                    break;
                }
            }

            // 사다리 설치(인접한 숫자 위치 변경, 정렬)
            for(int j = idx-1; j >= i; j--){
                CNT++;
                int tmp = num[j+1];
                num[j+1] = num[j];
                num[j] = tmp;
            }
        }

        cout << CNT << "\n";
        CNT = 0;
    }

    return 0;
}