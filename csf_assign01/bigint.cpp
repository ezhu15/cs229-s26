#include <vector>
#include <iostream>
#include "bigint.h"

  // TODO: initialize member variables

BigInt::BigInt() {
  mag.push_back(0);
  neg = false;
}

BigInt::BigInt(uint64_t val, bool negative)
  // TODO: initialize member variables
{
  mag.push_back(val);
  neg = negative;
}

BigInt::BigInt(std::initializer_list<uint64_t> vals, bool negative)
  // TODO: initialize member variables
{
  mag = vals;
  neg = negative;
}

BigInt::BigInt(const BigInt &other)
  // TODO: initialize member variables
{
  mag = other.mag;
  neg = other.neg;
}

BigInt::~BigInt()
{
}

BigInt &BigInt::operator=(const BigInt &rhs)
{
}

bool BigInt::is_negative() const
{
  return neg;
}

const std::vector<uint64_t> &BigInt::get_bit_vector() const {
  return mag;
}

uint64_t BigInt::get_bits(unsigned index) const
{
  if (index >= mag.size()){
    return 0;
  }
  return mag.at(index);
  // TODO: implement
}

BigInt BigInt::operator+(const BigInt &rhs) const
{
  
  // TODO: implement
}

BigInt BigInt::operator-(const BigInt &rhs) const
{
  // TODO: implement
  // Hint: a - b could be computed as a + -b
}

BigInt BigInt::operator-() const
{
  BigInt negSelf;
  negSelf.mag = mag;
  negSelf.neg = !neg;
  return negSelf;
  // TODO: implement
}

bool BigInt::is_bit_set(unsigned n) const
{
  // TODO: implement
}

BigInt BigInt::operator<<(unsigned n) const
{
  // TODO: implement
}

BigInt BigInt::operator*(const BigInt &rhs) const
{
  // TODO: implement
}

BigInt BigInt::operator/(const BigInt &rhs) const
{
  // TODO: implement
}

int BigInt::compare(const BigInt &rhs) const
{
  // TODO: implement
}

std::string BigInt::to_hex() const
{
  char hex[] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
  std::string out = "";
  if (neg) {
    out += '-';
  }
  for(int i = mag.size() - 1; i >= 0; i--) {
    uint64_t curr = mag[i];
    for(int j = 60; j >= 0; j -= 4) {
      char h = hex[(curr >> j) & 15];
      if (h == '0' && i == mag.size() - 1 && j != 0) {
        continue;
      }
      out += h;
    }
  }
  return out;
}

std::string BigInt::to_dec() const
{
  // TODO: implement
}

