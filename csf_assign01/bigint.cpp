#include <vector>
#include <iostream>
#include "bigint.h"
#include <sstream>
#include <iomanip>

BigInt::BigInt() {
  mag.push_back(0);
  neg = false;
}

BigInt::BigInt(uint64_t val, bool negative) {
  mag.push_back(val);
  neg = negative;
  if (val == 0) {
    neg = false;
  }
}

BigInt::BigInt(std::initializer_list<uint64_t> vals, bool negative) {
  mag = vals;
  neg = negative;
  if (mag.empty()) mag.push_back(0);
  // ensures all bigints have no leading zeroes
  trim_zeroes();
}

BigInt::BigInt(const BigInt &other) {
  mag = other.mag;
  neg = other.neg;
}

BigInt::~BigInt()
{
}

// helper functions
bool BigInt::is_zero() const {
  for (uint64_t i : mag) {
    if (i != 0) {
      return false;
    }
  }
  return true;
}

void BigInt::trim_zeroes() {
  // remove leading zeroes except if bigint = 0
  while(mag.size() > 1 && mag.back() == 0) {
    mag.pop_back();
  }
  if (mag[0] == 0 && mag.size() == 1) {
    neg = false;
  }
}

BigInt &BigInt::operator=(const BigInt &rhs) {
}

bool BigInt::is_negative() const {
  return neg;
}

const std::vector<uint64_t> &BigInt::get_bit_vector() const {
  return mag;
}

uint64_t BigInt::get_bits(unsigned index) const {
  if (index < mag.size()) {
    return mag[index];
  } else {
    return 0;
  }
}

BigInt BigInt::operator+(const BigInt &rhs) const {
  
}

BigInt BigInt::add_magnitudes(const BigInt &lhs, const BigInt &rhs){

}

BigInt BigInt::operator-(const BigInt &rhs) const {
}

BigInt BigInt::operator-() const {
  BigInt negSelf;
  negSelf.mag = mag;
  if (!is_zero()) {
    negSelf.neg = !negSelf.neg;
  }
  return negSelf;
}

bool BigInt::is_bit_set(unsigned n) const {
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
}

std::string BigInt::to_hex() const {
  if (is_zero()) {
    return "0";
  }
  std::stringstream out;
  if (neg) {
    out << "-";
  }
  for (size_t i = mag.size(); i > 0; i--) {
    size_t index = i - 1;
    if (index < mag.size() - 1) {
      out << std::hex << std::setfill('0') << std::setw(16) << mag[index];
    } else {
      out << std::hex << mag[index];
    }
  }
  return out.str();
}

std::string BigInt::to_dec() const
{
  // TODO: implement
}

