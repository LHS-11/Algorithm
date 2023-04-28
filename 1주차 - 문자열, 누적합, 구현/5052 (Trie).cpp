#include<bits/stdc++.h>
using namespace std;
int t,n;
struct Trie{
	
	bool isFinished;
	Trie *Node[10]; // 자식 노드에 접근하기 위해 포인터 배열 사용  
	
	Trie(){ // 생성자  
		isFinished=false;
		for(int i=0;i<10;i++) Node[i]=NULL;
	} 
	
	void insert(char *str){ // *str => 문자 , str => 주소값 
		if(*str=='\0'){
			isFinished=true;
			return;
		}
		
		int now=*str-'0';
		if(Node[now]==NULL) Node[now]=new Trie();
		Node[now]->insert(str+1); // 자식 노드에서 재귀적으로 삽입하기 위해서 주소값 + 1   
	}
	
	bool find(char *str){
		if(*str=='\0') return false;
		
		if(isFinished==true) return true;
		
		int now=*str-'0';
		if(Node[now]==NULL) return false;
		return Node[now]->find(str+1);
	}
	
	void insert1(string str){
		if(str.empty()){
			isFinished=true;
			return;	
		}
		
		int now=str[0]-'0';
		if(Node[now]==NULL) Node[now]=new Trie();
		Node[now]->insert1(str.substr(1));
	}
	bool find1(string str){
		if(str.empty()) return false;
		
		if(isFinished) return true;
		
		int now=str[0]-'0';
		if(Node[now]==NULL) return false;
		return Node[now]->find1(str.substr(1));
	}
};
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	
	cin >> t;
	char input[10000][11];
	
	while(t--){
		cin >> n;
		vector<string> str(n);
		
		Trie *Root=new Trie();
		for(int i=0;i<n;i++) {
			cin >> str[i];
			Root->insert1(str[i]);
//			cin >> input[i];
//			Root->insert(input[i]);	
		}
		
		int flag=0;
		for(int i=0;i<n;i++){
//			if(Root->find(input[i])){
			if(Root->find1(str[i])){
				cout<<"NO\n";
				flag=1;
				break;
			}
		}
		if(!flag) cout<<"YES\n";
	}
}

