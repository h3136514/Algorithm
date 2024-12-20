// 구현
#include <iostream>
#include <string>

using namespace std;
int L, R, M;
string str;

// 타자 연습
int main(){
    getline(cin, str);

    for(int i = 0; i < str.size(); i++){
        if(str[i] == ' '){
            M++;
            continue;
        }
        
        // Shift키 사용
        if(str[i] < 97){
            str[i] +=32;
            M++;
        }

        switch(str[i])
        {
            case 'q':
            case 'w':
            case 'e':
            case 'r':
            case 't':
            case 'y':
            case 'a':
            case 's':
            case 'd':
            case 'f':
            case 'g':
            case 'z':
            case 'x':
            case 'c':
            case 'v':
            case 'b':
                L++;
                break;
            default:
                R++;
                break;
        }
    }

    while(M > 0){
        if(L <= R)
            L++;
        else
            R++;
        
        M--;
    }

    cout << L << " " << R <<"\n";

    return 0;
}