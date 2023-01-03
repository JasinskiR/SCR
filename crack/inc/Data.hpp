#ifndef DATA_HPP
#define DATA_HPP

#include "Hash.hpp"
#include <bits/stdc++.h>

class Data {
private:
  std::vector<std::string> lines;
  uint64_t numberOfLines{};

public:
  std::unordered_map<std::string, Hash> hash2Hash;
  std::unordered_set<std::string> hashPasswd;
  std::vector<std::pair<std::string, Hash>> crackedPasswd;
  void readFile(const std::string& hash_f);
  void clearVar();
  std::vector<std::string> parser(std::string line);
  void addHash(std::vector<std::string> parsed);
  void universalFilter();
  void showAll();
};

#endif