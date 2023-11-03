#include<cstdio>
int T, i, word[11], p1, p2, count, point=-1;
char line[11][30];
int main(){
    scanf("%d", &T);
    for(i=1;i<=T;i++){
        scanf("%s", &line[i]);
        p1=0;
        p2=0;
        count=0;
        point=-1;
        while(true){
            p2++;
            if(p1==point || p2 >29)
                break;
            if(line[i][p1] == line[i][p2])
            {   if(point == -1 )    //처음으로 똑같은부분 기억
                    point =p2;  
                count++;
                p1++;
                if(word[i] < count)
                    word[i] =count;
            }
            else{
                point = -1;
                count=0;
                p1=0;
            }
        }
    }
    for(i=1;i<=T;i++){
        printf("#%d %d\n",i, word[i]);
    }
   
    return 0;
}