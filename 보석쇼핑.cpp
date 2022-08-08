/*
    프로그래머스 Lv.3
    보석 쇼핑



    효율성 테스트에서 0점을 받는다...
    이진탐색까진 맞는거 같은데..
    슬라이딩 윈도우쪽에서 시간이 오래걸리는 듯하다..
    어떻게 해결할 수 있을까..
*/

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    answer.push_back(0);
    answer.push_back(0);

    int size = gems.size();

    //구매할 보석의 가짓수 구하기
    set<string> kind;
    for (auto it = gems.begin(); it != gems.end(); it++)
        kind.insert(*it);
    int kinds = kind.size();

    int max = gems.size();
   
    //start부터, end까지 집었을 때, 선택된 각 보석의 수를 기록
    map<string, int> selected;
    int low = kinds, high = size;

    while(low <= high){
        selected.clear();

        int mid = (low + high) / 2;
        int start = 0, end = mid;

        bool includeAll = false;

        for (int i = start; i < end; i++) {
            if (selected.find(gems[i]) == selected.end()) {
                //한 번도 선택된 적 없는 경우
                selected.insert({ gems[i], 1 });
            }
            else {
                //중복 선택된 경우
                selected[gems[i]]++;
            }
        }

        if (selected.size() == kinds) {
            includeAll = true;
        }
        else {
            while (end < max) {
                selected[gems[start]]--;

                if (selected.find(gems[end]) == selected.end()) {
                    selected.insert({ gems[end], 1 });
                }
                else {
                    selected[gems[end]]++;
                }

                if (selected[gems[start]] == 0)
                    selected.erase(gems[start]);

                start++;
                end++;

                if (selected.size() == kinds) {
                    includeAll = true;
                    break;
                }
            }
        }
        

        if (includeAll) {
            high = mid - 1;
            answer[0] = start + 1;
            answer[1] = end;
        }
        else {
            low = mid + 1;
        }
    }

    return answer;
}



int main() {
    //vector<string> gems = { "DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA" };
    vector<string> gems = { "ZZZ", "YYY", "NNNN", "YYY", "BBB" };
    //vector<string> gems = { "AA", "AB", "AC", "AA", "AC" };
    //vector<string> gems = { "XYZ", "XYZ", "XYZ" };
    vector<int> result = solution(gems);
    cout << result[0] << ", " << result[1];
}