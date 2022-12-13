#ifndef DATA_HPP
#define DATA_HPP

#include <string>
#include <vector>
#include "Hash.hpp"

class Data {
private:

  std::vector<std::string> lines;
  uint64_t allData{};
  uint64_t numberOfLines{};

public:
  std::vector<Hash> hashData;
  void readFile();
  void clearVar();
  std::vector<std::string> parser(std::string line);
  void addHash(std::vector<std::string> parsed);
  void universalFilter();
};

#endif