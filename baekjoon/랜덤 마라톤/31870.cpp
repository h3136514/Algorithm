// 구현, 정렬
#include <iostream>

using namespace std;
int N, num[1001], tmp1[1001], tmp2[1001], CNT;

void copyNum(){
    for(int i = 0; i < N; i++){
        tmp1[i] = num[i];
        tmp2[i] = num[i];
    }
}

// 오른차순 버블정렬
int bubbleASC(){
    int cnt = 0;
    bool check = false;
    while(!check){
        check = true;
        for(int i = 1; i < N; i++){
            if(tmp1[i-1] > tmp1[i]){
                int tmp = tmp1[i-1];
                tmp1[i-1] = tmp1[i];
                tmp1[i] = tmp;

                check = false;
                cnt++;
            }
        }
    }

    return cnt;
}

// 내림차순 버블정렬
int bubbleDESC(){
    int cnt = 1;    //  배열 전체의 순서 뒤집기
    bool check = false;
    while(!check){
        check = true;
        for(int i = 1; i < N; i++){
            if(tmp2[i-1] < tmp2[i]){
                int tmp = tmp2[i-1];
                tmp2[i-1] = tmp2[i];
                tmp2[i] = tmp;

                check = false;
                cnt++;
            }
        }
    }

    return cnt;
}

// 버블버블
int main(){
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> num[i];

    copyNum();

    CNT = min(bubbleASC(), bubbleDESC());
    cout << CNT << "\n";

    return 0;
}