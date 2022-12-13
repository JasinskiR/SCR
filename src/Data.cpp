#include "Data.hpp"

#include <bits/stdc++.h>

void Data::readFile() {
  lines.erase(lines.begin(), lines.end());
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
    lines.push_back(tmp);
  }
  universalFilter();
  allData = numberOfLines;
}

void Data::clearVar() {
  hashData.erase(hashData.begin(), hashData.end());
  numberOfLines = 0;
}

void Data::universalFilter() {
  clearVar();
  for (uint64_t i = 0; i < lines.size(); ++i) {
    addHash(parser(lines.at(i)));
  }
}

std::vector<std::string> Data::parser(std::string line) {
  std::vector<std::string> parsedLine;
  std::string column;
  std::stringstream tmp(line);
  while (std::getline(tmp, column, '\t')) {
    parsedLine.emplace_back(std::move(column));
  }
  return parsedLine;
}

void Data::addHash(std::vector<std::string> parsed) {
  Hash hashedLine;
  if (parsed.size() == 4) {
    try {
      hashedLine.setOrdNo(stoul(parsed.at(0)));
    } catch (std::invalid_argument const &ex) {
      return;
    }
    try {
      hashedLine.setHashPasswd(parsed.at(1));
    } catch (std::invalid_argument const &ex) {
      return;
    }
    try {
      hashedLine.setMail(parsed.at(2));
    } catch (std::invalid_argument const &ex) {
      return;
    }
    try {
      hashedLine.setUserName(parsed.at(3));
    } catch (std::invalid_argument const &ex) {
      return;
      hashData.emplace_back(hashedLine);
      numberOfLines++;
    }
  }
}
