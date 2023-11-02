#include<cstdio>
#include<algorithm>   //sort()알고리즘 사용
using namespace std;

int N, i, num[200];

int main() {
   scanf("%d", &N);
   for (i = 0; i < N; i++) {
      scanf("%d", &num[i]);
   }
   sort(num, num+N);
   int mid = N / 2;
   printf("%d", num[mid]);

   return 0;
}