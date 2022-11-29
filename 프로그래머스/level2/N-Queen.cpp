#include <string>
#include <vector>
using namespace std;
int vis[13], cnt; // 행 : i, 열 : vis[i]
bool check(int i) {
    for (int j = 0; j < i; j++) {
        if (vis[i] == vis[j] || (abs(vis[i] - vis[j]) == i - j)) return false;
    }
    return true;
}
void go(int h, int n) {

    if (h == n) {
        cnt++;
        return;
    }


    for (int i = 0; i < n; i++) {
        vis[h] = i;
        if (check(h)) {
            go(h + 1, n);
        }
    }

}
int solution(int n) {
    int answer = 0;
    go(0, n);
    answer = cnt;
    return answer;
}