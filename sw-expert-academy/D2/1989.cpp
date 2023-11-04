#include<cstdio>
#include<cstring>
int T, i, j, len, mid, result[11]={1,1,1,1,1,1,1,1,1,1,1};
char c[11][10];

int main(){
    scanf("%d", &T);
    for(i=1;i<=T;i++){
        scanf("%s",&c[i]);
        len = strlen(c[i]);
        if(len%2 == 0) //길이가 짝수일때
        {
            mid = len/2;
            for(j=0;j<mid;j++)
            {
                if(c[i][j] != c[i][len-j-1])
                {
                    result[i] = 0;
                    break;
                }
            }
        }
        else    //길이가 홀수일때
        {
            mid = len/2;
            for(j=0;j<=mid;j++)
            {
                if(c[i][j] != c[i][len-j-1])
                {
                    result[i] = 0;
                    break;
                }
            }
        }
    }
    for(i=1;i<=T;i++){
        printf("#%d %d\n",i, result[i]);
    }
    
    return 0;
}