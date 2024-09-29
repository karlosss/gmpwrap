#ifndef GMPWRAP_LIBRARY_H
#define GMPWRAP_LIBRARY_H

#include <iostream>
#include "gmp.h"

template <int PRECISION_BITS>
class BigFloat {
public:
    BigFloat() {
        mpf_init2(fp, PRECISION_BITS);
    }

    BigFloat(int value): BigFloat() {
        setInt(value);
    }

    BigFloat(double value): BigFloat() {
        setDouble(value);
    }

    BigFloat(const char* value): BigFloat() {
        setString(value);
    }

    BigFloat& operator=(const char* value) {
        setString(value);
        return *this;
    }

    BigFloat& operator=(double value) {
        setDouble(value);
        return *this;
    }

    BigFloat& operator=(int value) {
        setInt(value);
        return *this;
    }

    BigFloat& operator=(const BigFloat & value) {
        setBigFloat(value);
        return *this;
    }

    BigFloat& operator+=(const BigFloat & other) {
        mpf_add(fp, fp, other.fp);
        return *this;
    }

    BigFloat& operator-=(const BigFloat & other) {
        mpf_sub(fp, fp, other.fp);
        return *this;
    }

    BigFloat& operator*=(const BigFloat & other) {
        mpf_mul(fp, fp, other.fp);
        return *this;
    }

    BigFloat& operator/=(const BigFloat & other) {
        mpf_div(fp, fp, other.fp);
        return *this;
    }

    BigFloat operator+(const BigFloat & other) const {
        BigFloat result;
        mpf_add(result.fp, fp, other.fp);
        return result;
    }

    BigFloat operator-(const BigFloat & other) const {
        BigFloat result;
        mpf_sub(result.fp, fp, other.fp);
        return result;
    }

    BigFloat operator*(const BigFloat & other) const {
        BigFloat result;
        mpf_mul(result.fp, fp, other.fp);
        return result;
    }

    BigFloat operator/(const BigFloat & other) const {
        BigFloat result;
        mpf_div(result.fp, fp, other.fp);
        return result;
    }

    bool operator<(const BigFloat & other) const {
        return mpf_cmp(fp, other.fp) < 0;
    }

    bool operator>(const BigFloat & other) const {
      return mpf_cmp(fp, other.fp) > 0;
    }

    bool operator==(const BigFloat & other) const {
      return mpf_cmp(fp, other.fp) == 0;
    }

    bool operator!=(const BigFloat & other) const {
      return mpf_cmp(fp, other.fp) != 0;
    }

    bool operator<=(const BigFloat & other) const {
      return mpf_cmp(fp, other.fp) <= 0;
    }

    bool operator>=(const BigFloat & other) const {
      return mpf_cmp(fp, other.fp) >= 0;
    }

    std::string toString() const {
        char* str;
        gmp_asprintf(&str, ("%." + std::to_string(PRECISION_BITS) + "Ff").c_str(), fp);
        std::string result(str);
        free(str);
        return result;
    }
private:
    mpf_t fp;
    void setDouble(double value) {
        mpf_set_d(fp, value);
    }
    void setInt(int value) {
        mpf_set_si(fp, value);
    }
    void setString(const std::string & value) {
        mpf_set_str(fp, value.c_str(), 10);
    }
    void setBigFloat(const BigFloat & other) {
        mpf_set(fp, other.fp);
    }
};

template <int PRECISION_BITS>
std::ostream& operator<<(std::ostream& stream, const BigFloat<PRECISION_BITS> & bf) {
    stream << bf.toString();
    return stream;
}

template <int PRECISION_BITS>
std::istream& operator>>(std::istream& stream, BigFloat<PRECISION_BITS> & bf) {
    std::string value;
    stream >> value;
    bf = value.c_str();
    return stream;
}

#endif //GMPWRAP_LIBRARY_H
