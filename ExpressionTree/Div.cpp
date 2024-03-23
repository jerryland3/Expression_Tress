#include"Div.h"
#include"Mul.h"
#include"Sub.h"

Div::Div(std::shared_ptr<Node> left, std::shared_ptr<Node> right) : OperatorNodes{ left, right } {
}

void Div::setRight(std::shared_ptr<Node> right) {
	// make sure right is not zero
	if (right->evaluate() == 0) {
		throw std::invalid_argument("Divisor cannot be zero");
	}
	OperatorNodes::setRight(right);
}

std::ostream& Div::print(std::ostream& out) const {
	out << "(" << getLeft() << " / " << getRight() << ")";
	return out;
}

double Div::evaluate() const {
	return getLeft()->evaluate() / getRight()->evaluate();
}

std::shared_ptr<Node> Div::derivative(std::string var) const {
	return std::make_shared<Div>(std::make_shared<Sub>(std::make_shared<Mul>(getLeft()->derivative(var), getRight()), std::make_shared<Mul>(getLeft(), getRight()->derivative(var))), std::make_shared<Mul>(getRight(), getRight()));
}