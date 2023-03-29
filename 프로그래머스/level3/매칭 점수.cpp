#include<bits/stdc++.h>

using namespace std;

map<string, int> basic_scores; // 기본 점수를 저장할 맵
map<string, double> link_scores; // 외부 링크 수에 따른 링크 점수를 저장할 맵
map<string, vector<string>> outbound_links; // 외부 링크를 저장할 맵
map<string, double> matching_scores; // 매칭 점수를 저장할 맵

string to_lowercase(string s) { // 문자열을 모두 소문자로 변환해 반환하는 함수
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}

int solution(string word, vector<string> pages) {
    int n = pages.size();
    for (int i = 0; i < n; i++) {
        string page = pages[i];
        page = to_lowercase(page);
        string url;
        int pos = page.find("<meta property=\"og:url\" content=\"");
        pos += strlen("<meta property=\"og:url\" content=\"");
        while (page[pos] != '\"') {
            url += page[pos];
            pos++;
        }
        basic_scores[url] = 0; // url을 기본 점수 맵에 등록
        outbound_links[url] = vector<string>(); // url을 외부 링크 맵에 등록
        string body;
        int body_start = page.find("<body>");
        int body_end = page.find("</body>");
        body = page.substr(body_start, body_end - body_start);
        while (1) { // body에서 검색어를 찾아 기본 점수를 계산하고 외부 링크를 찾음
            int pos = body.find(word);
            if (pos == string::npos) break;
            if (body[pos - 1] >= 'a' && body[pos - 1] <= 'z') { // 단어와 붙어있는 문자는 기본 점수에서 제외
                body = body.substr(pos + word.length());
                continue;
            }
            if (body[pos + word.length()] >= 'a' && body[pos + word.length()] <= 'z') { // 단어와 붙어있는 문자는 기본 점수에서 제외
                body = body.substr(pos + word.length());
                continue;
            }
            basic_scores[url]++;
            body = body.substr(pos + word.length());
        }
        pos = page.find("<a href=");
        while (pos != string::npos) { // 외부 링크를 찾음
            string outbound_link;
            pos += strlen("<a href=\"");
            while (page[pos] != '\"') {
                outbound_link += page[pos];
                pos++;
            }
            outbound_links[url].push_back(outbound_link);
            link_scores[outbound_link] = 0; // 외부 링크를 링크 점수 맵에 등록
            pos = page.find("<a href=", pos);
        }
    }
    for (auto p : outbound_links) { // 외부 링크 수에 따른 링크 점수 계산
        int outbound_link_count = p.second.size(); // 해당 페이지에서의 외부 링크 수
        double link_score = (double)basic_scores[p.first] / outbound_link_count; // 해당 페이지의 기본 점수를 외부 링크 수로 나눠 링크 점수를 계산
        for (string outbound_link : p.second) {
            link_scores[outbound_link] += link_score; // 해당 페이지의 링크 점수를 외부 링크들의 링크 점수 맵에 더함
        }
    }

    for (auto p : basic_scores) { // 매칭 점수 계산
        double matching_score = p.second + link_scores[p.first];
        matching_scores[p.first] = matching_score;
    }

    string max_matching_url;
    double max_matching_score = -1;
    for (auto p : matching_scores) { // 매칭 점수가 가장 높은 페이지의 url을 찾음
        if (p.second > max_matching_score) {
            max_matching_url = p.first;
            max_matching_score = p.second;
        }
    }
    for (int i = 0; i < n; i++) { // 매칭 점수가 가장 높은 페이지의 인덱스를 반환
        if (max_matching_url == to_lowercase(pages[i])) return i;
    }
}
