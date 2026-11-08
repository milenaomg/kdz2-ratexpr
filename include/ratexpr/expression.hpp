#pragma once
#include <memory>
#include <ostream>
#include "ratexpr/fraction.hpp"
#include <utility>

namespace ratexpr {

class Expression {
public:
    virtual ~Expression() = default;
    virtual Fraction evaluate() const = 0;
    virtual void print(std::ostream& os) const = 0;
};

inline std::ostream& operator<<(std::ostream& os, const Expression& e) {
    e.print(os);
    return os;
};

class Const : public Expression {
public:
    explicit Const(const Fraction& value) {
        valuee = value;
    }
    Fraction evaluate() const override {
        return valuee;
    }
    void print(std::ostream& os) const override {
        os << valuee;
    }
    private:
        Fraction valuee;
};

class Negative : public Expression {
public:
    explicit Negative(std::unique_ptr<Expression> operand) {
        operandd = std::move(operand);
    }
    Fraction evaluate() const override {
        return -operandd->evaluate();
    }
    void print(std::ostream& os) const override {
        os << "(-";
        operandd->print(os);
        os << ")";
    }
private:
    std::unique_ptr<Expression> operandd;
};

class BinaryExpression : public Expression {
public:
    BinaryExpression(std::unique_ptr<Expression> lhs,
                     std::unique_ptr<Expression> rhs) {
        left = std::move(lhs);
        right = std::move(rhs);
    }
protected:
    std::unique_ptr<Expression> left;
    std::unique_ptr<Expression> right;
};

class Add : public BinaryExpression { 
    public: 
        using BinaryExpression::BinaryExpression;
        Fraction evaluate() const override {
            return left->evaluate() + right->evaluate();
        }
        void print(std::ostream& os) const override {
            os << "(";
            left->print(os);
            os << " + ";
            right->print(os);
            os << ")";
        }
};

class Sub : public BinaryExpression { 
    public: 
        using BinaryExpression::BinaryExpression;
        Fraction evaluate() const override {
            return left->evaluate() - right->evaluate();
        }
        void print(std::ostream& os) const override {
            os << "(";
            left->print(os);
            os << " - ";
            right->print(os);
            os << ")";
        }
};

class Mul : public BinaryExpression { 
    public: 
        using BinaryExpression::BinaryExpression;
        Fraction evaluate() const override {
            return left->evaluate() * right->evaluate();
        }
        void print(std::ostream& os) const override {
            os << "(";
            left->print(os);
            os << " * ";
            right->print(os);
            os << ")";
        }
};

class Div : public BinaryExpression { 
    public: 
        using BinaryExpression::BinaryExpression;
        Fraction evaluate() const override {
            return left->evaluate() / right->evaluate();
        }
        void print(std::ostream& os) const override {
            os << "(";
            left->print(os);
            os << " / ";
            right->print(os);
            os << ")";
        }
};


}; 