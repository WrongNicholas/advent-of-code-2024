#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

bool is_safe(std::vector<int>& levels) {
  int previous, current;
  previous = levels[0];

  int delta, sign;
  bool first = true;

  for (int i = 1; i < levels.size(); i++) {
    current = levels[i];
    delta = current - previous;

    if (std::abs(delta) < 1 || std::abs(delta) > 3) return false;

    if (first) {
      sign = delta / std::abs(delta);
      first = false;
    }
    else if ((delta / std::abs(delta)) != sign) {
      return false;
    }

    previous = current; 
  }

  return true;
}

bool safe_with_one_removal(std::vector<int>& levels) {
  std::vector<int> vector_one_removed;
  for (int i = 0; i < levels.size(); i++) {
    for (int j = 0; j < levels.size(); j++) {
      if (i == j) continue;
      vector_one_removed.push_back(levels[j]);
    }

    if (is_safe(vector_one_removed)) return true;
    vector_one_removed.clear();
  }

  return false;
}

int main(int argc, char *argv[]) {
  std::ifstream inputFile(argv[1]);

  int count = 0; 
  std::string line;

  while(std::getline(inputFile, line)) {

    std::istringstream stream(line);

    std::vector<int> levels;
    int number;
    while (stream >> number) {
      levels.push_back(number);
    }

    if (is_safe(levels) || safe_with_one_removal(levels)) count++;
  }
  
  std::cout << count << std::endl;
  
  return 0;
}
