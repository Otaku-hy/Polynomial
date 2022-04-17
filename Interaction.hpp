#ifndef Interaction_H_
#define Interaction_H_

#include <iostream>
#include <cstdint>
#include <map>
#include <string>
#include <sstream>

#include "InputParser.hpp"
#include "Polynomial.hpp"

namespace PolynomialProject
{

    class Interaction
    {
    private:
        uint32_t interactive_option_;
        std::map<std::string, Polynomial::SharedPtr> polynomials_pool_;
        InputParser inputParser_;

    public:
        Interaction();
        ~Interaction();

        void InteractiveOperation();
        void UpdatePolynomials();
        void AddPolynomials();
        void MinusPolynomials();
        void ComputeValue();
    };
}

#endif