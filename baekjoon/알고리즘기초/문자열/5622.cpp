#include<cstdio>
#include<cstring>
char str[16]; 
int i, sum;

int main(){
    scanf("%s", &str);
    sum += strlen(str);
    for(i=0;i<strlen(str);i++){
        switch(str[i]){
            case 'A':
            case 'B':
            case 'C':
                sum +=2;
                break;
            case 'D':
            case 'E':
            case 'F':
                sum +=3;
                break;
            case 'G':
            case 'H':
            case 'I':
                sum +=4;
                break;
            case 'J':
            case 'K':
            case 'L':
                sum +=5;
                break;
            case 'M':
            case 'N':
            case 'O':
                sum +=6;
                break;
            case 'P':
            case 'Q':
            case 'R':
            case 'S':
                sum +=7;
                break;
            case 'T':
            case 'U':
            case 'V':
                sum +=8;
                break;
            case 'W':
            case 'X':
            case 'Y':
            case 'Z':
                sum +=9;
                break;

        }
    }
    printf("%d\n", sum);
    return 0;
}