#include <iostream>
#include <vector>

using namespace std;
vector<int> v;

// 출력
void pri(){
    for(int i = 0; i < 5; i++){
        cout << v[i] << " ";
    }
    cout << "\n";
}

// 순서 확인
bool check(){
    for(int i = 0; i < 4; i++){
        if(v[i] > v[i+1])
            return false;
    }

    return true;
}

// 나무 조각
int main(){
    v.resize(5);
    for(int i = 0; i < 5; i++){
        cin >> v[i];
    }

    while(true){
        for(int i = 0; i < 4; i++){
            if(v[i] > v[i+1]){
                int tmp = v[i];
                v[i] = v[i+1];
                v[i+1] = tmp;

                pri();
            }
        }

        if(check())
            break;
    }

    return 0;
}