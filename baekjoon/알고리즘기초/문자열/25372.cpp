#include<cstdio>
#include<cstring>
int i, N;
char str[1001]; 

int main(){
    scanf("%d", &N);
    for(i=0;i<N;i++){
        scanf("%s", &str);
        if(strlen(str)>= 6 && strlen(str)<= 9){
            printf("yes\n");
        } else
            printf("no\n");
    }
    return 0;
}