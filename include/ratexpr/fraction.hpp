#pragma once
#include <cstdint>
#include <iostream>
#include <numeric>
#include <stdexcept>

namespace ratexpr {
class Fraction { 
    public: 
        Fraction() {
            num = 0;
            den = 1;
        }
        Fraction(std::int64_t a, std::int64_t b = 1) {
            if (b == 0) throw std::invalid_argument("zero denominator");
            num = a;
            den = b;
            normaldake();
        }
        std::int64_t Numerator() const {
            return num;
        }
        std::int64_t Denominator() const {
            return den;
        }
        Fraction& operator+=(const Fraction& other) {
            num = num * other.den + other.num * den;
            den = den * other.den;
            normaldake();         
            return *this;
        }
        Fraction& operator-=(const Fraction& other) {
            num = num * other.den - other.num * den;
            den = den * other.den;
            normaldake();         
            return *this;
        }
        Fraction& operator*=(const Fraction& other) {
            num = num * other.num;
            den = den * other.den;
            normaldake();         
            return *this;
        }
        Fraction& operator/=(const Fraction& other) {
            if (other.num == 0) throw std::invalid_argument("division by zero");
            num = num * other.den;
            den = den * other.num;
            normaldake();         
            return *this;
        }
        Fraction operator+() const {
            return Fraction(num, den);
        }
        Fraction operator-() const {
            return Fraction(-num, den);
        }
        Fraction& operator++() {         
            num += den;
            return *this;
        }
        Fraction operator++(int) {
            Fraction old = *this;
            num += den;
            return old;
        }
        Fraction& operator--() {
            num -= den;
            return *this;
        }
        Fraction operator--(int) {
            Fraction old = *this;
            num -= den;
            return old;
        }
        Fraction& operator+=(std::uint32_t k) { 
            return *this += Fraction(k); 
        }
        Fraction& operator-=(std::uint32_t k) { 
            return *this -= Fraction(k); 
        }
        Fraction& operator*=(std::uint32_t k) { 
            return *this *= Fraction(k); 
        }
        Fraction& operator/=(std::uint32_t k) { 
            return *this /= Fraction(k); 
        }
        friend Fraction operator+(const Fraction& a, std::uint32_t k) { 
            return a + Fraction(k); 
        }
        friend Fraction operator+(std::uint32_t k, const Fraction& b) { 
            return Fraction(k) + b; 
        }
        friend Fraction operator+(const Fraction& a, const Fraction& b) {
            Fraction res = a;   
            res += b;         
            return res;
        }

        friend Fraction operator-(const Fraction& a, const Fraction& b) {
            Fraction res = a;   
            res -= b;         
            return res;
        }
        friend Fraction operator-(const Fraction& a, std::uint32_t k) { 
            return a - Fraction(k); 
        }
        friend Fraction operator-(std::uint32_t k, const Fraction& b) { 
            return Fraction(k) - b; 
        }

        friend Fraction operator*(const Fraction& a, const Fraction& b) {
            Fraction res = a;   
            res *= b;         
            return res;
        }
        friend Fraction operator*(const Fraction& a, std::uint32_t k) { 
            return a * Fraction(k); 
        }
        friend Fraction operator*(std::uint32_t k, const Fraction& b) { 
            return Fraction(k) * b; 
        }

        friend Fraction operator/(const Fraction& a, const Fraction& b) {
            Fraction     res = a;   
            res /= b;         
            return res;
        }
        friend Fraction operator/(const Fraction& a, std::uint32_t k) {
            return a / Fraction(k);
        }
        friend Fraction operator/(std::uint32_t k, const Fraction& b) {
            return Fraction(k) / b;
        }
        friend std::ostream& operator<<(std::ostream& os, const Fraction& f) {
            os << f.num;
            if (f.den != 1) os << '/' << f.den;
            return os;
        }
    private: 
        void normaldake() {
            if (den<0) {
                den = den * (-1);
                num = num * (-1);
            }
            std::int64_t gg = std::gcd(num, den);
            den = den / gg;  
            num = num / gg;
        }
        std::int64_t num, den;
};



inline bool operator==(const Fraction& a, const Fraction& b) {
    return a.Numerator() == b.Numerator() and a.Denominator() == b.Denominator();
}
inline bool operator!=(const Fraction& a, const Fraction& b) {
    return !(a == b);
}
}