#include "PasswdCrack.hpp"

std::string md5hash(const std::string& content) {
  unsigned char *passwArray;
  passwArray = new unsigned char[content.size() +1];
  strcpy((char *)passwArray, content.c_str());
  unsigned char md[MD5_DIGEST_LENGTH];

  MD5(passwArray, content.size(), md);

  for (int i = 0; i < MD5_DIGEST_LENGTH; i++) {
    std::cout << std::setw(2) << std::setfill('0') << std::hex << md[i];
  }
  return "";
}

void passwdCrack(std::vector<Hash> line, std::vector<std::string> dict) {
  for (auto word : dict) {
    std::string hashedWord = md5hash(word);
    for (auto passw : line) continue ;
    //if (hashedWord == passw.getHashPasswd())
    //std::cout << "Password for " << passw.getMail() << " is " << word << std::endl;
    //}
  }
}

std::vector<std::string> readDictionary() {
  std::vector<std::string> words;
  std::string tmp;
  std::cout << "Enter a file name: ";
  std::string fileName;
  std::cin >> fileName;

  std::fstream file;
  file.open(fileName, std::ios::in);
  if (!file.good()) {
    throw std::invalid_argument("The file " + fileName +
                                " was not opened properly or " + fileName +
                                "does not exist!");
  }

  while (!file.eof()) {
    if (!getline(file, tmp)) continue;
    words.push_back(tmp);
  }
  return words;
}
