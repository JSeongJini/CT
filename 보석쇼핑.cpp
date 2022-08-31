/*
    프로그래머스 Lv.3
    보석 쇼핑

    이진탐색 버리고,
    슬라이딩 윈도우와 set과 map을 함께 이용하여
    모든 보석이 선택되었는지를 검사하여 시간을 단축시켰다
*/

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

bool IncludeAll(const map<string, int> selected) {
    for (auto it = selected.begin(); it != selected.end(); it++) {
        if (it->second <= 0) return false;
    }

    return true;
}



vector<int> solution(vector<string> gems) {
    vector<int> answer;


    int size = gems.size();

    //구매할 보석의 가짓수 구하기
    set<string> kind;
    for (auto it = gems.begin(); it != gems.end(); it++)
        kind.insert(*it);
    int kinds = kind.size();

    int max = gems.size();
    answer.push_back(0);
    answer.push_back(max);

    int start, end;
    start = -1; end = -1;

    map<string, int> selectedWithCount;
    set<string> selected;
    for (auto it = kind.begin(); it != kind.end(); it++) {
        selectedWithCount.insert({ *it, 0 });
    }


    while (end < max - 1) {
        while (selected.size() != kinds && end < max - 1) {
            selectedWithCount[gems[++end]]++;
            selected.insert(gems[end]);
        }

        while (selected.size() == kinds && start < end) {
            selectedWithCount[gems[++start]]--;
            if (selectedWithCount[gems[start]] == 0) {
                selected.erase(gems[start]);
            }
        }

        if (answer[1] - answer[0] > end - start) {
            answer[1] = end + 1;
            answer[0] = start + 1;
        }
    }

    return answer;
}



int main() {
    //vector<string> gems = { "DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA" };
    //vector<string> gems = { "ZZZ", "YYY", "NNNN", "YYY", "BBB" };
    vector<string> gems = { "AA", "AB", "AC", "AA", "AC" };
    //vector<string> gems = { "XYZ", "XYZ", "XYZ" };
    vector<int> result = solution(gems);
    cout << result[0] << ", " << result[1];
}