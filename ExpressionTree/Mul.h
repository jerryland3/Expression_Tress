#pragma once
#include"OperatorNodes.h"

class Mul : public OperatorNodes {
private:
	virtual std::ostream& print(std::ostream& out) const override;

public:
	Mul(std::shared_ptr<Node> left, std::shared_ptr<Node> right);
	virtual ~Mul() = default;

	virtual std::shared_ptr<Node> derivative(std::string var) const override;
	virtual double evaluate() const override;
};
