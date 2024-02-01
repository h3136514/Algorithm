#include<cstdio>
#include<cstring>
int i, j, N, cnt, check[26];
char str[101]; 
void init(){
    for(j=0;j<26;j++)
        check[j]=0;
}

int main(){
    scanf("%d", &N);
    for(i=0;i<N;i++){
        scanf("%s", &str);
        init();
        for(j=0;j<strlen(str);j++){
            int num=str[j] - 97;
            if(check[num]){
                if(str[j-1] - 97 == num)
                    continue;
                cnt--;
                break;
            }else
                check[num] = 1;
        }
        cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}