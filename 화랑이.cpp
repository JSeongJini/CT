#include <string>
#include <vector>
#include <iostream>

using namespace std;

int Discovered(int x, int y, int workTime, int breakTime) {
    int period = workTime + breakTime;

    for (x; x <= y; x++) {
        int mod = x % period;

        if (mod <= workTime && mod != 0) 
            return x;
    }

    return 0;
}


int solution(int distance, vector<vector<int>> scope, vector<vector<int>> times) {
    int answer = distance;

    int len = scope.size();

    for (int i = 0; i < len; i++) {
        int x, y;
        if (scope[i][0] < scope[i][1]) {
            x = scope[i][0];
            y = scope[i][1];
        }
        else {
            x = scope[i][1];
            y = scope[i][0];
        }

        int result = Discovered(x, y, times[i][0], times[i][1]);
        
        if(result != 0)
            if (answer > result) 
                answer = result;
    }

    return answer;
}

int main() {
    vector<vector<int>> scope = { {7, 8},{4, 6}, {11, 10} };
    vector<vector<int>> times = { {2, 2},{2, 4}, {3, 3} };

    cout << solution(12, scope, times);

}
