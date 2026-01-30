#include <iostream>
#include <string>

using namespace std;
int N;
string K;

// 홀수일까 짝수일까
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> K;
        int num = int(K[K.size()-1]);
        if(num%2 == 0){
            cout << "even\n";
        }else{
            cout << "odd\n";
        }
    }

    return 0;
}