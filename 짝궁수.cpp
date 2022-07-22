//#include <string>
//#include <vector>
//#include <iostream>
//
//using namespace std;
//
//string solution(string X, string Y) {
//    string answer = "";
//
//    vector<int> x = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
//    vector<int> y = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
//    vector<int> Union = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
//
//    auto xLen = X.size();
//    auto yLen = Y.size();
//
//    for (int i = 0; i < xLen; i++) {
//        int num = X[i] - 48;
//        x[num]++;
//    }
//
//    for (int i = 0; i < yLen; i++) {
//        int num = Y[i] - 48;
//        y[num]++;
//    }
//
//    for (int i = 0; i < 10; i++) {
//        if (x[i] > 0 && y[i] > 0) {
//            int min = (x[i] < y[i]) ? x[i] : y[i];
//            Union[i] = min;
//        }
//    }
//
//
//    for (int i = 9; i >= 0;) {
//        if (i == 0 && answer.compare("") == 0 && Union[i] > 0)
//            return "0";
//
//
//        if (Union[i] > 0) {
//            answer += to_string(i);
//            Union[i]--;
//        }
//        else {
//            i--;
//        }
//    }
//
//    if (answer.compare("") == 0)
//        return "-1";
//
//    return answer;
//}
//
//int main() {
//    string X = "12321";
//    string Y = "42531";
//    cout << solution(X, Y);
//}