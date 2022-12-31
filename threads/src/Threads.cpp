#include "Threads.hpp"

void crackCore(const std::string &word, Data *hData) {
  auto hash = md5hash(word);
  auto it = hData->hashPasswd.find(hash);
  if (it == hData->hashPasswd.end()) {
    return;
  }
  pthread_mutex_lock(&mutex_);
  hData->crackedPasswd.emplace_back(word, hData->hash2Hash[hash]);
  hData->hash2Hash.erase(hash);
  hData->hashPasswd.erase(it);
  condition = true;
  pthread_cond_signal(&condvar);
  pthread_mutex_unlock(&mutex_);
}

void *Listener(void *data) {
  auto hData_ = static_cast<Data **>(data);
  auto hData = *hData_;
  pthread_mutex_lock(&mutex_);
  while (true) {
    while (!condition) {
      pthread_cond_wait(&condvar, &mutex_);
      if (!num_of_workers) {
        pthread_exit(nullptr);
      }
    }
    std::cout << "Password for " << hData->crackedPasswd.back().second.getMail()
              << " is " << hData->crackedPasswd.back().first << std::endl;
    condition = false;
  }
}

void *passwdCrack_legacy(void *p) {
  auto pair_ = static_cast<std::pair<std::vector<std::string>, Data *> *>(p);
  auto lib = pair_->first;
  for (auto const &word: lib) {
    crackCore(word, pair_->second);
  }
  pthread_mutex_lock(&mutex_);
  num_of_workers--;
  pthread_cond_signal(&condvar);
  pthread_mutex_unlock(&mutex_);
  pthread_exit(nullptr);
}

void *passwdCrack_No_prefix(void *p) {
  auto pair_ = static_cast<std::pair<std::vector<std::string>, Data *> *>(p);
  auto lib = pair_->first;
  for (const auto &word: lib) {
    for (int fix = 0; fix < 99; fix++) {
      crackCore(std::to_string(fix) + word, pair_->second);
    }
  }
  pthread_mutex_lock(&mutex_);
  num_of_workers--;
  pthread_cond_signal(&condvar);
  pthread_mutex_unlock(&mutex_);
  pthread_exit(nullptr);
}

void *passwdCrack_No_sufix(void *p) {
  auto pair_ = static_cast<std::pair<std::vector<std::string>, Data *> *>(p);
  auto lib = pair_->first;
  for (const auto &word: lib) {
    for (int fix = 0; fix < 99; fix++) {
      crackCore(word + std::to_string(fix), pair_->second);
    }
  }
  pthread_mutex_lock(&mutex_);
  num_of_workers--;
  pthread_cond_signal(&condvar);
  pthread_mutex_unlock(&mutex_);
  pthread_exit(nullptr);
}

void *passwdCrack_No_prefixANDsufix(void *p) {
  auto pair_ = static_cast<std::pair<std::vector<std::string>, Data *> *>(p);
  auto lib = pair_->first;
  for (const auto &word: lib) {
    for (int fix1 = 0; fix1 < 99; fix1++) {
      for (int fix2 = 0; fix2 < 99; fix2++) {
        crackCore(std::to_string(fix1) + word + std::to_string(fix2), pair_->second);
      }
    }
  }
  pthread_mutex_lock(&mutex_);
  num_of_workers--;
  pthread_cond_signal(&condvar);
  pthread_mutex_unlock(&mutex_);
  pthread_exit(nullptr);
}