#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    ifstream input{"example.txt"};
    // ifstream input{"input.txt"};

    long long invalidIdSum{};

    string range;
    while (getline(input, range, ',')) {

        long long start{stoll(range.substr(0, range.find('-')))};
        long long end{stoll(range.substr(range.find('-') + 1))};

        for (long long id{start}; id <= end; ++id) {
            vector<long long> found{};
            size_t length{to_string(id).length()};
            for (size_t i{1}; i <= length/2; i++) {
                string part{to_string(id).substr(0, i)};
                string check{};
                while (check.length() < length) {
                    check += part;
                }
                if (check == to_string(id) && find(found.begin(), found.end(), id) == found.end()) {
                    invalidIdSum += id;
                    found.push_back(id);
                }
            }
        }
    }

    cout << invalidIdSum << endl;

    return 0;
}