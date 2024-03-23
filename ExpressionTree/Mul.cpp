#include"Mul.h"
#include"Add.h"

Mul::Mul(std::shared_ptr<Node> left, std::shared_ptr<Node> right) : OperatorNodes{ left, right } {
}

std::ostream& Mul::print(std::ostream& out) const {
	out << "(" << getLeft() << " * " << getRight() << ")";
	return out;
}

double Mul::evaluate() const {
	return getLeft()->evaluate() * getRight()->evaluate();
}

std::shared_ptr<Node> Mul::derivative(std::string var) const {
	return std::make_shared<Add>(std::make_shared<Mul>(getLeft()->derivative(var), getRight()), std::make_shared<Mul>(getLeft(), getRight()->derivative(var)));
}