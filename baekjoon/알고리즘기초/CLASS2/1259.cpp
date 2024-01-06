#include<cstdio>
#include<cstring>
char text[100000];
int mid, len;
bool check;

int main(){
    while(true){
        scanf("%s", &text);
        if(!strcmp(text, "0"))
            break;
        len=strlen(text);
        mid=len/2;
        check= true;
        for(int i=0;i<mid;i++){
            if(text[i] != text[len-1-i]){
                check=false;
                break;
            }
        }
        
        if(check)
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}