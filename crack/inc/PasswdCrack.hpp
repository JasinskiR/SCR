#ifndef SCR_2022_23_PASSWCRACK_HPP
#define SCR_2022_23_PASSWCRACK_HPP

#include "Data.hpp"
#include <openssl/evp.h>
#include <openssl/md5.h>
#include <bits/stdc++.h>

std::string md5(const std::string& content);
void passwdCrack(std::vector<Hash> line, std::vector<std::string> dict);
std::vector<std::string> readDictionary();

#endif//SCR_2022_23_PASSWCRACK_HPP
