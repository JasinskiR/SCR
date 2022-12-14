#ifndef PASSW_HPP
#define PASSW_HPP

#include "Data.hpp"
#include <openssl/evp.h>
#include <openssl/md5.h>
#include <bits/stdc++.h>


using namespace std;
std::string md5(const std::string& content) {
  unsigned char passwArray[content.size() +1];
  strcpy((char *)passwArray, content.c_str());
  unsigned char md[MD5_DIGEST_LENGTH];
  MD5(passwArray, content.size(), md);

  for (int i = 0; i < MD5_DIGEST_LENGTH; i++) {
    cout << setw(2) << setfill('0') << hex << md[i];
  }
  return "";
}


void passwdCrack(std::vector<Hash> line, std::vector<std::string> dict) {
  for (auto word : dict) {
    std::string hashedWord = md5(word);
    //for (auto passw : line)
      //if (hashedWord == passw.getHashPasswd())
      //std::cout << "Password for " << passw.getMail() << " is " << word << std::endl;
   //}
  }
}

#endif 