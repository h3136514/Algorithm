#include<cstdio>
#include<vector>
using namespace std;
vector <int> v;
int p, q, i;

int main(){
    scanf("%d %d", &p, &q);
    for(i=1;i<=p;i++){
        if(p%i == 0)
            v.push_back(i);
    }
    if(v.size() < q)
        printf("0\n");
    else
        printf("%d\n", v[q-1]);
    return 0;
}