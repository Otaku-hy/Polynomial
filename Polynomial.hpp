#include <iostream>
#include <memory>

struct PolynomialNode
{
    using SharedPtr = std::shared_ptr<PolynomialNode>;

    double expo = 0;
    uint32_t coef = 0;
    SharedPtr next = nullptr;
};

class Polynomial
{
private:
    size_t poly_size_ = 0;
    PolynomialNode::SharedPtr head_node_ = nullptr;

public:
    using SharedPtr = std::shared_ptr<Polynomial>;

    Polynomial(/* args */);
    ~Polynomial();

    bool IsEmpty();
    void PrintPolynomial();
    void InsertNode(const PolynomialNode::SharedPtr& node);
};
