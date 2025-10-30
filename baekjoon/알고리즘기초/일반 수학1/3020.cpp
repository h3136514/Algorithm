// 누적합
#include <iostream>
#include <vector>
#include <algorithm>

#define INF 200001
using namespace std;
int N, H, num, answer = INF, CNT;
int down[500001], up[500001];

// 개똥벌레
int main(){
    cin >> N >> H;

    for(int i = 0; i < N; i++){
        cin >> num;
        if(i % 2 == 0){
            down[num]++;
        }else{
            up[H-num+1]++;
        }
    }
    for(int i = 1; i <= H; i++){
        up[i] += up[i-1];
        down[H-i] += down[H-i+1];
    }

    for(int i = 1; i <= H; i++){
        if(up[i] + down[i] < answer){
            answer = up[i] + down[i];
            CNT = 1;
        }else if(up[i] + down[i] == answer){
            CNT++;
        }
    }
  
    cout << answer << " " << CNT << "\n";
    
    return 0;
}