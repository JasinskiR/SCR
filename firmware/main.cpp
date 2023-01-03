#include "Threads.cpp"
#include "Threads.hpp"
#include <csignal>
#include <iostream>

using namespace std;
Data hData;
void start_threads(vector<pair<vector<string>, Data *>> &p, Data *&ptrData) {
  pthread_create(&listener, &attr, Listener, &ptrData);

  pthread_create(&threads[0], &attr, &passwdCrack_legacy, &p[0]);
  pthread_create(&threads[1], &attr, &passwdCrack_No_prefix, &p[0]);
  pthread_create(&threads[2], &attr, &passwdCrack_No_sufix, &p[0]);
  pthread_create(&threads[3], &attr, &passwdCrack_No_prefixANDsufix, &p[0]);
  pthread_create(&threads[4], &attr, &passwdCrack_doubleWord, &p[0]);

  pthread_create(&threads[5], &attr, &passwdCrack_legacy, &p[1]);
  pthread_create(&threads[6], &attr, &passwdCrack_No_prefix, &p[1]);
  pthread_create(&threads[7], &attr, &passwdCrack_No_sufix, &p[1]);
  pthread_create(&threads[8], &attr, &passwdCrack_No_prefixANDsufix, &p[1]);
  pthread_create(&threads[9], &attr, &passwdCrack_doubleWord, &p[1]);

  pthread_create(&threads[10], &attr, &passwdCrack_legacy, &p[2]);
  pthread_create(&threads[11], &attr, &passwdCrack_No_prefix, &p[2]);
  pthread_create(&threads[12], &attr, &passwdCrack_No_sufix, &p[2]);
  pthread_create(&threads[13], &attr, &passwdCrack_No_prefixANDsufix, &p[2]);
  pthread_create(&threads[14], &attr, &passwdCrack_doubleWord, &p[2]);
}

void stop_threads() {
  for (int i = 0; i < 15; i++) {
    pthread_cancel(threads[i]);
  }
  pthread_cancel(listener);
}

void signal_handler(int signal_num);

int main(int argc, char *argv[]) {
  if (argc != 3) {
    throw std::invalid_argument("Invalid number of arguments Required " + to_string(2) +
                                " provided " + to_string(argc));
  }
  signal(SIGHUP, signal_handler);

  Data *ptrhData = &hData;
  hData.readFile(argv[1]);
  vector<string> libWords1 = readDictionary(argv[2]);
  vector<string> libWords2 = firstUpperCase(libWords1);
  vector<string> libWords3 = allUpperCase(libWords1);

  string new_file;

  // create threads
  vector<pair<vector<string>, Data *>> dataVec = {{libWords1, &hData}, {libWords2, &hData}, {libWords3, &hData}};
  start_threads(dataVec, ptrhData);


  while (true) {
    cin >> new_file;
    cout << num_of_workers << endl;
    stop_threads();

    pthread_mutex_unlock(&mutex_);

    hData.readFile(new_file);
    num_of_workers = 15;
    pthread_mutex_unlock(&mutex_);
    start_threads(dataVec, ptrhData);
  }

  cout << "__________________________\n";
}

void signal_handler(int) {
  hData.showAll();
}