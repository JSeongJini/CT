//#include <string>
//#include <vector>
//#include <iostream>
//#include <map>
//using namespace std;
//
//int solution(vector<string> want, vector<int> number, vector<string> discount) {
//    int answer = 0;
//
//    //품목명, {구매가능한 수, 원하는 구매 수}
//    map<string, pair<int, int>> buyable;
//
//    auto len = want.size();
//    for (int i = 0; i < len; i++) {
//        buyable.insert({ want[i], {0, number[i]} });
//    }
//
//    auto lastday = discount.size();
//    
//    if (lastday < 10) return 0;
//
//    for (int i = 0; i < 10; i++) {
//        if (buyable.find(discount[i]) != buyable.end()) {
//            buyable[discount[i]].first++;
//        }
//    }
//
//    bool allBuyable = true;
//    auto itr = buyable.begin();
//    for (itr; itr != buyable.end(); itr++) {
//        if (itr->second.first < itr->second.second) {
//            allBuyable = false;
//            break;
//        }
//    }
//
//    if (allBuyable) answer++;
//
//    int begin = 0;
//    int after = 10;
//    while (after < lastday) {
//        allBuyable = true;
//        if (buyable.find(discount[begin]) != buyable.end()) {
//            if (buyable[discount[begin]].first > 0) buyable[discount[begin]].first--;
//        }
//
//        if (buyable.find(discount[after]) != buyable.end()) {
//            buyable[discount[after]].first++;
//        }
//
//        auto itr = buyable.begin();
//        for (itr; itr != buyable.end(); itr++) {
//            if (itr->second.first < itr->second.second) {
//                allBuyable = false;
//                break;
//            }
//        }
//
//        if (allBuyable) answer++;
//
//        begin++;
//        after++;
//    }
//
//    return answer;
//}
//
//int main() {
//    vector<string> want = { "banana", "apple", "rice", "pork", "pot" };
//    vector<int> number = { 3, 2, 2, 2, 1 };
//    vector<string> discount = { "chicken", "apple", "apple", "banana", "rice", "apple", "pork", "banana", "pork", "rice", "pot", "banana", "apple", "banana" };
//    cout << solution(want, number, discount);
//
//}