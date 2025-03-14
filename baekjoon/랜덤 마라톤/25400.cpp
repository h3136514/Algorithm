// 그리디
#include <iostream>

using namespace std;
int N, num[250001], CNT, result;

// 제자리
int main(){
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> num[i];
    
    CNT = 1;
    for(int i = 0; i < N; i++){
        if(num[i] == CNT)
            CNT++;
    }
    
    if(CNT != 1)
        result =  N - CNT + 1;
    else
        result = N;

    cout << result << "\n";

    return 0;
}