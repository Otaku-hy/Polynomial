#include "Polynomial.hpp"

namespace PolynomialProject
{

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
    while (traverse_ptr)
    {
        std::cout << ", " << traverse_ptr->coef << ":" << traverse_ptr->expo;
        traverse_ptr = traverse_ptr->next;
    }
    std::cout << std::endl;
}

void Polynomial::InsertNode(const PolynomialNode::SharedPtr &node)
{
    if(node->coef == 0) return;

    if (IsEmpty())
    {
        head_node_->next = node;
        poly_size_ ++;
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
        poly_size_ ++;
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
            poly_size_ ++;
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
    PolynomialNode::SharedPtr others_traverse_ptr = other.head_node_->next;
    PolynomialNode::SharedPtr this_traverse_ptr = head_node_->next;
    Polynomial result;
    result.head_node_->next = nullptr;
    result.poly_size_ = 0;
    PolynomialNode::SharedPtr result_traverse_ptr = result.head_node_;

    while(this_traverse_ptr && others_traverse_ptr)
    {
        if(this_traverse_ptr->expo == others_traverse_ptr->expo)
        {
            if((this_traverse_ptr->coef+others_traverse_ptr->coef)==0)
            {
                this_traverse_ptr = this_traverse_ptr->next;
                others_traverse_ptr = others_traverse_ptr->next;
                continue;
            }
            else
            {
                result_traverse_ptr->next = std::make_shared<PolynomialNode>(this_traverse_ptr->expo,this_traverse_ptr->coef + others_traverse_ptr->coef);
                result_traverse_ptr = result_traverse_ptr->next;
                this_traverse_ptr = this_traverse_ptr->next;
                others_traverse_ptr = others_traverse_ptr->next;
                result.poly_size_++;
                continue;
            }
        }
        else if(this_traverse_ptr->expo > others_traverse_ptr->expo)
        {
            result_traverse_ptr->next = std::make_shared<PolynomialNode>(this_traverse_ptr->expo,this_traverse_ptr->coef);
            result_traverse_ptr = result_traverse_ptr->next;
            this_traverse_ptr = this_traverse_ptr->next;
            result.poly_size_++;
            continue;
        }
        else if(this_traverse_ptr->expo < others_traverse_ptr->expo)
        {
            result_traverse_ptr->next = std::make_shared<PolynomialNode>(others_traverse_ptr->expo,others_traverse_ptr->coef);
            result_traverse_ptr = result_traverse_ptr->next;
            others_traverse_ptr = others_traverse_ptr->next;
            result.poly_size_++;
            continue;
        }
    }
    if(!this_traverse_ptr && others_traverse_ptr)
    {
        while(others_traverse_ptr)
        {
            result_traverse_ptr->next = std::make_shared<PolynomialNode>(others_traverse_ptr->expo,others_traverse_ptr->coef);
            result_traverse_ptr = result_traverse_ptr->next;
            others_traverse_ptr = others_traverse_ptr->next;
            result.poly_size_++;
        }
    }
    else if(this_traverse_ptr && !others_traverse_ptr)
    {
        while (this_traverse_ptr)
        {
            result_traverse_ptr->next = std::make_shared<PolynomialNode>(this_traverse_ptr->expo,this_traverse_ptr->coef);
            result_traverse_ptr = result_traverse_ptr->next;
            this_traverse_ptr = this_traverse_ptr->next;
            result.poly_size_++;
        }
    }
    return result;
}

Polynomial Polynomial::operator-(const Polynomial &other)
{
    PolynomialNode::SharedPtr others_traverse_ptr = other.head_node_->next;
    PolynomialNode::SharedPtr this_traverse_ptr = head_node_->next;
    Polynomial result;
    result.head_node_->next = nullptr;
    result.poly_size_ = 0;
    PolynomialNode::SharedPtr result_traverse_ptr = result.head_node_;
    while(this_traverse_ptr && others_traverse_ptr)
    {
        if(this_traverse_ptr->expo==others_traverse_ptr->expo)
        {
            if((this_traverse_ptr->coef - others_traverse_ptr->coef)==0){
                this_traverse_ptr = this_traverse_ptr->next;
                others_traverse_ptr = others_traverse_ptr->next;
                continue;
            }
            else
            {
                result_traverse_ptr->next = std::make_shared<PolynomialNode>(this_traverse_ptr->expo,this_traverse_ptr->coef-others_traverse_ptr->coef);
                result_traverse_ptr = result_traverse_ptr->next;
                this_traverse_ptr = this_traverse_ptr->next;
                others_traverse_ptr = others_traverse_ptr->next;
                result.poly_size_++;
                continue;
            }
        }
        else if(this_traverse_ptr->expo > others_traverse_ptr->expo)
        {
            result_traverse_ptr->next = std::make_shared<PolynomialNode>(this_traverse_ptr->expo,this_traverse_ptr->coef);
            result_traverse_ptr = result_traverse_ptr->next;
            this_traverse_ptr = this_traverse_ptr->next;
            result.poly_size_++;
            continue;
        }
        else if(others_traverse_ptr->expo > this_traverse_ptr->expo)
        {
            result_traverse_ptr->next = std::make_shared<PolynomialNode>(others_traverse_ptr->expo,(-1)*others_traverse_ptr->coef);
            result_traverse_ptr = result_traverse_ptr->next;
            others_traverse_ptr = others_traverse_ptr->next;
            result.poly_size_++;
            continue;
        }
    }
    if (this_traverse_ptr && !others_traverse_ptr)
    {
        while(this_traverse_ptr)
        {
            result_traverse_ptr->next = std::make_shared<PolynomialNode>(this_traverse_ptr->expo,this_traverse_ptr->coef);
            result_traverse_ptr = result_traverse_ptr->next;
            this_traverse_ptr = result_traverse_ptr->next;
            result.poly_size_++;
        }
    }
    else if(!this_traverse_ptr && others_traverse_ptr)
    {
        while(others_traverse_ptr)
        {
            result_traverse_ptr->next = std::make_shared<PolynomialNode>(others_traverse_ptr->expo,(-1)*others_traverse_ptr->coef);
            result_traverse_ptr = result_traverse_ptr->next;
            others_traverse_ptr = others_traverse_ptr->next;
            result.poly_size_++;
        }
    }
    return result;
}

double Polynomial::Value(double x){
    PolynomialNode::SharedPtr value_traverse_ptr = head_node_->next;
    double result = 0;
    while(value_traverse_ptr)
    {
        result += value_traverse_ptr->coef*(pow(x,value_traverse_ptr->expo));
        value_traverse_ptr = value_traverse_ptr->next;
    }
    return result;
}

} //Polynomail