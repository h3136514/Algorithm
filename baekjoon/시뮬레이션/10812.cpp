#include <iostream>

using namespace std;
int N, M, num[101], tmp[101], startIdx, endIdx, midIdx;

void copyNum(int s, int e){
    for(int i = s; i <= e; i++){
        tmp[i] = num[i];
    }
}

// 바구니 순서 바꾸기
int main(){
    cin >> N >> M;
    for(int i = 1; i <= N; i++)
        num[i] = i;
    
    for(int i = 0; i < M; i++){
        cin >> startIdx >> endIdx >> midIdx;

        copyNum(startIdx, endIdx);
        for(int j = midIdx; j <= endIdx; j++){
            num[startIdx + j - midIdx] = tmp[j];
        }
        
        for(int j = startIdx; j < midIdx; j++){
            num[j+endIdx-midIdx+1] = tmp[j];
        }
    }

    for(int i = 1; i <= N; i++){
        cout << num[i] << " ";
    }
    cout << "\n";

    return 0;
}