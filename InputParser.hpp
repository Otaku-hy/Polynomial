#ifndef InputParser_H_
#define InputParser_H_

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <memory>
#include <assert.h>
#include <map>

#include "Polynomial.hpp"

namespace PolynomialProject
{

class InputParser
{
private:
    std::string file_name_ = "PolynomialInput.txt";

public:
    using SharedPtr = std::shared_ptr<InputParser>;

    InputParser(/* args */);
    ~InputParser();

    std::map<std::string,Polynomial::SharedPtr> UpdatePolynomialData();
    std::pair<std::string,Polynomial::SharedPtr> ParseInputPolynomial(std::fstream& file);
};

} //Polynomial 

#endif