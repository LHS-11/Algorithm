#include<bits/stdc++.h>
using namespace std;

string solution(string new_id) {
    string answer = "";

    string new_id1 = "";
    // 1 단계
    for (auto c : new_id) {
        if (isupper(c)) new_id1 += tolower(c);
        else new_id1 += c;
    }
    // 포인터로 그냥 변경해버리기
    // for(auto &c:new_id) if(isupper(c)) c=tolower(c);

    // 2 단계
    new_id = "";
    for (auto c : new_id1) {
        if ('a' <= c && c <= 'z' ||
            '0' <= c && c <= '9' ||
            strchr("-_.", c)) new_id += c;
    }
    // for(auto c:new_id1){
    //     if(((c>='a' && c<='z') || (c>='0' && c<='9') || c=='-' || c=='_'||c=='.')){
    //         new_id+=c;
    //     }
    // }
    new_id1 = "";

    // 3 단계
    int x = 0;
    for (int i = 0; i < new_id.size(); i++) {
        if (new_id[i] == '.') {
            x++;
        }
        else {
            if (x >= 1) {
                new_id1 += new_id[i - 1];
            }
            new_id1 += new_id[i];
            x = 0;
        }
    }
    if (x >= 1) new_id1 += new_id[new_id.size() - 1];

    // 4 단계
    if (new_id1.front() == '.') new_id1.erase(0, 1);
    //  if(new_id1.front()=='.') new_id1.erase(new_id1.begin());
    if (new_id1.back() == '.') new_id1.pop_back();


    // 5 단계
    if (new_id1.size() == 0) new_id1 += 'a';

    new_id = "";
    // 6 단계
    if (new_id1.size() >= 16) {
        new_id1 = new_id1.substr(0, 15);
    }
    if (new_id1[new_id1.size() - 1] == '.') new_id1.pop_back();

    // 7 단계
    while (new_id1.size() <= 2) {
        new_id1 += new_id1.back();
    }
    cout << new_id1 << endl;

    answer = new_id1;
    return answer;
}