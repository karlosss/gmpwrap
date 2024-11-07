//
// Created by karlosss on 11/5/24.
//

#ifndef BIGINTEGER_H
#define BIGINTEGER_H
#include <gmp.h>
#include <string>

class BigInteger {
public:
    BigInteger();
    BigInteger(int value);
    BigInteger(const char* value);
    BigInteger(const BigInteger & other);

    ~BigInteger();

    BigInteger & operator=(const char* value);
    BigInteger & operator=(int value);
    BigInteger & operator=(const BigInteger & value);

    BigInteger & operator+=(const BigInteger & other);

    BigInteger & operator-=(const BigInteger & other);

    BigInteger & operator*=(const BigInteger & other);

    BigInteger & operator/=(const BigInteger & other);

    BigInteger operator+(const BigInteger & other) const;

    BigInteger operator-(const BigInteger & other) const;

    BigInteger operator*(const BigInteger & other) const;

    BigInteger operator*(unsigned long int value) const;

    BigInteger operator/(const BigInteger & other) const;

    bool operator<(const BigInteger & other) const;

    bool operator>(const BigInteger & other) const;

    bool operator==(const BigInteger & other) const;

    bool operator!=(const BigInteger & other) const;

    bool operator<=(const BigInteger & other) const;

    bool operator>=(const BigInteger & other) const;

    std::string to_string() const;

    int to_int() const;

    const mpz_t & get() const;

private:
    mpz_t i;
};

static std::ostream & operator<<(std::ostream & stream, const BigInteger & bi);

static std::istream & operator>>(std::istream & stream, BigInteger & bi);
#endif // BIGINTEGER_H
