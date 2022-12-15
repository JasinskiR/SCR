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
  //passwdCrack_legacy(hData.hashData, libWords);
  passwdCrack_No(hData.hashData, libWords);
  cout << "End of app\n";
}