#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;

    //고속도로에서 나간지점 기준으로 오름차순으로 정렬하기 위해 자리 스왑
    for (int i = 0; i < routes.size(); i++) {
        int tmp = routes[i][0];
        routes[i][0] = routes[i][1];
        routes[i][1] = tmp;
    }

    sort(routes.begin(), routes.end());


    while (!routes.empty()) {
        int point = routes[0][0];

        //처음으로 나간 차의 지점을 통과한 모든 차량을 목록에서 제거
        for (int i = 0; i < routes.size(); i++) {
            if (routes[i][0] >= point && point >= routes[i][1]) {
                routes.erase(routes.begin() + i--);
            }
        }
        
        answer++;
    }
    
    return answer;
}

int main() {
    vector<vector<int>> routes = { {3, 22}, {5, 12}, {10, 15}, {12, 17}, {6, 16}, {15, 20}, {13, 18} };
    
    cout << solution(routes);
}