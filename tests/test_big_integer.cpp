//
// Created by karlosss on 11/7/24.
//

#include "gtest/gtest.h"

#include "gmpwrap.h"

TEST(BigIntegerInitialization, Empty) {
    BigInteger i;
}

TEST(BigIntegerInitialization, FromInteger) {
    BigInteger i(69);

    EXPECT_EQ(69, i.to_int());
    EXPECT_EQ("69", i.to_string());
}

TEST(BigIntegerInitialization, FromStringSmall) {
    BigInteger i("69");

    EXPECT_EQ(69, i.to_int());
    EXPECT_EQ("69", i.to_string());
}

TEST(BigIntegerInitialization, FromStringLarge) {
    BigInteger i("3000000000");

    EXPECT_EQ(-1294967296, i.to_int());
    EXPECT_EQ("3000000000", i.to_string());
}

TEST(BigIntegerAssignment, Integer) {
    BigInteger i;
    i = 69;

    EXPECT_EQ(69, i.to_int());
    EXPECT_EQ("69", i.to_string());
}

TEST(BigIntegerAssignment, StringSmall) {
    BigInteger i;
    i = "69";

    EXPECT_EQ(69, i.to_int());
    EXPECT_EQ("69", i.to_string());
}

TEST(BigIntegerAssignment, StringLarge) {
    BigInteger i;
    i = "3000000000";

    EXPECT_EQ(-1294967296, i.to_int());
    EXPECT_EQ("3000000000", i.to_string());
}

TEST(BigIntegerAssignment, BigInteger) {
    BigInteger other("3000000000");
    BigInteger i;
    i = other;

    EXPECT_EQ(-1294967296, i.to_int());
    EXPECT_EQ("3000000000", i.to_string());
}

TEST(BigIntegerArithmetics, PlusEqual) {
    BigInteger other("3000000000");
    BigInteger i(69);
    i += other;

    EXPECT_EQ(-1294967227, i.to_int());
    EXPECT_EQ("3000000069", i.to_string());
}

TEST(BigIntegerArithmetics, MinusEqual) {
    BigInteger other("3000000069");
    BigInteger i(69);
    i -= other;

    EXPECT_EQ(1294967296, i.to_int());
    EXPECT_EQ("-3000000000", i.to_string());
}

TEST(BigIntegerArithmetics, MulEqual) {
    BigInteger other(1000000);
    BigInteger i(1000000);
    i *= other;

    EXPECT_EQ(-727379968, i.to_int());
    EXPECT_EQ("1000000000000", i.to_string());
}

TEST(BigIntegerArithmetics, DivEqual) {
    BigInteger other("3000000000");
    BigInteger i("3000000000");
    i /= other;

    EXPECT_EQ(1, i.to_int());
    EXPECT_EQ("1", i.to_string());
}

TEST(BigIntegerArithmetics, DivEqualWithRemainder) {
    BigInteger other("3000000001");
    BigInteger i("3000000000");
    i /= other;

    EXPECT_EQ(0, i.to_int());
    EXPECT_EQ("0", i.to_string());
}

TEST(BigIntegerArithmetics, Plus) {
    BigInteger other("3000000000");
    BigInteger i(69);
    BigInteger result = i + other;

    EXPECT_EQ(-1294967227, result.to_int());
    EXPECT_EQ("3000000069", result.to_string());
}

TEST(BigIntegerArithmetics, Minus) {
    BigInteger other("3000000069");
    BigInteger i(69);
    BigInteger result = i - other;

    EXPECT_EQ(1294967296, result.to_int());
    EXPECT_EQ("-3000000000", result.to_string());
}

TEST(BigIntegerArithmetics, Mul) {
    BigInteger other(1000000);
    BigInteger i(1000000);
    BigInteger result = i * other;

    EXPECT_EQ(-727379968, result.to_int());
    EXPECT_EQ("1000000000000", result.to_string());
}

TEST(BigIntegerArithmetics, MulByInteger) {
    BigInteger other(1000000);
    int i = 1000000;
    BigInteger result = other * i;

    EXPECT_EQ(-727379968, result.to_int());
    EXPECT_EQ("1000000000000", result.to_string());
}

TEST(BigIntegerArithmetics, Div) {
    BigInteger other("3000000000");
    BigInteger i("3000000000");
    BigInteger result = i / other;

    EXPECT_EQ(1, result.to_int());
    EXPECT_EQ("1", result.to_string());
}

TEST(BigIntegerArithmetics, DivWithRemainder) {
    BigInteger other("3000000001");
    BigInteger i("3000000000");
    BigInteger result = i / other;

    EXPECT_EQ(0, result.to_int());
    EXPECT_EQ("0", result.to_string());
}

TEST(BigIntegerComparison, LessThanTrue) {
    BigInteger other("3000000001");
    BigInteger i("3000000000");

    EXPECT_TRUE(i < other);
}

TEST(BigIntegerComparison, LessThanFalse) {
    BigInteger other("3000000000");
    BigInteger i("3000000001");

    EXPECT_FALSE(i < other);
}

TEST(BigIntegerComparison, GreaterThanTrue) {
    BigInteger other("3000000000");
    BigInteger i("3000000001");

    EXPECT_TRUE(i > other);
}

TEST(BigIntegerComparison, GreaterThanFalse) {
    BigInteger other("3000000001");
    BigInteger i("3000000000");

    EXPECT_FALSE(i > other);
}

TEST(BigIntegerComparison, EqualTrue) {
    BigInteger other("3000000000");
    BigInteger i("3000000000");

    EXPECT_TRUE(i == other);
}

TEST(BigIntegerComparison, EqualFalse) {
    BigInteger other("3000000001");
    BigInteger i("3000000000");

    EXPECT_FALSE(i == other);
}

TEST(BigIntegerComparison, NotEqualTrue) {
    BigInteger other("3000000001");
    BigInteger i("3000000000");

    EXPECT_TRUE(i != other);
}

TEST(BigIntegerComparison, NotEqualFalse) {
    BigInteger other("3000000000");
    BigInteger i("3000000000");

    EXPECT_FALSE(i != other);
}

TEST(BigIntegerComparison, LessThanOrEqualLessThanTrue) {
    BigInteger other("3000000001");
    BigInteger i("3000000000");

    EXPECT_TRUE(i <= other);
}

TEST(BigIntegerComparison, LessThanOrEqualEqualTrue) {
    BigInteger other("3000000000");
    BigInteger i("3000000000");

    EXPECT_TRUE(i <= other);
}

TEST(BigIntegerComparison, LessThanOrEqualFalse) {
    BigInteger other("3000000000");
    BigInteger i("3000000001");

    EXPECT_FALSE(i <= other);
}

TEST(BigIntegerComparison, GreaterThanOrEqualGreaterThanTrue) {
    BigInteger other("3000000000");
    BigInteger i("3000000001");

    EXPECT_TRUE(i >= other);
}

TEST(BigIntegerComparison, GreaterThanOrEqualEqualTrue) {
    BigInteger other("3000000000");
    BigInteger i("3000000000");

    EXPECT_TRUE(i >= other);
}

TEST(BigIntegerComparison, GreaterThanOrEqualFalse) {
    BigInteger other("3000000001");
    BigInteger i("3000000000");

    EXPECT_FALSE(i >= other);
}
