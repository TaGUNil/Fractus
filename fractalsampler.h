#ifndef FRACTALSAMPLER_H
#define FRACTALSAMPLER_H

#include <memory>
#include "sampler.h"
#include "polynomialfunction.h"

class FractalSampler : public Sampler
{
public:
    FractalSampler();

    void setFunction(PolynomialFunction *function);
    bool setDomain(const Complex &bottomLeft,
                   const Complex &topRight);
    void setLimit(const Real &limit);
    void setSteps(Level steps);

protected:
    std::shared_ptr<PolynomialFunction> m_function;
    Complex m_bottomLeft;
    Complex m_topRight;
    Real m_limit;
    Level m_steps;
};

#endif // FRACTALSAMPLER_H
