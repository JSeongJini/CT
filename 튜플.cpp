#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> ToSet(string s) {
    vector<vector<int>> result = { };
    int len = s.size();
    bool open = false;

    int index = 0;
    string num = "";
    for (int i = 1; i < len - 1; i++) {
        if (s[i] == '{') {
            result.push_back({});
        }else if (s[i] == '}') {
            result[index].push_back(stoi(num));
            num = "";
            index++;
        }
        else if (s[i] >= 48 && s[i] <= 57) {
            num += s[i];
        }
        else if (s[i] == ',') {
            if (num.length() > 0) {
                result[index].push_back(stoi(num));
                num = "";
            }
        }
    }

    return result;
}



vector<int> solution(string s) {
    vector<int> answer;

    vector<vector<int>> set = ToSet(s);

    vector<pair<int, int>> count;
    for (int i = 0; i < set.size(); i++) {
        count.push_back({ set[i].size(), i });
    }


    sort(count.begin(), count.end());


    vector<vector<int>> sortedSet = {};
    for (auto itr = count.begin(); itr != count.end(); itr++) {
        sortedSet.push_back(set[itr->second]);
    }

    
    answer.push_back(sortedSet[0][0]);

    for (int i = 1; i < sortedSet.size(); i++) {
        for (int j = 0; j < sortedSet[i].size(); j++) {
            bool isIncluded = false;
            for (int k = 0; k < answer.size(); k++) {
                if (answer[k] == sortedSet[i][j]) {
                    isIncluded = true;
                    break;
                }
            }
            if (!isIncluded) {
                answer.push_back(sortedSet[i][j]);
            }
        }
    }

    return answer;
}


int main() {
   
    vector<int> answer = solution("{{20,111},{111}}");

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }

}

