#include <iostream>

using namespace std;
int N, num;

// 배수 찾기
int main(){
    cin >> N;
    while(true){
        cin >> num;
        if(num == 0)
            break;

        if(num%N == 0){
            cout << num <<" is a multiple of " << N << "." <<"\n";
        }else{
            cout << num <<" is NOT a multiple of " << N  << "." <<"\n";
        }
    }

    return 0;
}
