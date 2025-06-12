#include <iostream>

using namespace std;
int N, line, people[11];

// 한 줄로 서기
int main(){
    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> line;
        int idx = 0;
        for(int j = 0; j < N; j++){
            if(people[j])
                continue;
            if(idx == line){
                people[j] = i+1;
                break;
            }
            idx++;

        }
    }

    for(int i = 0; i < N; i++){
        cout << people[i] << " ";
    }
    cout << "\n";

    return 0;
}