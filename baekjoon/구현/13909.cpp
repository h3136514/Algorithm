#include <iostream>

using namespace std;
int N, count = 0;

// 창문 닫기
int main(){
    cin >> N;
    
    for(int i = 1; i * i <= N; i++)
        count++;
    
     cout << count;
}