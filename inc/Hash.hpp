#ifndef HASH_HPP
#define HASH_HPP

#include <iostream>

class Hash {
private:
  uint64_t ordinalNo{};
  std::string hashPasswd{};
  std::string mail{};
  std::string userName{};

  Hash(uint64_t _ordNo, std::string _hashPasswd, std::string _mail, std::string _userName);

public:
  Hash(){};

  uint64_t getOrdNo() const { return ordinalNo; };

  std::string getHashPasswd() const { return hashPasswd; };

  std::string getMail() const { return mail; };

  std::string getUserName() const { return userName; };

  void setOrdNo(const uint64_t _ordinalNo) { ordinalNo = _ordinalNo; };

  void setHashPasswd(const std::string _passwd) { hashPasswd = _passwd; }

  void setMail(const std::string _mail) { mail = _mail; };

  void setUserName(const std::string _userName) { userName = _userName; };
};


std::ostream &operator<<(std::ostream &stream, const Hash &data);
#endif//SCR_2022_23_HASH_HPP
