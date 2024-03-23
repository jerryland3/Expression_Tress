#pragma once
#include"OperatorNodes.h"

class Sub : public OperatorNodes {
private:
	virtual std::ostream& print(std::ostream& out) const override;

public:
	Sub(std::shared_ptr<Node> left, std::shared_ptr<Node> right);
	virtual ~Sub() = default;

	virtual std::shared_ptr<Node> derivative(std::string var) const override;
	virtual double evaluate() const override;
};
