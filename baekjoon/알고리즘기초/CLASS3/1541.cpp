#include<cstdio>
#include<cstring>
#include<cstdlib>   // atoi() 사용
using namespace std;
char input[51], num[5];
int i, j, sum, isMinus, cnt;

int main() {
    scanf("%s", &input);

    for(i=0;i<=strlen(input);i++) {
        if(input[i] == '-' || input[i] == '+' || i == strlen(input)){
            if(isMinus){
                sum -= atoi(num); //문자열 -> 정수
            }else {
                sum += atoi(num); //문자열 -> 정수
            }
            //문자열 초기화
            for(j=0;j<5;j++)
                num[j] ='\0';
            cnt = 0;

        }else{
            num[cnt++] =input[i];
        }

        if(input[i] == '-')
            isMinus = 1;  
    }
    printf("%d\n", sum);
    return 0;
}