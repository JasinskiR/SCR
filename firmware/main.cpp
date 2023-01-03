#include "Threads.cpp"
#include "Threads.hpp"
#include <csignal>
#include <iostream>

using namespace std;
Data hData;
void start_threads(pair<vector<string>, Data *> &p, Data *&ptrData) {
  pthread_create(&listener, &attr, Listener, &ptrData);
  pthread_create(&threads[0], &attr, &passwdCrack_legacy, &p);
  pthread_create(&threads[1], &attr, &passwdCrack_No_prefix, &p);
  pthread_create(&threads[2], &attr, &passwdCrack_No_sufix, &p);
  pthread_create(&threads[3], &attr, &passwdCrack_No_prefixANDsufix, &p);
}

void stop_threads() {
  pthread_cancel(threads[0]);
  pthread_cancel(threads[1]);
  pthread_cancel(threads[2]);
  pthread_cancel(threads[3]);
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
  vector<string> libWords = readDictionary(argv[2]);

  string new_file;

  // create threads
  std::pair<std::vector<std::string>, Data *> pairV = {libWords, &hData};
  start_threads(pairV, ptrhData);


  while (true) {
    cin >> new_file;
    stop_threads();
    pthread_mutex_lock(&mutex_);
    hData.readFile(new_file);
    pthread_mutex_unlock(&mutex_);
    start_threads(pairV, ptrhData);
  }

  cout << "__________________________\n";
}

void signal_handler(int) {
  hData.showAll();
}