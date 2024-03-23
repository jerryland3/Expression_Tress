#pragma once
#include<string>
#include"Node.h"

class Constant : public Node {
private:
	double value;
	virtual std::ostream& print(std::ostream& out) const override;

public:
	Constant(double value);
	virtual ~Constant() = default;

	virtual std::shared_ptr<Node> derivative(std::string var) const override;
	virtual double evaluate() const override;
	void setConstant(double value);
};
