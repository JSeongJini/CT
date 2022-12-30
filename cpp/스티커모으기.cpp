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

    selectFirst[0].push_back(sticker[0]);       //[0] -> ���� ����
    selectFirst[1].push_back(sticker[0]);       //[1] -> ������
    for (int i = 2; i < len - 1; i++) {         //ù�� ° ��ƼĿ�� �����ؼ�, ������ ��ƼĿ�� ���� �Ұ���
        int select = sticker[i] + selectFirst[0][i - 2];    //�����ϴ� ���, ���� ��ƼĿ�� �������� ���� ��� + ���� ��ƼĿ ��
        selectFirst[1].push_back(select);       

        if (select > answer) answer = select;

        //�������� �ʴ� ���, ���� ��ƼĿ�� ������ ���� �������� ���� ��� �� �� ū ��
        selectFirst[0].push_back(max(selectFirst[0][i - 2], selectFirst[1][i - 2]));
    }


    unselectFirst[0].push_back(0);
    unselectFirst[1].push_back(sticker[1]);
    for (int i = 2; i < len; i++) {         //ù�� ° ��ƼĿ�� �������� �ʾƼ�, ������ ��ƼĿ ���� ����
        int select = sticker[i] + unselectFirst[0][i - 2];
        unselectFirst[1].push_back(select);

        if (select > answer) answer = select;

        //�������� �ʴ� ���, ���� ��ƼĿ�� ������ ���� �������� ���� ��� �� �� ū ��
        unselectFirst[0].push_back(max(unselectFirst[0][i - 2], unselectFirst[1][i - 2]));
    }

    return answer;
}

int main() {
    vector<int> sticker = { 14, 6, 5, 11, 3, 9, 2, 10 };
    cout << solution(sticker);


}