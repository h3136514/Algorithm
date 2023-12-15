#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int cnt, i, length;
bool check = true;
char c[1000001];

int main(){
    cin.getline(c, 1000001, '\n');  //공백이 낀 문자열을 입력받기
    length = strlen(c);
    cnt=0;
    for(i=0;i<length;i++){
        if(c[i]!=' '&& check){  //처음 알파벳이 나오면 +1
            cnt++;  
            check= false;
        }else if(c[i] ==' ')
            check =true;
            
    }
    printf("%d", cnt);

    return 0;
}