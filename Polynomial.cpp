#include "Polynomial.hpp"

Polynomial::Polynomial(/* args */)
{
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