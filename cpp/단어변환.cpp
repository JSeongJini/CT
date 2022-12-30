#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool IsDifferentOnlyOneAlpabat(const string lhs, const string rhs) {
    int len = lhs.length();
    int diff = 0;

    for (int i = 0; i < len; i++) {
        if (lhs[i] != rhs[i]) diff++;
    }

    return (diff == 1);
}

/// <summary>
/// DFS�� Ȱ���Ͽ� target���� ��ȯ�ϱ� ���� ���� �ܾ ã�� �Լ�
/// </summary>
/// <param name="begin">���� �ܾ�</param>
/// <param name="target">��ǥ �ܾ�</param>
/// <param name="words">�ܾ� ���</param>
/// <param name="path">��ȯ �������� ���õ� �ܾ� ���</param>
/// <param name="min">�ּ� ��ȯ ���� ����</param>
void SearchNextWord(const string begin, const string target, const vector<string> words, const vector<string> path, int& min) {
    if (begin == target) {
        if (path.size() < min) {
            min = path.size();
        }
        return;
    }

    if (path.size() > min) return;

    for (auto itr = words.begin(); itr != words.end(); itr++) {
        if (find(path.begin(), path.end(), *itr) == path.end()) {   //path�� ���� �ܾ��� ���
            if (IsDifferentOnlyOneAlpabat(begin, *itr)) {   
                vector<string> newPath(path);
                newPath.push_back(*itr);
                SearchNextWord(*itr, target, words, newPath, min);
            }
        }
    }
}


int solution(string begin, string target, vector<string> words) {
    if (find(words.begin(), words.end(), target) == words.end()) {
        return 0;
    }
    else {
        int min = 50;
        SearchNextWord(begin, target, words, { begin }, min);

        return min - 1; //min�� ���ۿ� ��ǥ �ܾ ������ ��ȯ ������ �����̹Ƿ�, -1�� ���־�� �Ѵ�.
    }
}

int main() {
    string begin = "hit";
    string target = "cog";
    vector<string> words = { "hot", "dot", "dog", "lot", "log" };
    
    cout << solution(begin, target, words);
}