#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main() {

    ifstream input{"example.txt"};
    // ifstream input{"input.txt"};

    int pos{50};
    int atZero{};

    string line;
    while (getline(input, line)) {
        stringstream ss{line};
        string action{ss.str()};

        string direction{action.substr(0, 1)};
        int value{stoi(action.substr(1))};

        if (direction == "L") { // +
            for (int i = 0; i < value; ++i) {
                if (++pos > 99) {
                    pos = 0;
                }
            }
        } else { // -
            for (int i = 0; i < value; ++i) {
                if (--pos < 0) {
                    pos = 99;
                }
            }
        }

        if (pos == 0) {
            atZero++;
        }
    }

    cout << atZero << endl;

    return 0;
}