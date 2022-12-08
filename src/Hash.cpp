#include "Hash.hpp"

Hash::Hash(uint64_t _ordNo, std::string _hashPasswd, std::string _mail, std::string _userName)
    : ordinalNo(_ordNo), hashPasswd(_hashPasswd), mail(_mail), userName(_userName) {}

std::ostream &operator<<(std::ostream &stream, const Hash &data) {
  stream << data.getOrdNo() << " " << data.getHashPasswd() << " "
         << data.getMail() << data.getUserName() std::endl;
  return stream;
}
