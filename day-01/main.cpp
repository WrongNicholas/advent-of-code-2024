#include <iostream>
#include <fstream>
#include <set>
#include <string>

int main(int argc, char *argv[]) {
  std::ifstream inputFile(argv[1]); 
  std::multiset<int> left_set, right_set; 

  std::string line;
  std::string delimiter = "   ";
  while(std::getline(inputFile, line)) {
    int delimiter_position = line.find(delimiter);

    left_set.insert(std::stoi(line.substr(0, delimiter_position)));
    right_set.insert(std::stoi(line.substr(delimiter_position += delimiter.length())));
  }

  int dist_sum = 0;
  std::multiset<int>::iterator left_iterator = left_set.begin();
  std::multiset<int>::iterator right_iterator = right_set.begin();

  while(left_iterator != left_set.end() && right_iterator != right_set.end()) {
    dist_sum += std::abs(*left_iterator - *right_iterator);
    left_iterator++;
    right_iterator++;
  } 

  std::cout << dist_sum << std::endl;

  return 0;
}
