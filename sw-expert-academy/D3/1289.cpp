#include<cstdio>
#include<cstring>
int T, i, j, cnt, v,s, r[11];
char c[11][50];

int main(){
    scanf("%d", &T);
    for(i=1;i<=T;i++){
        v=0; //기준
        cnt=0;
        scanf("%s",c[i]);
        for(j=0;j<strlen(c[i]);j++){
            s= c[i][j]-'0'; //정수로 변환
            if(v==s)
                continue;
            else{
                v=s;
                cnt++;
            }
        }
        r[i]=cnt;
    }
    for(i=1;i<=T;i++){
        printf("#%d %d\n", i, r[i]);
    }
    return 0;
}