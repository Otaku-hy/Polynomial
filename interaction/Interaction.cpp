#include "Interaction.hpp"

namespace PolynomialProject
{
    Interaction::Interaction() : interactive_option_(),inputParser_(InputParser())
    {
    }

    Interaction::~Interaction()
    {

    }

    void Interaction::InteractiveOperation()
    {
        UpdatePolynomials();

        while (std::cin >> interactive_option_, interactive_option_ != "6")
        {
            if (interactive_option_ == "1")
            {
                UpdatePolynomials();
                std::cout <<"update success!"<<std::endl;
            }
            else if (interactive_option_ == "2")
            {
                std::string poly_name;
                std::cin >> poly_name;
                if (polynomials_pool_.find(poly_name) == polynomials_pool_.end())
                {
                    std::cout << "wrong name, please check your input\n";
                    continue;
                }
                polynomials_pool_[poly_name]->PrintPolynomial();
            }
            else if (interactive_option_ == "3")
            {
                AddPolynomials();
            }
            else if (interactive_option_ == "4")
            {
                MinusPolynomials();
            }
            else if (interactive_option_ == "5")
            {
                ComputeValue();
            }
            else
            {
                std::cout << "Unsupported operator";
                continue;
            }
        }
    }

    void Interaction::UpdatePolynomials()
    {
        polynomials_pool_ = inputParser_.UpdatePolynomialData();
    }

    void Interaction::AddPolynomials()
    {
        std::string option_expression, poly_final, pa, pb;
        getline(std::cin,option_expression);
        getline(std::cin,option_expression);
        std::string holder;

        if (option_expression.find("=") < option_expression.size())
        {
            std::stringstream expression(option_expression);
            expression >> poly_final;
            expression >> holder;
            expression >> pa;
            expression >> holder;
            expression >> pb;

            if (polynomials_pool_.find(pa) == polynomials_pool_.end() || polynomials_pool_.find(pb) == polynomials_pool_.end())
            {
                std::cout << "invalid poly_name";
                return;
            }
            Polynomial::SharedPtr poly_ptr = std::make_shared<Polynomial>(*polynomials_pool_[pa] + *polynomials_pool_[pb]);

            if (polynomials_pool_.find(poly_final) != polynomials_pool_.end())
            {
                polynomials_pool_[poly_final] = poly_ptr;
            }
            else
            {
                polynomials_pool_.insert(std::pair<std::string, Polynomial::SharedPtr>(poly_final, poly_ptr));
            }
            poly_ptr->PrintPolynomial();
        }
        else
        {
            std::stringstream expression(option_expression);
            expression >> holder;
            expression >> pa;
            expression >> pb;
            if (polynomials_pool_.find(pa) == polynomials_pool_.end() || polynomials_pool_.find(pb) == polynomials_pool_.end())
            {
                std::cout << "invalid poly_name";
                return;
            }
            (*polynomials_pool_[pa] + *polynomials_pool_[pb]).PrintPolynomial();
        }
    }

    void Interaction::MinusPolynomials()
    {
        std::string option_expression, poly_final, pa, pb;
        getline(std::cin,option_expression);
        getline(std::cin,option_expression);
        std::string holder;

        if (option_expression.find("=") < option_expression.size())
        {
            std::stringstream expression(option_expression);
            expression >> poly_final;
            expression >> holder;
            expression >> pa;
            expression >> holder;
            expression >> pb;

            if (polynomials_pool_.find(pa) == polynomials_pool_.end() || polynomials_pool_.find(pb) == polynomials_pool_.end())
            {
                std::cout << "invalid poly_name";
                return;
            }
            Polynomial::SharedPtr poly_ptr = std::make_shared<Polynomial>(*polynomials_pool_[pa] - *polynomials_pool_[pb]);

            if (polynomials_pool_.find(poly_final) != polynomials_pool_.end())
            {
                polynomials_pool_[poly_final] = poly_ptr;
            }
            else
            {
                polynomials_pool_.insert(std::pair<std::string, Polynomial::SharedPtr>(poly_final, poly_ptr));
            }
            poly_ptr->PrintPolynomial();
        }
        else
        {
            std::stringstream expression(option_expression);
            expression >> pa;
            expression >> holder;
            expression >> pb;
            if (polynomials_pool_.find(pa) == polynomials_pool_.end() || polynomials_pool_.find(pb) == polynomials_pool_.end())
            {
                std::cout << "invalid poly_name";
                return;
            }
            (*polynomials_pool_[pa] - *polynomials_pool_[pb]).PrintPolynomial();
        }
    }

    void Interaction::ComputeValue()
    {
        std::string poly_name;
        double value_pos;
        std::cin >> poly_name >> value_pos;
        if (polynomials_pool_.find(poly_name) == polynomials_pool_.end())
        {
            std::cout << "wrong name, please check your input\n";
            return;
        }
        std::cout << polynomials_pool_[poly_name]->Value(value_pos);
    }

}