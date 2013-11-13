#ifndef POLYNOMIALFUNCTION_H
#define POLYNOMIALFUNCTION_H

#include <vector>
#include "function.h"

class PolynomialFunction : public Function
{
public:
    PolynomialFunction(unsigned int degree);

    Complex operator()(const Complex &input) const;

    unsigned int getDegree() const;

    Complex getCoeff(unsigned int degree) const;
    bool setCoeff(unsigned int degree,
                  const Complex &coeff);
    bool setCoeff(unsigned int degree,
                  const Real &x,
                  const Real &y);

    const Complex *getRawCoeffs() const;
    Complex *getRawCoeffs();

private:
    std::vector<Complex> m_coeffs;
};

#endif // POLYNOMIALFUNCTION_H
