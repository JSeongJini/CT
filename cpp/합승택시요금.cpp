#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

#define INF 999999

vector<vector<int>> AdjaencyMatrix(int n, vector<vector<int>> v) {
    vector<vector<int>> result;
    for (int i = 0; i <= n; i++) {
        result.push_back({});
        for (int j = 0; j <= n; j++) {
            if (i == j) result[i].push_back(0);
            else result[i].push_back(INF);
        }
    }

    for (auto itr = v.begin(); itr != v.end(); itr++) {
        result[(*itr)[0]][(*itr)[1]] = (*itr)[2];
        result[(*itr)[1]][(*itr)[0]] = (*itr)[2];
    }

    return result;
}

vector<vector<int>> Floyd(int n, vector<vector<int>> adj) {
    vector<vector<int>> result;

    for (int i = 0; i <= n; i++) {
        result.push_back({});
        for (int j = 0; j <= n; j++) {
            result[i].push_back(INF);
        }
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            result[i][j] = adj[i][j];
        }
    }

    for (int m = 1; m <= n; m++) {
        for (int s = 1; s <= n; s++) {
            for (int e = 1; e <= n; e++) {
                if (result[s][e] > result[s][m] + result[m][e]) {
                    result[s][e] = result[s][m] + result[m][e];
                }
            }
        }
    }

    return result;
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    vector<vector<int>> adj = AdjaencyMatrix(n, fares);
    vector<vector<int>> floyd = Floyd(n, adj);

    vector<int> answer = {0};
    int min = 100000 * n + 1;
    for (int i = 1; i <= n; i++) {
        answer.push_back(floyd[s][i] + floyd[i][a] + floyd[i][b]);
        if (min > answer[i]) {
            min = answer[i];
        }
    }


    return min;
}

int main() {
    vector<vector<int>> fares = { {4, 1, 10}, {3, 5, 24}, {5, 6, 2}, {3, 1, 41}, {5, 1, 24}, {4, 6, 50}, {2, 4, 66}, {2, 3, 22}, {1, 6, 25} };
    //vector<vector<int>> fares = { {2, 6, 6}, {6, 3, 7}, {4, 6, 7}, {6, 5, 11}, {2, 5, 12}, {5, 3, 20}, {2, 4, 8}, {4, 3, 9} };
    cout << solution(6, 4, 6, 2, fares);
}