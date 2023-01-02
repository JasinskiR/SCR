#include "PasswdCrack.hpp"


std::string md5hash(const std::string &content) {
  std::stringstream result;
  unsigned char *passwArray;
  passwArray = new unsigned char[content.size() + 1];
  strcpy((char *) passwArray, content.c_str());
  unsigned char md[MD5_DIGEST_LENGTH];

  MD5(passwArray, content.size(), md);

  for (int i = 0; i < MD5_DIGEST_LENGTH; i++) {
    result << std::hex << std::setfill('0') << std::setw(2) << (int) md[i];
  }
  return result.str();
}

std::vector<std::string> readDictionary(std::string dict_f) {
  std::vector<std::string> words;
  std::string tmp;

  std::fstream file;
  file.open(dict_f, std::ios::in);
  if (!file.good()) {
    throw std::invalid_argument("The file " + dict_f +
                                " was not opened properly or " + dict_f +
                                "does not exist!");
  }

  while (!file.eof()) {
    if (!getline(file, tmp)) continue;
    words.push_back(tmp);
  }
  return words;
}
