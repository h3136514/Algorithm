#include <iostream>
#include <vector>

using namespace std;
int N, M, J, leftB = 1, rightB, gab, CNT;
vector<int> v;

// 사과 담기 게임
int main(){
    cin >> N >> M;
    cin >> J;

    v.resize(J);
    for(int i = 0; i < J; i++){
        cin >> v[i];
    }

    rightB = M;
    for(int i = 0; i < J; i++){
        if(leftB <= v[i] && v[i] <= rightB)
            continue;
        else if(rightB < v[i]){
            gab = v[i] - rightB;
            leftB += gab, rightB += gab;
            CNT += gab;
        }else{
            gab = leftB - v[i];
            leftB -= gab, rightB -= gab;
            CNT += gab;
        }
    }

    cout << CNT << "\n";

    return 0;
}

