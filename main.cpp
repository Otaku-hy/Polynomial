#include "InputParser.hpp"
#include "Polynomial.hpp"

using namespace PolynomialProject;

int main()
{
    InputParser inputParser;
    auto pool = inputParser.UpdatePolynomialData();
    auto val1 = pool["p1"];
    auto val2 = pool["p2"];

    auto val = *val1 - *val2;
    val.PrintPolynomial();
    val1->PrintPolynomial();
    std::cout << "   "<<val.Value(2);
}