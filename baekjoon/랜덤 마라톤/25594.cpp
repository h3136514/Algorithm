// 구현, 문자열, 부르트포스
#include <iostream>
#include <string>
using namespace std;
string str, result;

bool HG(string s){
    int idx = 0;
    while(true){
        if(s.size() <= idx)
            return true;

        if(s[idx] == 'a'){
           if(s.substr(idx, 5) == "aespa"){
            idx += 5;
            result += 'a';
            continue;
           }
        }else if(s[idx]== 'b'){
           if(s.substr(idx, 8) == "baekjoon"){
            idx += 8;
            result += 'b';
            continue;
           }
        }else if(s[idx] == 'c'){
           if(s.substr(idx, 3) == "cau"){
            idx += 3;
            result += 'c';
            continue;
           }
        }else if(s[idx] == 'd'){
           if(s.substr(idx, 5) == "debug"){
            idx += 5;
            result += 'd';
            continue;
           }
        }else if(s[idx] == 'e'){
           if(s.substr(idx, 4) == "edge"){
            idx += 4;
            result += 'e';
            continue;
           }
        }else if(s[idx] == 'f'){
           if(s.substr(idx, 7) == "firefox"){
            idx += 7;
            result += 'f';
            continue;
           }
        }else if(s[idx] == 'g'){
           if(s.substr(idx, 6) == "golang"){
            idx += 6;
            result += 'g';
            continue;
           }
        }else if(s[idx] == 'h'){
           if(s.substr(idx, 7) == "haegang"){
            idx += 7;
            result += 'h';
            continue;
           }
        }else if(s[idx] == 'i'){
           if(s.substr(idx, 2) == "iu"){
            idx += 2;
            result += 'i';
            continue;
           }
        }else if(s[idx] == 'j'){
           if(s.substr(idx, 4) == "java"){
            idx += 4;
            result += 'j';
            continue;
           }
        }else if(s[idx] == 'k'){
           if(s.substr(idx, 6) == "kotlin"){
            idx += 6;
            result += 'k';
            continue;
           }
        }else if(s[idx] == 'l'){
           if(s.substr(idx, 3) == "lol"){
            idx += 3;
            result += 'l';
            continue;
           }
        }else if(s[idx] == 'm'){
           if(s.substr(idx, 4) == "mips"){
            idx += 4;
            result += 'm';
            continue;
           }
        }else if(s[idx] == 'n'){
           if(s.substr(idx, 4) == "null"){
            idx += 4;
            result += 'n';
            continue;
           }
        }else if(s[idx] == 'o'){
           if(s.substr(idx, 2) == "os"){
            idx += 2;
            result += 'o';
            continue;
           }
        }else if(s[idx] == 'p'){
           if(s.substr(idx, 6) == "python"){
            idx += 6;
            result += 'p';
            continue;
           }
        }else if(s[idx] == 'q'){
           if(s.substr(idx, 5) == "query"){
            idx += 5;
            result += 'q';
            continue;
           }
        }else if(s[idx]== 'r'){
           if(s.substr(idx, 4) == "roka"){
            idx += 4;
            result += 'r';
            continue;
           }
        }else if(s[idx] == 's'){
           if(s.substr(idx, 8) == "solvedac"){
            idx += 8;
            result += 's';
            continue;
           }
        }else if(s[idx] == 't'){
           if(s.substr(idx, 3) == "tod"){
            idx += 3;
            result += 't';
            continue;
           }
        }else if(s[idx] == 'u'){
           if(s.substr(idx, 4) == "unix"){
            idx += 4;
            result += 'u';
            continue;
           }
        }else if(s[idx] == 'v'){
           if(s.substr(idx, 5) == "virus"){
            idx += 5;
            result += 'v';
            continue;
           }
        }else if(s[idx] == 'w'){
           if(s.substr(idx, 5) == "whale"){
            idx += 5;
            result += 'w';
            continue;
           }
        }else if(s[idx] == 'x'){
           if(s.substr(idx, 5) == "xcode"){
            idx += 5;
            result += 'x';
            continue;
           }
        }else if(s[idx] == 'y'){
           if(s.substr(idx, 5) == "yahoo"){
            idx += 5;
            result += 'y';
            continue;
           }
        }else if(s[idx] == 'z'){
           if(s.substr(idx, 5) == "zebra"){
            idx += 5;
            result += 'z';
            continue;
           }
        }

        return false;
    }
}

// HG 음성기호
int main(){
    cin >> str;

    if(HG(str)){
        cout << "It's HG!\n";
        cout << result << "\n";
    }else
        cout << "ERROR!\n";

    return 0;
}