#include<cstdio>
#include<cstring>
int T, N, i, j, cnt, ind, len,result[11];
char c[11][10],s[11][1000];

int main(){
    T=10;
    for(i=1;i<=10;i++){
        cnt=0;
        ind=0;
        scanf("%d", &N);
        scanf("%s",c[i]);
        scanf("%s",s[i]);
        len=strlen(c[i]);
        for(j=0;j<strlen(s[i]);j++){
            if(c[i][ind]==s[i][j])
                ind++;
            else{
                if(c[i][0]==s[i][j])//시작부분이 될수 있으므로
                    ind=1;
                else
                    ind=0;
            }
            if(ind==len){
                result[i]++;
                ind=0;
            }
        }
    }
    for(i=1;i<=T;i++){
        printf("#%d %d\n",i ,result[i]);
    }
    return 0;
}