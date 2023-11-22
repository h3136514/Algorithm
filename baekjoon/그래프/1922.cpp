#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

vector<pair<int, pair<int, int>>> edge;
int i,j,n,m,num[1000001],answer,broot,croot,a,b,c;

int find(int a){
    if(num[a]==a)
        return a;
    else
        return num[a]=find(num[a]);
}

void union_s(int b, int c){
    broot = find(b);
    croot = find(c);
    num[croot]=broot;
}

int main(){
    scanf("%d%d",&n,&m);
    //초기화
	for(i=1;i<=m;i++){
		num[i]=i;
    }
    for(i=0;i<m;i++){
        scanf("%d%d%d", &a, &b, &c);
        edge.push_back({c, {a, b}});      
    }
    sort(edge.begin(), edge.end()); //오른차순 정렬
    for(i=0;i<n-1;i++){
        while(find(edge[j].second.first) == find(edge[j].second.second))//싸이클이 안생기게 넘어감
            j++;
        answer += edge[j].first;
        union_s(edge[j].second.first, edge[j].second.second);
        j++;
    }
    printf("%d",answer);
    return 0;
}