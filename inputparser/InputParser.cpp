#include "InputParser.hpp"

namespace PolynomialProject
{
    InputParser::InputParser(/* args */)
    {
    }

    InputParser::~InputParser()
    {
    }

    std::map<std::string, Polynomial::SharedPtr> InputParser::UpdatePolynomialData()
    {
        std::map<std::string, Polynomial::SharedPtr> polynomial_pool;
        std::fstream file(file_name_);
        std::string line;
        while (getline(file, line))
        {
            if (line == "#BEGIN_POLYNOMIAL")
            {
                auto poly = ParseInputPolynomial(file);
                auto pos_in_pool = polynomial_pool.find(poly.first);
                if (pos_in_pool != polynomial_pool.end())
                {
                    pos_in_pool->second = poly.second;
                }
                else
                {                 
                    polynomial_pool.insert(poly);
                }
            }
        }
        return polynomial_pool;
    }

    std::pair<std::string, Polynomial::SharedPtr> InputParser::ParseInputPolynomial(std::fstream &file)
    {
        std::string line;
        std::string poly_name = "default";
        Polynomial::SharedPtr polynomial_ptr = std::make_shared<Polynomial>();
        while (getline(file, line))
        {
            if (line == "#END_POLYNOMIAL")
            {
                return std::pair<std::string, Polynomial::SharedPtr>(poly_name, polynomial_ptr);
            }
            else
            {
                std::stringstream line_stream(line);
                std::string word;
                int32_t expo;
                double coef;
                line_stream >> word;
                if (word == "#name:")
                {
                    line_stream >> poly_name;
                }
                else
                {
                    if (word.find_first_not_of("-0123456789.") < word.size())
                    {
                        assert("unsupported data");
                    }
                    else
                    {
                        expo = std::stoi(word);
                        line_stream >> word;
                        
                        if (word.find_first_not_of("-0123456789.") < word.size())
                           assert("unsupported data");
                        else
                        {
                            coef = std::stod(word);
                        }

                    }
                    polynomial_ptr->InsertNode(std::make_shared<PolynomialNode>(expo, coef));
                }
            }
        }
        assert("Expect expression : #END_POLYNOMIAL");
    }

} // Polynomail