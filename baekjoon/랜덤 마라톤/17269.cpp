// 수학, 구현
#include <iostream>
#include <string>
#include <vector>

using namespace std;
int N, M;
string A, B;
vector<int> before, after;

// 이름궁합 테스트
int nameInt(char c){
    switch (c){
        case 'C':
        case 'G':
        case 'I':
        case 'J':
        case 'L':
        case 'O':
        case 'S':
        case 'U':
        case 'V':
        case 'W':
        case 'Z':
            return 1;
        case 'B':
        case 'D':
        case 'N':
        case 'P':
        case 'Q':
        case 'R':
        case 'T':
        case 'X':
        case 'Y':
            return 2;
        case 'E':
            return 4;
        default:
            return 3;
    }
}

int main(){
    cin >> N >> M;
    cin >> A >> B;
    int maxNum = max(N, M);

    for(int i = 0; i < maxNum; i++){
        if(N > i)
            before.push_back(nameInt(A[i]));
        
        if(M > i)
            before.push_back(nameInt(B[i]));
    }

    while(true){
        for(int i = 1; i < before.size(); i++){
            int num = (before[i-1] + before[i] >= 10) ? before[i-1] + before[i] - 10 : before[i-1] + before[i];
            after.push_back(num);
        }

        if(after.size() == 2)
            break;

        before.clear();
        before = after;
        after.clear();
    }

    if(after[0] == 0)
        cout << after[1] << "%\n";
    else
        cout << after[0] << after[1] << "%\n";

    return 0;
}