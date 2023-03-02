#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
play 되는 시간에 특정 시간동안 광고를 넣어서 가장 많이 재생되는 시간이 될 수 있는 
광고의 가장 빠른 시작 시각을 구하는 문제 
-> 시간 x 명수 
 만약, 시청자들의 누적 재생시간이 가장 많은 곳이 여러 곳이라면, 그 중에서 가장 빠른 시작 시각을 return
*/
int strToTime(string time){
    int h=stoi(time.substr(0,2));
    int m=stoi(time.substr(3,2));
    int s=stoi(time.substr(6,2));
    return h*3600+m*60+s;
}
string timeToStr(int time){
    
    int h=time/3600;
    int m=(time%3600)/60;
    int s=(time%3600)%60%60;
    
    string h1="",m1="",s1="";
    if(h<10){
        h1="0"+to_string(h);
    }else if(h==0){
        h1="00";
    }else h1=to_string(h);
    
    if(m<10){
        m1="0"+to_string(m);
    }else if(m==0){
        m1="00";
    }else m1=to_string(m);
    
    if(s<10){
        s1="0"+to_string(s);
    }else if(s==0){
        s1="00";
    }else s1=to_string(s);
    
    return h1+":"+m1+":"+s1;
}
ll dp[360004]; // dp[i] 는 0~i분까지의 누적 시청자 수 (끝은 미만이라서 포함이 되지 않는다.)
string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    
    sort(logs.begin(),logs.end());
    
    vector<pair<int,int>> v;
    for(auto l : logs){
        int st=strToTime(l.substr(0,8));
        int en=strToTime(l.substr(9,8));
        v.push_back({st,en});
        dp[st]+=1;
        dp[en]-=1;
    }
    int pt=strToTime(play_time);
    int ad=strToTime(adv_time);
    
    for(int i=1;i<pt;i++){
        dp[i]+=dp[i-1];
    }
    
    for(int i=1;i<pt;i++){
        dp[i]+=dp[i-1];
    }
    
//     처음 시작하는 광고 시간을 기준으로 구함
//     ll total=0;
//     int ans=0;
//     for(int i=0;i<=pt-ad;i++){
//         ll sum=dp[i+ad-1];
//         if(i!=0) sum-=dp[i-1];
        
//         if(total<sum){
//             total=sum;
//             ans=i;
//         }
//     }
// 끝나는 광고 시간을 기준으로 구함
    
    ll mxT=dp[ad-1];
    int ans=0;
    for(int i=ad;i<=pt;i++){
        if(mxT<dp[i]-dp[i-ad]){
            mxT=dp[i]-dp[i-ad];
            ans=i-ad+1;
        }
    }
    
    answer=timeToStr(ans);
    
    
    
    return answer;
}



