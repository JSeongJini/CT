#include <iostream>

#include <stack>
#include <string>
#include <vector>
using namespace std;


int solution(vector<int> a) {
    int len = a.size();
    if (len < 3) return len;

    stack<int> survived;
    survived.push(0);

    int removed = 0;
    int center = 1;
    int left = 0;
    int right = 2;
    while (center < len - 1) {
        if (a[center] > a[left] && a[center] > a[right]) {
            center = survived.top(); survived.pop();
            if (survived.empty()) {
                survived.push(center);
                center = right++;
            }
            left = survived.top();
            removed++;
        }
        else {
            survived.push(center);
            center = right++;
            left = survived.top();
        }
    }

    return len - removed;
}

int main() {
    //vector<int> a = { -16 };
    //vector<int> a = { 9, -1, -5 };
    vector<int> a = { -16, 27, 65, -2, 58, -92, -71, -68, -61, -33 };
    //vector<int> a = { -16, 27, 65, -2, 58 };



    cout << solution(a);
}