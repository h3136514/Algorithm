#include<cstdio>
#include<cstring>
char A[1000], B[1000]; 

int main(){
    scanf("%s", &A);
    scanf("%s", &B);
    if(strlen(A) >= strlen(B))
        printf("go\n");
    else
        printf("no\n");
    return 0;
}