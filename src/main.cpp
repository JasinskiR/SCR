#include <fstream>
#include <iostream>
#include <openssl/evp.h>
#include <string>
#include <vector>
#include "Data.hpp"
#include "Library.hpp"

using namespace std;

int main() {
  Data hashedData;
  hashedData.readFile();
  vector<string> libWords = readLibrary();
  cout << "Dupa\n";
}