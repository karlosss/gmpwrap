//
// Created by karlosss on 11/5/24.
//

#include "BigFloat.h"

void set(mpf_t fp, int value) {
    mpf_set_si(fp, value);
}

void set(mpf_t fp, const char* value) {
    mpf_set_str(fp, value, 10);
}

void set(mpf_t fp, double value) {
    mpf_set_d(fp, value);
}

void set(mpf_t fp, const BigFloat & value) {
    mpf_set(fp, value.get());
}

BigFloat::BigFloat() {
    mpf_init(fp);
}

BigFloat::BigFloat(int value) : BigFloat() {
    set(fp, value);
}

BigFloat::BigFloat(double value) : BigFloat() {
    set(fp, value);
}

BigFloat::BigFloat(const char* value) : BigFloat() {
    set(fp, value);
}

BigFloat::BigFloat(const BigFloat & value) : BigFloat() {
    set(fp, value);
}

BigFloat::~BigFloat() {
    mpf_clear(fp);
}

BigFloat & BigFloat::operator=(int value) {
    set(fp, value);
    return *this;
}

BigFloat & BigFloat::operator=(double value) {
    set(fp, value);
    return *this;
}

BigFloat & BigFloat::operator=(const char* value) {
    set(fp, value);
    return *this;
}

BigFloat & BigFloat::operator=(const BigFloat & value) {
    set(fp, value);
    return *this;
}

BigFloat & BigFloat::operator+=(const BigFloat & other) {
    mpf_add(fp, fp, other.fp);
    return *this;
}

BigFloat & BigFloat::operator-=(const BigFloat & other) {
    mpf_sub(fp, fp, other.fp);
    return *this;
}

BigFloat & BigFloat::operator*=(const BigFloat & other) {
    mpf_mul(fp, fp, other.fp);
    return *this;
}

BigFloat & BigFloat::operator/=(const BigFloat & other) {
    mpf_div(fp, fp, other.fp);
    return *this;
}

BigFloat BigFloat::operator+(const BigFloat & other) const {
    BigFloat result;
    mpf_add(result.fp, fp, other.fp);
    return result;
}

BigFloat BigFloat::operator-(const BigFloat & other) const {
    BigFloat result;
    mpf_sub(result.fp, fp, other.fp);
    return result;
}

BigFloat BigFloat::operator*(const BigFloat & other) const {
    BigFloat result;
    mpf_mul(result.fp, fp, other.fp);
    return result;
}

BigFloat BigFloat::operator*(unsigned long int value) const {
    BigFloat result;
    mpf_mul_ui(result.fp, fp, value);
    return result;
}

BigFloat BigFloat::operator/(const BigFloat & other) const {
    BigFloat result;
    mpf_div(result.fp, fp, other.fp);
    return result;
}

bool BigFloat::operator<(const BigFloat & other) const {
    return mpf_cmp(fp, other.fp) < 0;
}

bool BigFloat::operator>(const BigFloat & other) const {
    return mpf_cmp(fp, other.fp) > 0;
}

bool BigFloat::operator==(const BigFloat & other) const {
    return mpf_cmp(fp, other.fp) == 0;
}

bool BigFloat::operator!=(const BigFloat & other) const {
    return mpf_cmp(fp, other.fp) != 0;
}

bool BigFloat::operator<=(const BigFloat & other) const {
    return mpf_cmp(fp, other.fp) <= 0;
}

bool BigFloat::operator>=(const BigFloat & other) const {
    return mpf_cmp(fp, other.fp) >= 0;
}

int BigFloat::get_precision() const {
    return mpf_get_prec(fp);
}

std::string BigFloat::to_string() const {
    char* str;
    gmp_asprintf(&str, ("%." + std::to_string(get_precision()) + "Ff").c_str(), fp);
    std::string result(str);
    free(str);
    return result;
}

double BigFloat::to_double() const {
    return mpf_get_d(fp);
}

const mpf_t & BigFloat::get() const {
    return fp;
}

std::ostream & operator<<(std::ostream & stream, const BigFloat & bf) {
    stream << bf.to_string();
    return stream;
}

std::istream & operator>>(std::istream & stream, BigFloat & bf) {
    std::string value;
    stream >> value;
    bf = value.c_str();
    return stream;
}
