#include<bits/stdc++.h>
using namespace std;
string s;
int n,ans=INT_MAX,ch[26];
vector<pair<int,string>> v;
void go(int cnt,int sum){
	if(cnt==n){
		
		int flag=0;
		int chh[26];
		copy(ch,ch+26,chh);
	
		for(int i=0;i<s.size();i++){
			if(chh[s[i]-'A']){
				chh[s[i]-'A']--;
			}else {
				flag=1;
				break;
			}
		}
		
		if(!flag) {	
			ans=min(ans,sum);
		}
		return;
	}
	
	string st=v[cnt].second;
	for(int i=0;i<st.size();i++){
		ch[st[i]-'A']++;
	}
	go(cnt+1,sum+v[cnt].first);
	for(int i=0;i<st.size();i++){
		ch[st[i]-'A']--;
	}
	go(cnt+1,sum);

}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	
	 cin >> s >> n;
	 
	 
	 for(int i=0;i<n;i++){
	 	int a; string b;
	 	cin >> a>>b;
	 	v.push_back(make_pair(a,b));
	 }
	 
	 go(0,0);
	 
	 cout<<ans;
}
/*#include<bits/stdc++.h>
using namespace std;
string t;
int n,vis[18],ans=INT_MAX;
vector<int> v;
int vvv[18][14];

// 완탐으로 모든 순열을 구해서 최솟값 찾기  

void dfs(int idx,int sz,vector<pair<int,string>>& vt){
	
	
	if(sz==v.size()){

		memset(vvv,0,sizeof(vvv));
		int vv[t.size()];
		fill(vv,vv+t.size(),0);
		
		int sum=0;
		for(auto& e : v){
			string str=vt[e].second;
			int price=vt[e].first;

			for(int j=0;j<str.size();j++){ // AAC
				for(int i=0;i<t.size();i++){ // AAA
					if(vv[i] || vvv[e][j]) continue;
					if(t[i]==str[j]) {
						vv[i]=1;
						vvv[e][j]=1;
					}
					
				}	
			}
			sum+=price;
			
		}
		
		bool flag=false;
		for(int i=0;i<t.size();i++){
			if(!vv[i]){
				flag=true;
				break;
			}
		}
		
		if(!flag){
			ans=min(ans,sum);
		}
		
		return;
	}
	
	for(int i=idx;i<n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		v.push_back(i);
		dfs(i,sz,vt);
		v.pop_back();
		vis[i]=0;
		
	}
	
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	
	cin >> t >> n;
	
	vector<pair<int,string>>vt(n);
	for(int i=0;i<n;i++){
		cin >> vt[i].first>> vt[i].second;
		
	}
	
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		dfs(0,i,vt);
	}
	
	if(ans==INT_MAX) cout<<-1;
	else cout<<ans;
}
*/
