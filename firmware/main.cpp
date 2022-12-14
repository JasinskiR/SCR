#include "Data.hpp"
#include "PasswdCrack.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  Data hData;
  hData.readFile();
  vector<string> libWords = readDictionary();
  passwdCrack(hData.hashData, libWords);
  cout << "End of app\n";
}