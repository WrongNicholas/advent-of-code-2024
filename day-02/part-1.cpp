#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

bool is_safe(std::istream& stream) {
  int previous, current;
  stream >> previous;

  int delta, sign;
  bool first = true;

  while (stream >> current) {
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

int main(int argc, char *argv[]) {
  std::ifstream inputFile(argv[1]);

  int count = 0; 
  std::string line;

  while(std::getline(inputFile, line)) {

    std::istringstream stream(line);

    if (is_safe(stream)) count++;
  }
  
  std::cout << count << std::endl;
  
  return 0;
}
