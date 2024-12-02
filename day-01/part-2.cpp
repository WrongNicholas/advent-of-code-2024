#include <iostream>
#include <fstream>
#include <set>
#include <string> 

int main(int argc, char *argv[]) {
  std::ifstream inputFile(argv[1]); 
  std::set<int> left_set;
  std::multiset<int> right_set; 

  std::string line;
  std::string delimiter = "   ";
  while(std::getline(inputFile, line)) {
    int delimiter_position = line.find(delimiter);

    left_set.insert(std::stoi(line.substr(0, delimiter_position)));
    right_set.insert(std::stoi(line.substr(delimiter_position += delimiter.length())));
  }
  
  int similarity_score = 0;
  std::multiset<int>::iterator left_iterator = left_set.begin();

  while (left_iterator != left_set.end()) {
    int number = *left_iterator;
    int count = right_set.count(*left_iterator);

    similarity_score += number * count;
    left_iterator++;
  }

  std::cout << similarity_score << std::endl;
  return 0;
}
