#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, maxSum;
vector<int> num;

// 일이 커졌어
int main(){
    cin >> N;

    num.resize(N);
    int oddN = N/2 +1;
    int evenN = oddN-1;
    for(int i = 0; i < N; i++){
        if(i % 2 == 0){
            num[i] = oddN++;
        }else
            num[i] = evenN--;
    }


    for(int i = 0; i < N; i++){
        cout << num[i] << " ";
    }
    cout << "\n";

    return 0;
}