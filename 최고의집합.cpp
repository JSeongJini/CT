#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;

    if (s < n) {
        answer.push_back(-1);
        return answer;
    }

    int quotient = s / n;
    int remainder = s % n;

    for (int i = 0; i < n - remainder; i++)
        answer.push_back(quotient);

    for (int i = 0; i < remainder; i++)
        answer.push_back(quotient + 1);

    return answer;
}