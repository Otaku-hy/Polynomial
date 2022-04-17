#include "Polynomial.hpp"

Polynomial::Polynomial(/* args */)
{
}

Polynomial::Polynomial(const Polynomial &other) : poly_size_(other.poly_size_)
{
    head_node_ = std::make_shared<PolynomialNode>();
    PolynomialNode::SharedPtr this_traverse_ptr = head_node_;
    PolynomialNode::SharedPtr other_traverse_ptr = other.head_node_->next;
    while (other_traverse_ptr)
    {
        this_traverse_ptr->next = std::make_shared<PolynomialNode>(other_traverse_ptr->expo, other_traverse_ptr->coef);
        this_traverse_ptr = this_traverse_ptr->next;
        other_traverse_ptr = other_traverse_ptr->next;
    }
}

Polynomial::~Polynomial()
{
}

bool Polynomial::IsEmpty()
{
    if (!head_node_->next)
        return true;
    return false;
}

void Polynomial::PrintPolynomial()
{
    std::cout << poly_size_;
    PolynomialNode::SharedPtr traverse_ptr = head_node_->next;
    while (!traverse_ptr)
    {
        std::cout << "," << traverse_ptr->coef << "," << traverse_ptr->expo;
        traverse_ptr = traverse_ptr->next;
    }
}

void Polynomial::InsertNode(const PolynomialNode::SharedPtr &node)
{
    if (IsEmpty())
    {
        head_node_->next = node;
        return;
    }

    PolynomialNode::SharedPtr traverse_pre_ptr = head_node_;
    PolynomialNode::SharedPtr traverse_ptr = head_node_->next;

    while (traverse_ptr && traverse_ptr->expo > node->expo)
    {
        traverse_ptr = traverse_ptr->next;
        traverse_pre_ptr = traverse_pre_ptr->next;
    }
    if (!traverse_ptr)
    {
        traverse_pre_ptr->next = node;
    }
    else
    {
        if (traverse_ptr->expo == node->expo)
        {
            traverse_ptr->coef += node->coef;
        }
        else
        {
            node->next = traverse_ptr;
            traverse_pre_ptr->next = node;
        }
    }
}

Polynomial &Polynomial::operator=(const Polynomial &other)
{
    head_node_->next = nullptr;
    poly_size_ = other.poly_size_;

    PolynomialNode::SharedPtr this_traverse_ptr = head_node_;
    PolynomialNode::SharedPtr other_traverse_ptr = other.head_node_->next;
    while (other_traverse_ptr)
    {
        this_traverse_ptr->next = std::make_shared<PolynomialNode>(other_traverse_ptr->expo, other_traverse_ptr->coef);
        this_traverse_ptr = this_traverse_ptr->next;
        other_traverse_ptr = other_traverse_ptr->next;
    }

    return *this;
}

Polynomial Polynomial::operator+(const Polynomial &other)
{
    PolynomialNode::SharedPtr others_travese_ptr = other.head_node_->next;
    Polynomial result(*this);

    
}