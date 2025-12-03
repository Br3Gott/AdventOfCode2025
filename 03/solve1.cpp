#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

int main() {

  ifstream input{"example.txt"};
  // ifstream input{"input.txt"};

  long sum{};

  string line;
  while (getline(input, line)) {
    int largetCombo{};

    for (size_t i{}; i < line.length(); i++) {
      char c1{line[i]};

      for (size_t u{i + 1}; u < line.length(); u++) {
        char c2{line[u]};
        stringstream combo;
        combo << c1 << c2;
        int comboNum{stoi(combo.str())};
        if (comboNum > largetCombo) {
          largetCombo = comboNum;
        }
      }
    }
    sum += largetCombo;
  }

  cout << sum << endl;

  return 0;
}