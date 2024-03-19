#include"Add.h"

Add::Add(std::shared_ptr<Node> left, std::shared_ptr<Node> right) : Node{ "+" }, leftPtr(left), rightPtr(right) {
}

std::ostream& Add::print(std::ostream& out) const {
	out << "(" << leftPtr << " + " << rightPtr << ")";
	return out;
}

double Add::evaluate() const {
	return leftPtr->evaluate() + rightPtr->evaluate();
}

std::shared_ptr<Node> Add::derivative(std::string var) const {
	return std::make_shared<Add>(leftPtr->derivative(var), rightPtr->derivative(var));
}