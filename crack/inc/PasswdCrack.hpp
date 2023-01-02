#ifndef SCR_2022_23_PASSWCRACK_HPP
#define SCR_2022_23_PASSWCRACK_HPP

#include <bits/stdc++.h>
#include <openssl/evp.h>
#include <openssl/md5.h>


std::string md5hash(const std::string &content);
std::vector<std::string> readDictionary(std::string dict_f);

#endif//SCR_2022_23_PASSWCRACK_HPP
