//#include <string>
//#include <vector>
//#include <stack>
//#include <iostream>
//
//using namespace std;
//
//int solution(vector<int> order) {
//    int answer = 0;
//
//    stack<int> second;
//
//    auto len = order.size();
//    int idx = 0;
//    int next = 1;
//    
//    while(true) {
//        if (order[idx] == next) {
//            answer++;
//            idx++;
//            next++;
//        }
//        else if (!second.empty() && second.top() == order[idx]) {
//            answer++;
//            idx++;
//            second.pop();
//        }
//        else {
//            if (next > len) break;
//            second.push(next);
//            next++;
//        }
//    }
//    
//    return answer;
//}
//
//int main() {
//    vector<int> order = { 4, 3, 1, 2, 5 };
//    cout << solution(order);
//}