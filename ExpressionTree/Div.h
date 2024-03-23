#pragma once
#include"OperatorNodes.h"

class Div : public OperatorNodes {
private:
	virtual std::ostream& print(std::ostream& out) const override;

public:
	Div(std::shared_ptr<Node> left, std::shared_ptr<Node> right);
	virtual ~Div() = default;
	void setRight(std::shared_ptr<Node> right);

	virtual std::shared_ptr<Node> derivative(std::string var) const override;
	virtual double evaluate() const override;
};
