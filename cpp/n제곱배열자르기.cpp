#include <iostream>

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;


    for (int i = left; i <= right; i++) {
        int a = i / n;
        int b = i % n;
        if (b < a) {
            answer.push_back(a + 1);
        }
        else {
            answer.push_back(b + 1);
        }
    }

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }

    return answer;
}

int main() {
    solution(3, 2, 5);
}
