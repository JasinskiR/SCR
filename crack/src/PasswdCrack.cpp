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

void passwdCrack_legacy(std::vector<Hash> line, const std::vector<std::string> &dict) {
  for (const auto &word: dict) {
    std::string hashedWord = md5hash(word);
    for (unsigned long i = 0; i < line.size(); i++) {
      if (checkPassword(hashedWord, line.at(i).getHashPasswd(), line.at(i).getMail(), word)) {
        line.erase(line.begin() + i);
      }
    }
  }
}

void passwdCrack_No(std::vector<Hash> line, const std::vector<std::string> &dict) {
  std::string tmp;
  std::string hashedWord;
  passwdCrack_legacy(line, dict);
  for (const auto &word: dict) {
    for (int fix = -1; fix < 99; fix++) {
      tmp = std::to_string(fix) + word;
      hashedWord = md5hash(tmp);
      for (unsigned long i = 0; i < line.size(); i++) {
        if (checkPassword(hashedWord, line.at(i).getHashPasswd(), line.at(i).getMail(), tmp)) {
          line.erase(line.begin() + i);
        }
      }
      tmp = word + std::to_string(fix);
      hashedWord = md5hash(tmp);
      for (unsigned long i = 0; i < line.size(); i++) {
        if (checkPassword(hashedWord, line.at(i).getHashPasswd(), line.at(i).getMail(), tmp)) {
          line.erase(line.begin() + i);
        }
      }

      const unsigned int Base = 10;
      for (int splitFix = 11; splitFix <= 9999; splitFix++) {
        unsigned int divisor = Base;
        while ((splitFix / divisor) > divisor) divisor *= Base;
        tmp = std::to_string(splitFix / divisor) + word + std::to_string(splitFix % divisor);
        hashedWord = md5hash(tmp);
        for (unsigned long i = 0; i < line.size(); i++) {
          if (checkPassword(hashedWord, line.at(i).getHashPasswd(), line.at(i).getMail(), tmp)) {
            line.erase(line.begin() + i);
          }
        }
      }
      //special 00 case
      for (unsigned long i = 0; i < line.size(); i++) {
        tmp = word + "00";
        hashedWord = md5hash(tmp);
        if (checkPassword(hashedWord, line.at(i).getHashPasswd(), line.at(i).getMail(), tmp)) {
          line.erase(line.begin() + i);
        }
        tmp = "00" + word;
        hashedWord = md5hash(tmp);
        if (checkPassword(hashedWord, line.at(i).getHashPasswd(), line.at(i).getMail(), tmp)) {
          line.erase(line.begin() + i);
        }
      }
    }
  }
}

bool checkPassword(const std::string &hashedWord, const std::string &password, const std::string &mail, const std::string &word) {
  if (hashedWord == password) {
    std::cout << "Password for " << mail << " is " << word << std::endl;
    return true;
  } else
    return false;
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
