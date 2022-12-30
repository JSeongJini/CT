#include <iostream>
#include <vector>
#include <string>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;

    vector<int> needInstall;
    int cur = 1;
    for (int i = 0; i < stations.size(); i++) {
        if(stations[i] - w - cur > 0)
            needInstall.push_back(stations[i] - w - cur);
        cur = stations[i] + w + 1;
    }
    if(n  >= cur)
        needInstall.push_back(n + 1 - cur);

    int coverDistance = 2 * w + 1;
    for (int i = 0; i < needInstall.size();) {
        if (needInstall[i] <= coverDistance) {
            i++;
        }
        else {
            needInstall[i] -= coverDistance;
        }
        answer++;
    }

    return answer;
}

int main() {
    int n = 16;
    int w = 0;
    vector<int> stations = { 9 };

    cout << solution(n, stations, w);
}