#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;

    int len = topping.size();

    set<int> left;
    map<int, int> right;

    for (int i = 0; i < len; i++)
    {
        if (right.find(topping[i]) != right.end()) {
            right[topping[i]]++;
        }
        else {
            right.insert({ topping[i], 1 });
        }
    }


    for (int mid = 1; mid < len; mid++) {
        left.insert(topping[mid - 1]);

        if (right.find(topping[mid - 1]) != right.end()) {
            right[topping[mid - 1]]--;

            if (right[topping[mid - 1]] == 0)
                right.erase(topping[mid - 1]);
        }

        if (left.size() == right.size()) answer++;
    }

    return answer;
}


int main() {
    vector<int> topping = { 1, 2, 1, 3, 1, 4, 1, 2 };
    cout << solution(topping) << endl;
}