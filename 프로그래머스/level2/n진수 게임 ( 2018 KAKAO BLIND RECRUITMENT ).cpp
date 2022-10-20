#include<bits/stdc++.h>
using namespace std;
vector<char> v;
void change(int n, int t, int m) {

    v.push_back('0');
    for (int i = 1; i <= t * m; i++) {
        int j = i;
        deque<char> v1;
        while (j) {
            if (n >= 11) {
                switch (j % n) {
                case 10: v1.push_front('A');
                    break;
                case 11: v1.push_front('B');
                    break;
                case 12: v1.push_front('C');
                    break;
                case 13: v1.push_front('D');
                    break;
                case 14: v1.push_front('E');
                    break;
                case 15: v1.push_front('F');
                    break;
                default: v1.push_front((j % n) + '0');
                    break;
                }
            }
            else {
                v1.push_front(((j % n) + '0'));
            }
            j /= n;

        }
        for (auto c : v1) v.push_back(c);
    }

}
string solution(int n, int t, int m, int p) {
    string answer = "";

    change(n, t, m);

    int k = 0;
    while (answer.size() != t) {
        answer += v[p + m * k - 1];
        k++;
    }

    return answer;
}

