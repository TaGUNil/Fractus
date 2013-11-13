#include "polynomialfunction.h"

PolynomialFunction::PolynomialFunction(unsigned int degree) :
    m_coeffs(degree + 1, 0.0)
{
}

Complex PolynomialFunction::operator()(const Complex &input) const
{
    Complex accum = 1.0;
    Complex output = 0.0;

    for (size_t i = 0; i < m_coeffs.size(); i++)
    {
        output += m_coeffs[i] * accum;
        accum *= input;
    }

    return output;
}

unsigned int PolynomialFunction::getDegree() const
{
    return m_coeffs.size() - 1;
}

Complex PolynomialFunction::getCoeff(unsigned int degree) const
{
    if (degree >= m_coeffs.size())
    {
        return 0.0;
    }

    return m_coeffs[degree];
}

bool PolynomialFunction::setCoeff(unsigned int degree,
                                  const Complex &coeff)
{
    if (degree >= m_coeffs.size())
    {
        return false;
    }

    m_coeffs[degree] = coeff;

    return true;
}

bool PolynomialFunction::setCoeff(unsigned int degree,
                                  const Real &x,
                                  const Real &y)
{
    return setCoeff(degree, Complex(x, y));
}

const Complex *PolynomialFunction::getRawCoeffs() const
{
    return m_coeffs.data();
}

Complex *PolynomialFunction::getRawCoeffs()
{
    return m_coeffs.data();
}
