//
// Created by karlosss on 11/5/24.
//

#ifndef BIGFLOAT_H
#define BIGFLOAT_H
#include <gmp.h>
#include <string>

class BigFloat {
public:
    BigFloat();
    BigFloat(int value);
    BigFloat(double value);
    BigFloat(const char* value);
    BigFloat(const BigFloat & other);

    ~BigFloat();

    BigFloat & operator=(const char* value);
    BigFloat & operator=(double value);
    BigFloat & operator=(int value);
    BigFloat & operator=(const BigFloat & value);

    BigFloat & operator+=(const BigFloat & other);

    BigFloat & operator-=(const BigFloat & other);

    BigFloat & operator*=(const BigFloat & other);

    BigFloat & operator/=(const BigFloat & other);

    BigFloat operator+(const BigFloat & other) const;

    BigFloat operator-(const BigFloat & other) const;

    BigFloat operator*(const BigFloat & other) const;

    BigFloat operator*(unsigned long int value) const;

    BigFloat operator/(const BigFloat & other) const;

    bool operator<(const BigFloat & other) const;

    bool operator>(const BigFloat & other) const;

    bool operator==(const BigFloat & other) const;

    bool operator!=(const BigFloat & other) const;

    bool operator<=(const BigFloat & other) const;

    bool operator>=(const BigFloat & other) const;

    int get_precision() const;

    std::string to_string() const;

    double to_double() const;

    const mpf_t & get() const;

private:
    mpf_t fp;
};

static std::ostream & operator<<(std::ostream & stream, const BigFloat & bf);

static std::istream & operator>>(std::istream & stream, BigFloat & bf);

#endif // BIGFLOAT_H
