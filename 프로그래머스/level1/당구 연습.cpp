#include<bits/stdc++.h>
using namespace std;
/*
한 좌표에서 네변의 정사각형에 대칭인 점을 찾음 
그 점과 맞춰야 하는 공의 길이를 다 구하고 최솟값을 구하면 됨
*/
vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;
    
    vector<pair<int,int>> vp;
    vp.push_back({-startX,startY});
    vp.push_back({startX,-startY});
    vp.push_back({startX,n+abs(n-startY)});
    vp.push_back({m+abs(m-startX),startY});
    
    for(auto b : balls){
        int nx=b[0];
        int ny=b[1];
        
        int ans=INT_MAX;
        for(auto v : vp){
            int x=v.first;
            int y=v.second;
            
            if(nx==startX){
                if((ny>startY && y>startY)||(ny<startY && y<startY)) continue;
                
            }
            
            if(ny==startY){
                if((nx>startX && x>startX) || (nx<startX && x<startX)) continue;
            }
            
            
            ans=min(ans,(int)(pow(x-nx,2)+pow(y-ny,2)));
        }
        answer.push_back(ans);
    }
    
    return answer;
} 