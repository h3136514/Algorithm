#include<cstdio>
#include<algorithm>
using namespace std;

int T, i, j, num[10], Max[4];

int main(){
   scanf("%d", &T);
   for (i = 1; i <= T; i++) {
      for(j=0;j<10;j++)
         scanf("%d", &num[j]);
      sort(num, num + 10);
      Max[i] = num[9];
   }
   for (i = 1; i <= T; i++) {
      printf("#%d %d\n", i, Max[i]);
   }
   return 0;
}