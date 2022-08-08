/*
    ���α׷��ӽ� Lv.3
    ���� ����



    ȿ���� �׽�Ʈ���� 0���� �޴´�...
    ����Ž������ �´°� ������..
    �����̵� �������ʿ��� �ð��� �����ɸ��� ���ϴ�..
    ��� �ذ��� �� ������..
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

    //������ ������ ������ ���ϱ�
    set<string> kind;
    for (auto it = gems.begin(); it != gems.end(); it++)
        kind.insert(*it);
    int kinds = kind.size();

    int max = gems.size();
   
    //start����, end���� ������ ��, ���õ� �� ������ ���� ���
    map<string, int> selected;
    int low = kinds, high = size;

    while(low <= high){
        selected.clear();

        int mid = (low + high) / 2;
        int start = 0, end = mid;

        bool includeAll = false;

        for (int i = start; i < end; i++) {
            if (selected.find(gems[i]) == selected.end()) {
                //�� ���� ���õ� �� ���� ���
                selected.insert({ gems[i], 1 });
            }
            else {
                //�ߺ� ���õ� ���
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