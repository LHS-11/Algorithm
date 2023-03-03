#include<bits/stdc++.h>
using namespace std;
// 최대,최소 구해서 좌표 설정 
vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    
    int mnX=INT_MAX;
    int mnY=INT_MAX;
    int mxX=0;
    int mxY=0;
    for(int i=0;i<wallpaper.size();i++){
        for(int j=0;j<wallpaper[i].size();j++){
            if(wallpaper[i][j]=='#'){
                mnX=min(mnX,j);
                mnY=min(mnY,i);
                
                mxX=max(mxX,j);
                mxY=max(mxY,i);
            }
        }
    }
    
    answer={mnY,mnX,mxY+1,mxX+1};
    return answer;
}