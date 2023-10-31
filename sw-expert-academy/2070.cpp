#include<cstdio>
int T,i,j, numleft, numright;
char result[4];

int main(){
   scanf("%d",&T);
   for(i=1;i<=T;i++){
      scanf("%d %d", &numleft, &numright);
      if(numleft > numright)
         result[i]='>';
      else if(numleft < numright)
         result[i]='<';
      else
         result[i]='=';
   }
   for(i=1;i<=T;i++){
      printf("#%d %c\n",i, result[i]);   
   }
   return 0;
}