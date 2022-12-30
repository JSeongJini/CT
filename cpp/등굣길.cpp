#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    vector<vector<int>> path;

    for (int y = 0; y <= n; y++) {
        path.push_back({});
        for (int x = 0; x <= m; x++) {
            path[y].push_back(0);
        }
    }

    for (int i = 0; i < puddles.size(); i++) {
        path[puddles[i][1]][puddles[i][0]] = 1000000007;    //물에 잠긴 지역
    }

    path[0][1] = 1;
    for (int y = 1; y <= n; y++) {
        for (int x = 1; x <= m; x++) {
            if (path[y][x] != 1000000007)
                path[y][x] = (path[y - 1][x] + path[y][x - 1]) % 1000000007; // (a % c) + (b % c) = ((a + b) % c)
        }
    }

    return path[n][m];
}

int main() {
    vector<vector<int>> puddles = { {2, 2}, {3, 2} };

    cout << solution(4, 3, puddles);
}