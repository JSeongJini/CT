#include <iostream>

#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

void NextDestination(const string departure, map<string, vector<string>> destinations, const int count, vector<string> candidate, vector<string>& answer) {
    if (!answer.empty()) { //�� ������.
        return;
    }

    if (candidate.size() == count + 1) {    //��� Ƽ���� ����Ͽ��� ���
        answer = candidate;
        return;
    }
    
    if (destinations.find(departure) == destinations.end() 
        || destinations[departure].empty()) {  //���� ��ġ���� �� �̻� �� ���� ���� ���
        return;
    }

    for (int i = 0; i < destinations[departure].size(); i++) {
        string destination = destinations[departure][i];
        map<string, vector<string>> reaminDestination(destinations);
        reaminDestination[departure].erase(reaminDestination[departure].begin() + i);
        vector<string> nextCandidate(candidate);
        nextCandidate.push_back(destination);
        NextDestination(destination, reaminDestination, count, nextCandidate, answer);
    }
}




vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    int count = tickets.size();
    sort(tickets.begin(), tickets.end());

    map<string, vector<string>> destinations;
    for (auto itr = tickets.begin(); itr != tickets.end(); itr++) {
        string departure = (*itr)[0];
        string dest = (*itr)[1];

        if (destinations.find(departure) == destinations.end()) {
            vector<string> list;
            list.push_back(dest);
            destinations.insert({ departure, list });
        }
        else {
            destinations[departure].push_back(dest);
        }
    }

    NextDestination("ICN", destinations, count, {"ICN"}, answer);

    return answer;
}


int main() {
    vector<vector<string>> tickets = { {"ICN", "SFO"}, {"ICN", "ATL"}, {"SFO", "ATL"}, {"ATL", "ICN"}, {"ATL", "SFO"}, {"SFO", "AAA"}};
    
    vector<string> answer = solution(tickets);

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i];
        if (i < answer.size() - 1) {
            cout << "-";
        }
    }
}