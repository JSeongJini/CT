#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>


using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;

    set<int> list;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;


    auto itr = operations.begin();
    while (itr != operations.end()) {
        char op = (*itr)[0];
        string value;
        value.assign((*itr), 2, (*itr).length() - 1);
        int num = stoi(value);

        if (op == 'I' || op == 'i') {
            list.insert(num);
            maxHeap.push(num);
            minHeap.push(num);
        }

        if (op == 'D' || op == 'd') {
            if (!list.empty()) {
                if (num > 0) {
                    while (list.find(maxHeap.top()) == list.end() && !list.empty() && !maxHeap.empty()) {
                        maxHeap.pop();
                    }

                    int target = maxHeap.top(); maxHeap.pop();
                    list.erase(target);

                }
                else {
                    while (list.find(minHeap.top()) == list.end() && !list.empty() && !minHeap.empty()) {
                        minHeap.pop();
                    }

                    int target = minHeap.top(); minHeap.pop();
                    list.erase(target);
                }
            }
        }

        itr++;
    }

    if (list.size() == 0) {
        answer.push_back(0);
        answer.push_back(0);
    }
    else {
        int max = maxHeap.top();
        int min = minHeap.top();
        while (list.find(max) == list.end() && !list.empty() && !maxHeap.empty()) {
            maxHeap.pop();
            max = maxHeap.top();
        }
        while (list.find(min) == list.end() && !list.empty() && !minHeap.empty()) {
            minHeap.pop();
            min = minHeap.top();
        }

        answer.push_back(max);
        answer.push_back(min);
    }
    return answer;
}

int main() {
    vector<string> operations = { "I -45", "I 653", "D 1", "I -642", "I 45", "I 97", "D 1", "D -1", "I 333" };
    vector<int> a = solution(operations);

    cout << a[0] << ", " << a[1] << endl;
}