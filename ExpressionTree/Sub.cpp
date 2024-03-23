#include"Sub.h"

Sub::Sub(std::shared_ptr<Node> left, std::shared_ptr<Node> right) : OperatorNodes{ left, right } {
}

std::ostream& Sub::print(std::ostream& out) const {
	out << "(" << getLeft() << " - " << getRight() << ")";
	return out;
}

double Sub::evaluate() const {
	return getLeft()->evaluate() - getRight()->evaluate();
}

std::shared_ptr<Node> Sub::derivative(std::string var) const {
	return std::make_shared<Sub>(getLeft()->derivative(var), getRight()->derivative(var));
}