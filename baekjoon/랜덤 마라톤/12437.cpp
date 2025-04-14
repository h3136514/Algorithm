// 구현, 시뮬레이션
#include <iostream>

using namespace std;
int T, i, totallMonth, month, week, CNT, idx, num, sum;

// 새로운 달력 (Small)
int main(){
    cin >> T;
    for(int j = 1; j <= T; j++){
        cin >> totallMonth >> month >> week;
        CNT =  0, sum = 0, num = 0, idx = 0;
        bool check = false;
        while (true){
            for(i = 0; i < week; i++){
                if(check && idx != i){
                    continue;
                }else
                    num++;

                if(num > month){
                    if(i != 0){
                        check = true;
                        idx = i; 
                        num = 0;
                    }else
                        num = 1;
                    if(++CNT == totallMonth)
                        break;
                }else
                    check = false;
                
            }
            if(CNT == totallMonth){
                if(i != 0)
                    sum++;
                break;
            }
            
            sum++;
        }
        
        cout << "Case #" << j << ": " << sum << "\n";
    }

    return 0;
}