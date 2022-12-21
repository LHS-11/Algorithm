#include<bits/stdc++.h>
using namespace std;
int vis[31][31];
bool check(vector<string>& mp) {
    int flag1 = 0;
    for (int i = 0; i < mp.size() - 1; i++) {
        for (int j = 0; j < mp[i].size() - 1; j++) {

            int flag = 0;
            char c = mp[i][j];
            if (!(c >= 'A' && c <= 'Z')) {
                c = '3';
            }

            for (int y = i; y <= i + 1; y++) {
                for (int x = j; x <= j + 1; x++) {
                    if (mp[y][x] != c) {
                        flag = 1;
                    }
                }
            }

            if (!flag) {
                flag1 = 1;
                for (int y = i; y <= i + 1; y++) {
                    for (int x = j; x <= j + 1; x++) {
                        vis[y][x] = 1;
                    }
                }
            }

        }
    }
    return flag1;
}
int solution(int m, int n, vector<string> board) {
    int answer = 0;
    int sz = board.size();

    // 오른쪽으로 회전
    vector<string> mp;
    for (int i = 0; i < board[0].size(); i++) {
        string s = "";
        for (int j = board.size() - 1; j >= 0; j--) {
            s += board[j][i];
        }
        mp.push_back(s);
    }

    while (check(mp)) {

        for (int i = 0; i < mp.size(); i++) {
            for (int j = 0; j < mp[i].size(); j++) {
                if (vis[i][j]) {
                    mp[i][j] = '0';
                }
            }
        }

        for (int i = 0; i < mp.size(); i++) {
            while (mp[i].find('0') != string::npos) {
                mp[i].erase(mp[i].find('0'), 1);
                answer++;
            }
        }

        for (int i = 0; i < mp.size(); i++) {
            while (mp[i].size() != sz) {
                mp[i] += '1';
            }
        }

        for (int i = 0; i < mp.size(); i++) {
            cout << mp[i] << endl;
        }

        memset(vis, 0, sizeof(vis));
    }



    return answer;
}

