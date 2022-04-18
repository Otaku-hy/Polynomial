#ifndef Polynomial_H_
#define Polynomial_H_

#include <iostream>
#include <memory>
#include <cmath>

namespace PolynomialProject
{

struct PolynomialNode
{
    using SharedPtr = std::shared_ptr<PolynomialNode>;

    int32_t expo = 0;
    double coef = 0;
    SharedPtr next = nullptr;

    PolynomialNode() = default;
    PolynomialNode(int32_t _expo, double _coef) : expo(_expo), coef(_coef), next(nullptr){};
};

class Polynomial
{
private:
    size_t poly_size_ = 0;
    PolynomialNode::SharedPtr head_node_ = std::make_shared<PolynomialNode>();

public:
    using SharedPtr = std::shared_ptr<Polynomial>;

    Polynomial(/* args */);
    Polynomial(const Polynomial &other);
    ~Polynomial();

    bool IsEmpty();
    void PrintPolynomial();
    void InsertNode(const PolynomialNode::SharedPtr &node);

    Polynomial &operator=(const Polynomial &other);
    Polynomial operator+(const Polynomial &other);
    Polynomial operator-(const Polynomial &other);
    double Value(double x);
};

} //Polynomial

#endif