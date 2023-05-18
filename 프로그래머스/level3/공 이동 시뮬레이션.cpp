#include<bits/stdc++.h>

using namespace std;
/*
O(n*m);
역으로 x,y에서 역방향으로 출발 
*/
long long solution(int n, int m, int x, int y, vector<vector<int>> queries) {
    long long answer = 0;
    
    reverse(queries.begin(),queries.end());
    
    long long x1=y,x2=y,y1=x,y2=x;
    
    for(auto& q : queries){
        if(q[0]==0){ // -> 오른쪽 방향 
            
            if(x1) x1+=q[1];
            x2+=q[1];
            if(x2>=m) x2=m-1;
            
        }else if(q[0]==1){  // <- 왼쪽
            x1-=q[1];
            if(x1<0) x1=0;
            if(x2!=m-1) x2-=q[1];
        }else if(q[0]==2){  // 아래
            if(y1) y1+=q[1];
            y2+=q[1];
            if(y2>=n) y2=n-1;
        }else{ // 위
            y1-=q[1];
            if(y1<0) y1=0;
            if(y2!=n-1) y2-=q[1];
        }
        if(x2<0 || x1>=m || y2<0 || y1>=n){
            
            return answer;
        }
        // cout<<x1<<' '<<x2<<' '<<y1<<' '<<y2<<endl;
        
    }
    
    // cout<<x1<<' '<<y1<<' '<<x2<<' '<<y2<<endl;
    answer=(y2-y1+1)*(x2-x1+1);
    
    return answer;
}