#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int N, i, j, ind, num, answer, score[26];// 알파벳 갯수
char c[9];   //수의 최대 길이는 8
int main(){
    scanf("%d", &N);
    for(i=0;i<N;i++){
        scanf("%s", &c);
        num=1;
        for(j=strlen(c)-1;j>=0;j--){
            ind=c[j]-'A';
            score[ind] +=num;
            num *=10;
        }
    }
    sort(score, score+26);  //맨뒤에 가장큰 값으로 정렬
    num=9;
    for(i=25;i>15;i--){
        answer +=num*score[i];
        num--;
    }
    printf("%d",answer);
    
    return 0;
}
