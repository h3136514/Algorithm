#include<cstdio>
#include<cstring>
int T, i, cnt, sum;
char c[80];

int main(){
    scanf("%d", &T);
    while(T--){
        sum=0;
        cnt=1;
        scanf("%s", &c);
        int len =strlen(c);
        for(i=0;i<len;i++){
            if(c[i]=='O')
                sum += cnt++;
            else{
                cnt=1;
                continue;
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}