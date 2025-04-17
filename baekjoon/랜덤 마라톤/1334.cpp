#include <iostream>
#include <string>

using namespace std;
int N, sSize;
string s, result;

// 좌우대칭 수 비교 및 변환
void check(string tmp){
    bool checkS = false;
    int end = sSize/2, start =(sSize % 2 != 0) ? sSize/2 : sSize/2 -1;
    while(true){
        if(start < 0 || end >= sSize)
            break;

        if(tmp[start] > s[start]){
            break;
        }else{
            if(start != end)
                tmp[end]++;
            tmp[start]++;
        }
        
        if(tmp[start] > '9'){
            if(start != end)
                tmp[end] = '0';
            tmp[start] = '0';
            start--, end++;
        }

    }

    result = tmp;
}

// 다음 팰린드롬 수
int main(){
    cin >> s;
    sSize = s.size();
    // 앞자리 좌우대칭 수 만들기
    string tmp = "";
    for(int i = 0; sSize/2 > i; i++)
        tmp += s[i];
    if(sSize % 2 != 0){    // 홀 수 길이 일때
        tmp += s[sSize/2];
    }
    for(int i = sSize/2-1; i >= 0; i--)
        tmp += s[i];

    
    if(tmp > s){
        result = tmp;
    }else{
         // 9로만 이루어진 수 인지 확인
        string tmp2(sSize,'9');
        if(tmp == tmp2){
            for(int i = 0; sSize > i; i++)
                result += '0';
            result[0] = '1';
            result += '1';
        }else{
            check(tmp);
        }
    }

    cout << result << "\n";

    return 0;
}