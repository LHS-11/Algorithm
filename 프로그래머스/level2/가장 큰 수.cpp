#include<bits/stdc++.h>
using namespace std;
bool compare(string s1, string s2) {
    return s1 + s2 > s2 + s1;
}
string solution(vector<int> numbers) {
    string answer = "";

    vector<string> str;

    for (auto n : numbers) {
        str.push_back(to_string(n));
    }

    sort(str.begin(), str.end(), compare);

    if (str[0] == "0") return "0";

    for (auto s : str) {
        answer += s;
    }

    return answer;
}