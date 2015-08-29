#include<math.h>
#include<iostream>
#include "rational.hpp"

///////////////////C'TORS///////////////////


// A rational is every a/b where a and b are integers (positive and non-positive)
// Thus, this is a constructor by definition of a rational.
Rational::Rational(int numerator, int denominator) {
    set(numerator, denominator);
}

// A c'tor by value (decimal expantion)
Rational::Rational(double value) {
    set(value);
}

// A c'tor for default number - 0
Rational::Rational() {
    _numerator = 0, _denominator = 1;
    _value = 0;
    // Better 0 than nothing :P
}

///////////////////GETTERS & SETTERS///////////////////

// Set by numerator/denominator
double Rational::set(int numerator, int denominator) {
    _numerator = numerator, _denominator = denominator;
    _recalculate();
}

// Set by value and expand
double Rational::set(double value) {
    _value = value;
    _rexpand();
}

// get double precision decimal representation
double Rational::value() const{
    return _value;
}

// Get numerator
int Rational::getNumerator() const {
    return _numerator;
}

// Get denominator
int Rational::getDenominator() const {
    return _denominator;
}

// Print decimal expantion
void Rational::print() {
    std::cout<<_value;
}

// Print Fraction ("a/b")
void Rational::printf() {
    std::cout<<_numerator<<"/"<<_denominator<<std::endl;
}

///////////////////PRIVATE///////////////////

// Recalculate decimal expantion
void Rational::_recalculate() {
    if(_denominator != 0) {
        _value = (float)_numerator/_denominator;
    } else
        throw ZERO_DIVISION;
}

// Recalculate numerator and denominator
void Rational::_rexpand() {
    double remainder = 1; // For checking expantion.

    for(_denominator = 1; remainder!=0; _denominator++) {
        remainder = (_value*_denominator)-(int)(_value*_denominator);
    }
    _denominator--;
    _numerator = _value*_denominator;
}

///////////////////OPERATORS///////////////////

// Float casting operator
Rational::operator float() const {
    return (float)_value;
}

// Add two rationals operator
Rational Rational::operator +(const Rational& other) const {
    return Rational(_value+other.value());
}

// divide two rationals operator
Rational Rational::operator /(const Rational& other) const {
    return Rational(_value/other.value());
}

// subtract two rationals operator
Rational Rational::operator -(const Rational& other) const {
    return Rational(_value-other.value());
}

// multiply two rationals operator
Rational Rational::operator *(const Rational& other) const {
    return Rational(_value*other.value());
}

// change sign
Rational Rational::operator -() const {
    return Rational(-_value);
}

///////////////////EXTRA CASES///////////////////


// Add two rationals operator
Rational Rational::operator +(double other) const {
    return Rational(_value+other);
}

// divide two rationals operator
Rational Rational::operator /(double other) const {
    return Rational(_value/other);
}

// subtract two rationals operator
Rational Rational::operator -(double other) const {
    return Rational(_value-other);
}

// multiply two rationals operator
Rational Rational::operator *(double other) const {
    return Rational(_value*other);
}

///////////////////FRIEND FUNCTIONS///////////////////

Rational operator+(double d, const Rational &r) {
    return Rational(d+r.value()); // Commutative operation!
}

Rational operator-(double d, const Rational &r) {
    return Rational(d-r.value());
}

Rational operator*(double d, const Rational &r) {
    return Rational(d*r.value()); // Commutative operation!
}

Rational operator/(double d, const Rational &r) {
    return Rational(d/r.value());
}

