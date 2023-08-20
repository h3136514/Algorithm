#include<cstdio>
long long A,B,C;
int n,m,k,i;
long long input[1000001],tree[4000004];

long long init(int node,int s, int  e){
	if(s==e)
		return tree[node]=input[s];
	else
		return tree[node]=init(node*2, s, (s+e)/2) + init(node*2+1, (s+e)/2+1, e);	
	
}
void update(int  p,int s, int e, long long target, long long v){
	if(target<s || target>e)
		return;
	tree[p] +=v;
	if(s != e)
	{
	update(p*2, s, (s+e)/2, target,v);
	update(p*2+1, (s+e)/2+1, e, target,v);
	}
	
}

long long sum(int p, int  s, int  e ,int  sp, int ep){
	if(ep < s || sp > e)
		return 0;
		
	if(sp<=s && e<=ep)
		return tree[p];
		
	return sum(p*2, s, (s+e)/2, sp, ep) + sum(p*2+1,(s+e)/2+1, e, sp, ep);
	
}

int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=n;i++)
		scanf("%lld",&input[i]);	
		
	init(1,1,n);
		
	for(i=0;i<m+k;i++){
		scanf("%lld%lld%lld",&A,&B,&C);
		if(A==1){
			long long temp= C-input[B];
			input[B] =C;
			update(1,1,n,B,temp);		
		}
		else{
			printf("%lld\n", sum(1,1,n,B,C));
		}
		
	}
	return 0;
} 
