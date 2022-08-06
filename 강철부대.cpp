#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;

    vector<int> distance;
    vector<bool> visit;
    for (int i = 0; i < n + 1; i++) {
        distance.push_back(-1);
        visit.push_back(false);
    }

    vector<vector<bool>> adj;
    for (int i = 0; i < n + 1; i++) {
        vector<bool> row;
        for (int j = 0; j < n + 1; j++) {
            if (i == j) row.push_back(true);
            else row.push_back(false);
        }
        adj.push_back(row);
    }

    for (int i = 0; i < roads.size(); i++) {
        adj[roads[i][0]][roads[i][1]] = true;
        adj[roads[i][1]][roads[i][0]] = true;
    }



    queue<int> q;
    q.push(destination);
    visit[destination] = true;
    distance[destination] = 0;

    while (!q.empty()) {
        int location = q.front(); q.pop();

        for (int i = 1; i <= n; i++) {
            if (adj[location][i]) {
                if (!visit[i]) {
                    visit[i] = true;
                    q.push(i);
                    distance[i] = distance[location] + 1;
                }
            }
        }
    }

    for (int i = 0; i < sources.size(); i++) {
        answer.push_back(distance[sources[i]]);
    }

    return answer;
}

int main() {
    int n = 5;
    vector<vector<int>> roads = { {1, 2}, {1, 4}, {2, 4}, {2, 5}, {4, 5} };
    vector<int> sources = { 1, 3, 5 };
    int destination = 5;

    vector<int> result = solution(n, roads, sources, destination);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << ' ';
    }
    cout << endl;
}


