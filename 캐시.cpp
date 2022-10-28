#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

string GetLRUCity(const map<string, int> cache) {
    auto itr = cache.begin();
    int max = itr->second;
    string city = itr->first;
    for (itr++; itr != cache.end(); itr++) {
        if (itr->second > max) {
            max = itr->second;
            city = itr->first;
        }
    }

    return city;
}

string ParseCityName(const string str) {
    string result = "";
    int len = str.size();

    for (int i = 0; i < len; i++) {
        if (str[i] >= 97 && str[i] <= 122) {
            result += str[i];
        }
        else if (str[i] >= 65 && str[i] <= 90) {
            result += (str[i] + 32);
        }
    }
    return result;
}


int solution(int cacheSize, vector<string> cities) {
    int answer = 0;


    map<string, int> cache;
    int len = cities.size();
    if (cacheSize == 0) {
        return len * 5;
    }

    for (int i = 0; i < len; i++) {
        string city = ParseCityName(cities[i]);

        if (cache.find(city) != cache.end()) {
            //캐시에 있는 도시라면
            answer += 1;
            cache[city] = 0;       //Reset Last used
        }
        else {
            //캐시에 없는 도시라면
            if (cache.size() >= cacheSize) {
                string removeCity = GetLRUCity(cache);
                cache.erase(removeCity);
            }
            cache.insert({ city, 0 });

            answer += 5;
        }

        for (auto itr = cache.begin(); itr != cache.end(); itr++) {
            itr->second++;

        }
    }

    return answer;
}

int main() {
   // vector<string> cities = {"Jeju", "Pangyo", "Seoul", "NewYork", "LA", "Jeju", "Pangyo", "Seoul", "NewYork", "LA"};
    vector<string> cities = { "Jeju", "Pangyo" };

    //cout << ParseCityName(cities[2]) << " " << ParseCityName(cities[3]);


    cout << solution(0, cities);
}




