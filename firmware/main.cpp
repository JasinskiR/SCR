#include "Threads.hpp"
#include "Threads.cpp"
#include <iostream>

using namespace std;

int main() {
  Data hData;
  Data *ptrhData = &hData;
  hData.readFile();
  vector<string> libWords = readDictionary();

  // create threads
  std::pair<std::vector<std::string>, Data *> p = {libWords, &hData};
  pthread_create(&listener, &attr, Listener, &ptrhData);
  pthread_create(&threads[0], &attr, &passwdCrack_legacy, &p);
  pthread_create(&threads[1], &attr, &passwdCrack_No_prefix, &p);
  pthread_create(&threads[2], &attr, &passwdCrack_No_sufix, &p);
  pthread_create(&threads[3], &attr, &passwdCrack_No_prefixANDsufix, &p);
  pthread_join(listener, nullptr);
  cout << "__________________________\n";
}