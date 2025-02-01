// 수학, 소수 판정 + 에라토스테네스의 체(안사용)
#include <iostream>

using namespace std;
int T, N, num[1000001];

// 초기화
void init(){
    for(int i = 2; i <= N; i++)
        num[i] = 0;
}

// 소인수 출력
void printNum(){
    for(int i = 2; i <= N; i++){
        if(!num[i])
            continue;
        
        cout << i << " " << num[i] << "\n";
    }
}

// 수 복원하기
int main(){
    cin >> T;
    while(T--){
        cin >> N;
        int target = N;
        for(int i = 2; i <= N; i++){
            if(target < i)
                break;
            
            while(true){
                if(target%i != 0)
                    break;
                
                num[i]++;
                target /= i;
            }
        }

        printNum();

        init();
    }

    return 0;
}