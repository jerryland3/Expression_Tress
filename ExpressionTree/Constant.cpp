#include"Constant.h"

using namespace std;

Constant::Constant(double value) : Node(), value{ value } {
}

void Constant::setConstant(double value) {
	this->value = value;
}

shared_ptr<Node> Constant::derivative(string var) const {
	return std::make_shared<Constant>(0);
}

ostream& Constant::print(ostream& out) const {
	out << value;
	return out;
}

double Constant::evaluate() const {
	return value;
}