// 구현, 자료구조
#include <iostream>
#include <string>

using namespace std;
string puzzle;
bool result;
int num[9], CNT = 1;

// 각 블록의 왼쪽에 올 수 있는 블록인지 확인
bool puzzleCheck(){
    for(int i = 1; i < puzzle.size(); i++){
        if(puzzle[i] == '1'){
            return false;
        }else if(puzzle[i] == '2'){
            if(i != puzzle.size()-1 ||(puzzle[i-1] != '4' && puzzle[i-1] != '6'))
                return false;
        }else if(puzzle[i] == '3'){
            if(puzzle[i-1] != '4' && puzzle[i-1] != '6')
                return false;
        }else if(puzzle[i] == '4'){
            if(puzzle[i-1] != '1' && puzzle[i-1] != '3')
                return false;
        }else if(puzzle[i] == '5'){
            num[5]++;
            if(puzzle[i-1] != '3' && puzzle[i-1] != '1')
                return false;
        }else if(puzzle[i] == '6'){
            num[6]++;
            if(puzzle[i-1] != '8')
                return false;
        }else if(puzzle[i] == '7'){
            if(puzzle[i-1] != '8')
                return false;
        }else if(puzzle[i] == '8'){
            if(puzzle[i-1] != '5' && puzzle[i-1] != '7')
                return false;
        }
    }

    return true;
}

// 나무 블록
int main(){
    while(true){
        cin >> puzzle;
        if(puzzle == "0")
            break;
        
        if(puzzle.size() == 1 || puzzle[0] != '1' || puzzle[puzzle.size()-1] != '2'){
            cout << CNT++ << ". NOT\n";
            continue;
        }
        num[5] = 0;
        num[6] = 0;
        result = puzzleCheck();

        if(result && num[5] == num[6])
            cout << CNT++ << ". VALID\n";
        else
            cout << CNT++ << ". NOT\n";
    }

    return 0;
}