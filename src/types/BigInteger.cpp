//
// Created by karlosss on 11/7/24.
//
#include "BigInteger.h"

void set(mpz_t i, int value) {
    mpz_set_si(i, value);
}

void set(mpz_t i, const char *value) {
    mpz_set_str(i, value, 10);
}

void set(mpz_t i, const BigInteger & value) {
    mpz_set(i, value.get());
}

BigInteger::BigInteger() {
    mpz_init(i);
}

BigInteger::BigInteger(int value): BigInteger() {
    set(i, value);
}

BigInteger::BigInteger(const char *value): BigInteger() {
    set(i, value);
}

BigInteger::BigInteger(const BigInteger &value): BigInteger() {
    set(i, value);
}

BigInteger::~BigInteger() {
    mpz_clear(i);
}

BigInteger & BigInteger::operator=(const char *value) {
    set(i, value);
    return *this;
}

BigInteger & BigInteger::operator=(int value) {
    set(i, value);
    return *this;
}

BigInteger & BigInteger::operator=(const BigInteger &value) {
    set(i, value);
    return *this;
}

BigInteger & BigInteger::operator+=(const BigInteger &other) {
    mpz_add(i, i, other.i);
    return *this;
}

BigInteger & BigInteger::operator-=(const BigInteger &other) {
    mpz_sub(i, i, other.i);
    return *this;
}

BigInteger & BigInteger::operator*=(const BigInteger &other) {
    mpz_mul(i, i, other.i);
    return *this;
}

BigInteger & BigInteger::operator/=(const BigInteger &other) {
    mpz_div(i, i, other.i);
    return *this;
}

BigInteger BigInteger::operator+(const BigInteger &other) const {
    BigInteger result;
    mpz_add(result.i, i, other.i);
    return result;
}

BigInteger BigInteger::operator-(const BigInteger &other) const {
    BigInteger result;
    mpz_sub(result.i, i, other.i);
    return result;
}

BigInteger BigInteger::operator*(const BigInteger &other) const {
    BigInteger result;
    mpz_mul(result.i, i, other.i);
    return result;
}

BigInteger BigInteger::operator*(unsigned long int value) const {
    BigInteger result;
    mpz_mul_ui(result.i, i, value);
    return result;
}

BigInteger BigInteger::operator/(const BigInteger &other) const {
    BigInteger result;
    mpz_div(result.i, i, other.i);
    return result;
}

bool BigInteger::operator<(const BigInteger &other) const {
    return mpz_cmp(i, other.i) < 0;
}

bool BigInteger::operator>(const BigInteger &other) const {
    return mpz_cmp(i, other.i) > 0;
}

bool BigInteger::operator==(const BigInteger &other) const {
    return mpz_cmp(i, other.i) == 0;
}

bool BigInteger::operator!=(const BigInteger &other) const {
    return mpz_cmp(i, other.i) != 0;
}

bool BigInteger::operator<=(const BigInteger &other) const {
    return mpz_cmp(i, other.i) <= 0;
}

bool BigInteger::operator>=(const BigInteger &other) const {
    return mpz_cmp(i, other.i) >= 0;
}

std::string BigInteger::to_string() const {
    char* str;
    gmp_asprintf(&str, "%Zd", i);
    std::string result(str);
    free(str);
    return result;
}

int BigInteger::to_int() const {
    return mpz_get_si(i);
}

const mpz_t & BigInteger::get() const {
    return i;
}
