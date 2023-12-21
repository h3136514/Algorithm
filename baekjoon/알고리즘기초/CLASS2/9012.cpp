#include<cstdio>
#include<cstring>
int T, i, j, r, l, len;
char vps[51];
bool check;
int main(){
    scanf("%d", &T);
    for(i=0;i<T;i++){
        scanf("%s", &vps);
        len = strlen(vps);
        r=0;
        l=0;
        check = true;
        for(j=0;j<len;j++){
            if(vps[j]=='(')
                l++;
            else  if(vps[j]==')')
                r++;
            if(l < r){
                check = false;
                break;
            }
        }
        if( check &&(l==r))
            printf("YES\n");
        else
            printf("NO\n");

    }
    return 0;
}