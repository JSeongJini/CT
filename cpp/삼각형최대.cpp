#include <iostream>

#include <string>
#include <vector>

using namespace std;


int max(int lhs, int rhs) {
    return (lhs > rhs) ? lhs : rhs;
}


int solution(vector<vector<int>> triangle) {
    int answer = 0;

    int depth = triangle.size();

    for (int level = depth - 1; level > 0; level--) {
        for (int i = 0; i < level; i++) {
            triangle[level - 1][i] += max(triangle[level][i], triangle[level][i + 1]);
        }
    }
    answer = triangle[0][0];

    
    return answer;
}


int main() {
    vector<vector<int>> triangle = { {7}, {3, 8}, {8, 1, 0}, {2, 7, 4, 4}, {4,5,2,6,5} };
    cout << solution(triangle);
}