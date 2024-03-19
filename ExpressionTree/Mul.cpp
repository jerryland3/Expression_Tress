#include"Mul.h"
#include"Add.h"

Mul::Mul(std::shared_ptr<Node> left, std::shared_ptr<Node> right) : Node{ "*" }, leftPtr(left), rightPtr(right) {
}

std::ostream& Mul::print(std::ostream& out) const {
	out << "(" << leftPtr << " * " << rightPtr << ")";
	return out;
}

double Mul::evaluate() const {
	return leftPtr->evaluate() * rightPtr->evaluate();
}

std::shared_ptr<Node> Mul::derivative(std::string var) const {
	return std::make_shared<Add>(std::make_shared<Mul>(leftPtr->derivative(var), rightPtr), std::make_shared<Mul>(leftPtr, rightPtr->derivative(var)));
}