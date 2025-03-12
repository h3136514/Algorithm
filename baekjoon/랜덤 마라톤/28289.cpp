// 구현
#include <iostream>

using namespace std;
int P, G, C, N, num[4];

// 과 조사하기
int main(){
    cin >> P;
    for(int i = 0; i < P; i++){
        cin >> G >> C >> N;
        if(G == 1)
            num[3]++;
        else{
            if(C == 1 || C == 2)
                num[0]++;
            else if(C == 3)
                num[1]++;
            else
                num[2]++;
        }
    }

    for(int i = 0; i < 4; i++){
        cout << num[i] << "\n";
    }

    return 0;
}