#include <iostream>

#define INF 1987654321
using namespace std;
int N, S, startIdx, endIdx, sum, CNT = INF, num[100001]; 

// 부분합
int main(){
    cin >> N >> S;
    for(int i = 0; i < N; i++)
        cin >> num[i];
    
    sum = num[0];
    while(startIdx <= endIdx && endIdx < N){
        if(sum >= S)
            CNT = min(CNT, endIdx-startIdx +1);
        
        if(sum < S){
            endIdx++;
            sum += num[endIdx];
        }else{
            sum -= num[startIdx];
            startIdx++;
        }
    }
    

    if(CNT == INF)
        cout << "0\n";
    else
        cout << CNT << "\n";

    return 0;
}