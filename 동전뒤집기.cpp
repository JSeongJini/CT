#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<vector<int>> Reverse(const vector<vector<int>> beginning, int height, vector<int> reverse) {
    vector<vector<int>> result(beginning);

    for (int i = 0; i < reverse.size(); i++) {
        if (reverse[i] < height) {
            int row = reverse[i];
            for (auto i = 0; i < result[row].size(); i++)
                result[row][i] = (result[row][i] == 1) ? 0 : 1;
        }
        else {
            int col = reverse[i] - height;
            for (auto i = 0; i < result.size(); i++)
                result[i][col] = (result[i][col] == 1) ? 0 : 1;
        }
    }

    return result;
}

bool Equal(const vector<vector<int>> beginning, const vector<vector<int>> target) {
    int width = beginning[0].size();
    int height = beginning.size();
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (beginning[i][j] != target[i][j]) return false;
        }
    }
        
    return true;
}



int solution(vector<vector<int>> beginning, vector<vector<int>> target) {
    int answer = 0;
    int width = beginning[0].size();
    int height = beginning.size();

    if (Equal(beginning, target)) return 0;
    
    int start = 1;
    int end = width + height;

    vector<int> v;
    for (int i = 0; i < end; i++)
        v.push_back(i);


    while (start < end) {
        vector<int> temp;
        for (int i = 0; i < start; i++)
        {
            temp.push_back(1);
        }

        for (int i = 0; i < end - start; i++)
        {
            temp.push_back(0);
        }

        sort(temp.begin(), temp.end());

        do
        {
            vector<int> reverse;
            for (int i = 0; i < temp.size(); i++)
            {
                if (temp[i] == 1)
                    reverse.push_back(v[i]);
            }
            vector<vector<int>> reversed = Reverse(beginning, height, reverse);
            if (Equal(reversed, target)) return start;

        } while (next_permutation(temp.begin(), temp.end()));

        start++;
    }

    return -1;

}




int main() {
    vector<vector<int>> beginning = { {0, 1, 0, 0, 0},{1, 0, 1, 0, 1},{0, 1, 1, 1, 0},{1, 0, 1, 1, 0},{0, 1, 0, 1, 0}};

    vector<vector<int>> target = { {0, 0, 0, 1, 1},{0, 0, 0, 0, 1},{0, 0, 1, 0, 1},{0, 0, 0, 1, 0},{0, 0, 0, 0, 1} };

    cout << solution(beginning, target);
}