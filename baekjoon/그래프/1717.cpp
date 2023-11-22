#include<cstdio>

int i,j,n,m,num[1000001],a,b,c,broot,croot;

int find(int a){
	if(num[a]==a) return a;
	else return num[a]=find(num[a]);
}

void union_s(int b, int c){
	broot =find(b);
	croot =find(c);
	if (broot == croot) return;
	num[broot]=croot;
	
	
}

int main(){
	scanf("%d%d",&n,&m);
	for(i=0;i<=n;i++){
		num[i]=i;
}
for(i=0;i<m;i++){
	scanf("%d%d%d",&a,&b,&c);
	if(a==0){
		union_s(b,c);
	}else{
		if (find(b) == find(c))
			printf("YES\n");
		else
			printf("NO\n");
		}
	}
	return 0;
}