#pragma once
#include"OperatorNodes.h"

class Add : public OperatorNodes {
private:
	virtual std::ostream& print(std::ostream& out) const override;

public:
	Add(std::shared_ptr<Node> left, std::shared_ptr<Node> right);
	virtual ~Add() = default;

	virtual std::shared_ptr<Node> derivative(std::string var) const override;
	virtual double evaluate() const override;
};
