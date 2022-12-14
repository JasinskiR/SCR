#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "Data.hpp"
#include "Dictionary.hpp"
#include "PasswCracking.hpp"

using namespace std;

int main() {
  Data hData;
  hData.readFile();
  vector<string> libWords = readDictionary();
  passwdCrack(hData.hashData, libWords);
}