#if !defined (RATIONAL_HPP)
#define RATIONAL_HPP

// ERROR LIST
#define ZERO_DIVISION (-1)


class Rational {

private:
    int _numerator, _denominator; // That's all we need to make any rational :)
    double _value;                // double representation
    void _recalculate();          // recalculate value
    void _rexpand();              // re-expand the value to calculate nume&denomi

public:
    Rational(int numerator, int denominator);   // construct via n&d
    Rational(double value);                     // and via double
    Rational();                                 // default value is 0
    double set(int numerator, int denominator); // set via n&m
    double set(double value);                   // set via double
    double value() const;                       // get value
    int getNumerator() const;                   // nume getter
    int getDenominator() const;                 // denomin getter
    operator float() const;                     // cast operator
						// ALL POSSIBLE OPERATORS OVERLOADED
    Rational operator +(const Rational& other) const;
    Rational operator /(const Rational& other) const;
    Rational operator -(const Rational& other) const;
    Rational operator *(const Rational& other) const;
    Rational operator +(double other) const;
    Rational operator /(double other) const;
    Rational operator -(double other) const;
    Rational operator *(double other) const;
    Rational operator -() const;
    friend Rational operator+(double d, const Rational &r);
    friend Rational operator-(double d, const Rational &r);
    friend Rational operator*(double d, const Rational &r);
    friend Rational operator/(double d, const Rational &r);

    void printf(); // printFraction
    void print();  // print decimal expantion

};

// Friend operator functions signature
Rational operator+(double d, const Rational &r);
Rational operator-(double d, const Rational &r);
Rational operator*(double d, const Rational &r);
Rational operator/(double d, const Rational &r);

#endif // RATIONAL_INCLUDED
