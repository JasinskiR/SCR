#pragma once

#include "Data.hpp"
#include "PasswdCrack.hpp"
#include <functional>
#include <pthread.h>

pthread_t threads[200];
int num_of_workers = 4;
pthread_t listener;
bool condition;

pthread_attr_t attr;
pthread_mutex_t mutex_;
pthread_cond_t condvar;

void *Listener(void *cracks);
void crackCore(std::string &word);
void *passwdCrack_legacy(void *dict);
void *passwdCrack_No_prefix(void *dict);
void *passwdCrack_No_sufix(void *dict);
void *passwdCrack_No_prefixANDsufix(void *dict);

