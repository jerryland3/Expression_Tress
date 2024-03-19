#include"Sub.h"

Sub::Sub(std::shared_ptr<Node> left, std::shared_ptr<Node> right) : Node{ "-" }, leftPtr(left), rightPtr(right) {
}

std::ostream& Sub::print(std::ostream& out) const {
	out << "(" << leftPtr << " - " << rightPtr << ")";
	return out;
}

double Sub::evaluate() const {
	return leftPtr->evaluate() - rightPtr->evaluate();
}

std::shared_ptr<Node> Sub::derivative(std::string var) const {
	return std::make_shared<Sub>(leftPtr->derivative(var), rightPtr->derivative(var));
}