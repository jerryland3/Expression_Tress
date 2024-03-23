#include"Add.h"

Add::Add(std::shared_ptr<Node> left, std::shared_ptr<Node> right) : OperatorNodes(left, right) {
}

std::ostream& Add::print(std::ostream& out) const {
	out << "(" << getLeft() << " + " << getRight() << ")";
	return out;
}

double Add::evaluate() const {
	return getLeft()->evaluate() + getRight()->evaluate();
}

std::shared_ptr<Node> Add::derivative(std::string var) const {
	return std::make_shared<Add>(getLeft()->derivative(var), getRight()->derivative(var));
}