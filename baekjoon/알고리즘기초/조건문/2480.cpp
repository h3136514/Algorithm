#include<cstdio>
int a, b, c, max, award;

int main(){
    scanf("%d %d %d", &a, &b, &c);
    if(a==b&&b==c)
        award =10000 + a*1000;
    else if(a==b)
        award =1000 +a*100;
    else if(b==c)
        award =1000 +b*100;
    else if(a==c)
        award =1000 +a*100;
    else{
        if(a<c)
            max =c<b?b:c;
        else
            max =a<b?b:a;
        award =max*100;
    }
    printf("%d", award);

    return 0;
}