#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 1e6+4;
int n,k,d;
int cnt[MAX];
vector<tuple<int,int,int>> v;
ll go(int m){
	
	ll sum=0;
	for(int i=0;i<k;i++){
		int a,b,c;
		tie(a,b,c)=v[i];
		
		ll mn=min(m,b);
		if(mn>=a) sum+=(mn-a)/c+1;
	}
	
	return sum;
	
}
int main(){
	
	ios::sync_with_stdio(0);cin.tie(0);
	
	cin >> n >> k >> d;
	
	for(int i=0;i<k;i++){
		int a,b,c;
		cin >> a >> b >> c;
		
		v.push_back(make_tuple(a,b,c));
		
	}
	
	sort(v.begin(),v.end());
	
	ll l=0,r=n;
	
	int ans=0;
	while(l<=r){
		ll m=(l+r)>>1;
		
		
		if(go(m)>=d){
			r=m-1;
			ans=m;
			
		}else l=m+1;
	}
	
	cout<<ans;
}

/*#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e6+4;
int n,k,d;
ll sum[MAX],cnt[MAX];
vector<int> v;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	
	cin >> n >> k >> d;

	for(int i=0;i<k;i++){
		int a,b,c;
		cin >> a >> b >> c;
		
		for(int i=a;i<=b;i+=c){
			cnt[i]++;
		}
		
	}
	
	int m=0;
	for(int i=1;i<=n;i++){
		if(cnt[i]){
			sum[i]=cnt[i];
			v.push_back(i);
		}
	}
	
	for(int i=1;i<=n;i++){
		sum[i]+=sum[i-1];
	}
	
	
	ll l=0;
	ll r=v.size()-1;	
	
	int ans=0;
	while(l<=r){
		ll m=(l+r)>>1;
		
		ll k=v[m];
		
		if(sum[k]>d) r=m-1;
		else if(sum[k]==d) {
			ans=k;
			break;
		}
		else l=m+1;
	}
		
	if(!ans) ans=v[l];
	
	cout<<ans<<endl;
	
}*/
