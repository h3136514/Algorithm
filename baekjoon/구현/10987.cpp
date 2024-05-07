#include<cstdio>
#include<cstring>
int cnt, i;
char word[101];

int main() {
    scanf("%s", &word);
    for(i=0;i<strlen(word);i++) {
        if(word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u')
            cnt++;
    }
    printf("%d\n", cnt);
    
    return 0;
}