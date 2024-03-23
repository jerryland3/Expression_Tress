#pragma once
#include<string>
#include<iostream>

class Node {
	friend std::ostream& operator<<(std::ostream& os, const std::shared_ptr<Node> node);
private:
	virtual std::ostream& print(std::ostream& out) const = 0;

public:
	Node() {};
	virtual ~Node() {}

	virtual std::shared_ptr<Node> derivative(std::string var) const = 0;
	virtual double evaluate() const = 0;
};
