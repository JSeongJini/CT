/*
    프로그래머스 Lv3
    불량 사용자
*/
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

struct Node {
    string banned_id;
    vector<string> list;

    Node(string _id) :
        banned_id(_id)
    {}
};


bool IsSnaction(string user_id, string banned_id) {
    int len = banned_id.length();

    if (user_id.length() != len) return false;

    for (int i = 0; i < len; i++) {
        if (banned_id[i] != user_id[i]) {
            if (banned_id[i] != '*')
                return false;
        }
    }

    return true;
}


void FindCombination(int idx, int bannedSize, set<string> selected, const vector<Node> snaction, set<set<string>>& list) {
    if (idx == bannedSize) {
        if (selected.size() == bannedSize) {
            list.insert(selected);
        }
        return;
    }

    for (int i = 0; i < snaction[idx].list.size(); i++) {
        if (find(selected.begin(), selected.end(), snaction[idx].list[i]) == selected.end()) {
            set<string> select(selected);
            select.insert(snaction[idx].list[i]);
            FindCombination(idx + 1, bannedSize, select, snaction, list);
        }
    }

}


int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;

    int userSize = user_id.size();
    int bannedSize = banned_id.size();

    vector<Node> snaction;
    for (int i = 0; i < bannedSize; i++) {
        snaction.push_back(Node(banned_id[i]));
    }

    for (auto it = snaction.begin(); it != snaction.end(); it++) {
        for (int j = 0; j < userSize; j++) {
            if (IsSnaction(user_id[j], it->banned_id)) {
                it->list.push_back(user_id[j]);

            }
        }
    }

    set<string> selected;
    set<set<string>> list;
    FindCombination(0, bannedSize, selected, snaction, list);

    answer = list.size();
    return answer;
}

int main() {
    vector<string> user_id = { "frodo", "fradi", "crodo", "abc123", "frodoc" };
    vector<string> banned_id = { "fr*d*", "*rodo", "******", "******" };
    cout << solution(user_id, banned_id);
}