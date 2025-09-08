#include <iostream>

using namespace std;
int T, num[10], month[13], CNT;

// 생일 맞추기
int main(){
    month[1] = month[3] = month[5] = month[7] = month[8] = month[10] = month[12] = 31;
    month[2] = 29;
    month[6] = month[4] = month[9] = month[11] = 30;

    cin >> T;
    while(T--){
        for(int i = 0; i < 10; i++){
            cin >> num[i];
        }

        for(int i = 1; i <= 12; i++){
            if(i >= 10){
                if(num[1] || num[i%10])
                    continue;
            }else{
                if(num[i])
                    continue;
            }

            for(int j = 1; j <= month[i]; j++){
                if(j < 10){
                    if(num[j])
                        continue;
                }else{
                    if(num[j/10] || num[j%10])
                        continue;
                }

                CNT++;
            }
        }

        cout << CNT << "\n";
        CNT = 0;
    }

    return 0;
}