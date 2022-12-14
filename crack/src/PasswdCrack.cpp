#include "PasswdCrack.hpp"

std::string md5hash(const std::string& content) {
  std::stringstream result;
  unsigned char *passwArray;
  passwArray = new unsigned char[content.size() +1];
  strcpy((char *)passwArray, content.c_str());
  unsigned char md[MD5_DIGEST_LENGTH];

  MD5(passwArray, content.size(), md);

  for (int i = 0; i < MD5_DIGEST_LENGTH; i++) {
    result << std::hex << std::setfill('0') << std::setw(2) << (int)md[i];
  }
  return result.str();
}

void passwdCrack(std::vector<Hash> line, const std::vector<std::string>& dict) {
  for (const auto& word : dict) {
    std::string hashedWord = md5hash(word);
    for (unsigned long i = 0; i < line.size() ; i++) {
      if (hashedWord == line.at(i).getHashPasswd()) {
        std::cout << "Password for " << line.at(i).getMail() << " is " << word << std::endl;
        line.erase(line.begin() + i);
      }
    }
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
