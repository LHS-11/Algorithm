#include <string>
#include <vector>
using namespace std;
int vis[54][54];
vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    int x=0,y=0;
    
    for(int i=0;i<park.size();i++){
        for(int j=0;j<park[i].size();j++){
            if(park[i][j]=='S'){
                x=j;
                y=i;
            }
        }
    }
    
    int xsz=park[0].size();
    int ysz=park.size();
    for(auto r : routes){
        auto cmd=r[0];
        auto cnt=r[2]-'0';
        int flag=0;
        if(cmd=='N'){
            for(int i=y;i>=y-cnt;i--){
                
                if(i<0 || park[i][x]=='X') {
                    flag=1;
                    break;
                }
            }
            if(!flag) y-=cnt;
            
        }else if(cmd=='S'){
            for(int i=y;i<=y+cnt;i++){
                if(i>=ysz || park[i][x]=='X') {
                    flag=1;
                    break;
                }
            }
            if(!flag) y+=cnt;
            
        }else if(cmd=='W'){
            for(int i=x;i>=x-cnt;i--){
                if(i<0 || park[y][i]=='X') {
                    flag=1;
                    break;
                }
            }
            if(!flag) x-=cnt;
            
        }else{
            for(int i=x;i<=x+cnt;i++){
                if(i >=xsz  || park[y][i]=='X') {
                    flag=1;
                    break;
                }
            }
            if(!flag) x+=cnt;
            
        }
        
    }
    
    return {y,x};
}