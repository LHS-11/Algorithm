#include<bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;

    int sz = board.size();

    stack<int> stk;

    for (auto c : moves) {
        for (int i = 0; i < sz; i++) {
            if (board[i][c - 1]) {
                if (stk.size() && stk.top() == board[i][c - 1]) {
                    answer += 2;
                    stk.pop();
                }
                else stk.push(board[i][c - 1]);
                board[i][c - 1] = 0;
                break;
            }
        }

    }

    return answer;
}