#include <iostream>
#include <vector>

using namespace std;
int N, Y, M;
vector<int> v;

// 핸드폰 요금
int main(){
    cin >> N;
    
    v.resize(N);
    for(int i = 0; i < N; i++){
        cin >> v[i];
    }

    for(int i = 0; i < N; i++){
        Y += (v[i]/30)*10;
        Y += 10;
        
        M += (v[i]/60)*15;
        M += 15;
    }

    if(Y > M){
        cout << "M " << M  << "\n";
    }else if(Y < M){
        cout << "Y " << Y  << "\n";
    }else{
        cout << "Y M " << M  << "\n";
    }

    return 0;
}