#include <iostream>

using namespace std;
int num[10001];

// 생성자 수열들 확인
void dfs(int n){
    int sum = n;
    while(n > 0){
        int value = n%10;
        sum += value;
        n /= 10;
    }
    if(sum > 10000 || num[sum])    // 10000보다 크거나 이미 방문한 생성자 패턴
        return;
    
    num[sum] = 1;   // 생성자 있음 표시
    dfs(sum);
}

// 셀프 넘버(생성자가 없는 숫자를 셀프 넘버, 양의 정수 n에 대해서 n과 n의 각 자리수를 더해서 새로운 숫자b가 생성될때 이때의 n은 b의 생성자이다.)
int main(){
    for(int i = 1; i <= 10000; i++)
        dfs(i);
    
    for(int i = 1; i <= 10000; i++){
        if(!num[i])
            cout << i << "\n";
    }

    return 0;
}