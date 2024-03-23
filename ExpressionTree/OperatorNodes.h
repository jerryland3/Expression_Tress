#pragma once
#include"Node.h"

class OperatorNodes : public Node {
private:
	std::shared_ptr<Node> leftPtr;
	std::shared_ptr<Node> rightPtr;
	virtual std::ostream& print(std::ostream& out) const = 0;

public:
	OperatorNodes(std::shared_ptr<Node> left, std::shared_ptr<Node> right);
	virtual ~OperatorNodes() = default;

	virtual std::shared_ptr<Node> derivative(std::string var) const = 0;
	virtual double evaluate() const = 0;

	std::shared_ptr<Node> getLeft() const { return leftPtr; }
	std::shared_ptr<Node> getRight() const { return rightPtr; }
	void setLeft(std::shared_ptr<Node> left) { this->leftPtr = left; }
	void setRight(std::shared_ptr<Node> right) { this->rightPtr = right; }
};