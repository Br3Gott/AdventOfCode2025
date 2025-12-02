#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main() {

    // ifstream input{"example.txt"};
    ifstream input{"input.txt"};

    long long invalidIdSum{};

    string range;
    while (getline(input, range, ',')) {

        long long start{stoll(range.substr(0, range.find('-')))};
        long long end{stoll(range.substr(range.find('-') + 1))};

        for (long long id{start}; id <= end; ++id) {
            size_t length{to_string(id).length()};
            if (length % 2 == 0) {
                string part1{to_string(id).substr(0, length / 2)};
                string part2{to_string(id).substr(length / 2)};
                if (part1 == part2) {
                    invalidIdSum += id;
                }
            }
        }
    }

    cout << invalidIdSum << endl;

    return 0;
}