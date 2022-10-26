#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int max(const int lhs, const int rhs) {
    return (lhs > rhs) ? lhs : rhs;
}

int solution(vector<int> sticker)
{
    int len = sticker.size();
    int answer = sticker[0];

    if (len == 1) return sticker[0];

    vector<vector<int>> selectFirst = { {}, {} };
    vector<vector<int>> unselectFirst = { {}, {} };

    selectFirst[0].push_back(sticker[0]);       //[0] -> 선택 안함
    selectFirst[1].push_back(sticker[0]);       //[1] -> 선택함
    for (int i = 2; i < len - 1; i++) {         //첫번 째 스티커를 선택해서, 마지막 스티커는 선택 불가능
        int select = sticker[i] + selectFirst[0][i - 2];    //선택하는 경우, 이전 스티커를 선택하지 않은 경우 + 현재 스티커 값
        selectFirst[1].push_back(select);       

        if (select > answer) answer = select;

        //선택하지 않는 경우, 이전 스티커를 선택한 경우와 선택하지 않은 경우 중 더 큰 값
        selectFirst[0].push_back(max(selectFirst[0][i - 2], selectFirst[1][i - 2]));
    }


    unselectFirst[0].push_back(0);
    unselectFirst[1].push_back(sticker[1]);
    for (int i = 2; i < len; i++) {         //첫번 째 스티커를 선택하지 않아서, 마지막 스티커 선택 가능
        int select = sticker[i] + unselectFirst[0][i - 2];
        unselectFirst[1].push_back(select);

        if (select > answer) answer = select;

        //선택하지 않는 경우, 이전 스티커를 선택한 경우와 선택하지 않은 경우 중 더 큰 값
        unselectFirst[0].push_back(max(unselectFirst[0][i - 2], unselectFirst[1][i - 2]));
    }

    return answer;
}

int main() {
    vector<int> sticker = { 14, 6, 5, 11, 3, 9, 2, 10 };
    cout << solution(sticker);


}