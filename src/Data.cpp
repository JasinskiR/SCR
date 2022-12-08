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
  std::string quoted;

  std::stringstream tmp(line);
  bool withQuote = false;
  std::string part = "";
  while (std::getline(tmp, column, ' ')) {
    std::stringstream quote(column);
    do {
      auto position = column.find("\"");
      if (position != std::string::npos) {
        withQuote = !withQuote;
        part += column.substr(0, position + 1);
        column = column.substr(position + 1, column.size());
      }
    } while (std::getline(quote, quoted, '\"'));

    if (!withQuote) {
      column += part;
      parsedLine.emplace_back(std::move(column));
      part = "";
    } else {
      part += column + ",";
    }
  }
  return parsedLine;
}

void Data::addHash(std::vector<std::string> parsed) {
  Hash hashedLine;
  if (parsed.size() == 3) {
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
      hashedLine.setUserName(parsed.at(2));
    } catch (std::invalid_argument const &ex) {
      return;
      hashData.emplace_back(hashedLine);
      numberOfLines++;
    }
  }
}
