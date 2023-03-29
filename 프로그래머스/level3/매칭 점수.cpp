#include<bits/stdc++.h>
using namespace std;
map<string,int> base;
map<string,int> link;
map<string,double> score;
map<string,int> idx;
multimap<string,string> mmp;
bool cmp(pair<double,int> a,pair<double,int> b){
    if(a.first==b.first){
        return a.second<b.second;
    }else return a.first>b.first;
}
int getScore(string str,string word){
    string target1 = "<body>";
	string target2 = "/<body>";
	int idx1 = str.find(target1); 
    idx1 += target1.length();
	int idx2 = str.find(target2);
	str = str.substr(idx1, idx2 - idx1);
 
	string cur = "";
	int cnt = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (!(str[i]>='a' && str[i]<='z'))
		{
			if (cur == word) cnt++;
			cur = "";
		}
		else cur += str[i];
	}
	return cnt;
}
int solution(string word, vector<string> pages) {
    int answer = 0;
    vector<string> pp;
    for(auto p : pages){
        
        string newP="";
        for(auto e : p){
            newP+=tolower(e);
        }
        p=newP;
        
        // url 구하기
        string target="<meta property=\"og:url\" content=\"https://";
        int it=p.find(target);
        it+=target.size();
        string url="";
        while(p[it]!='\"') url+=p[it++];
        pp.push_back(url);
        // 기본 점수 구하기
        transform(word.begin(),word.end(),word.begin(),::tolower);
        base[url]=getScore(p,word);
        
        // 외부 링크 구하기
        target="a href=\"https://";
        while(p.find(target)!=string::npos){
            int it=p.find(target);
            it+=target.size();
            string cur="";
            while(p[it]!='\"') cur+=p[it++];
            link[url]++;
            mmp.insert({url,cur});
            p=p.substr(it);
        }
        
    }

    int x=0;
    for(int i=0;i<pp.size();i++){
        for(auto it=mmp.begin();it!=mmp.end();it++){
            if(it->first==pp[i]){

                if(!link[it->second]) continue;
                score[it->second]+=((double)base[it->first]/(double)link[it->first]);
            }
        }
        idx[pp[i]]=x++;
        score[pp[i]]+=base[pp[i]];
    }
    
    double mx=0;
    vector<pair<double,int>>v;
    for(auto it=score.begin();it!=score.end();it++){
        v.push_back({it->second,idx[it->first]});
        // if(mx<it->second){ 
        //     mx=it->second;
        //     answer=idx[it->first];
        // }
    }
    
    sort(v.begin(),v.end(),cmp);
    
    return v[0].second;
}