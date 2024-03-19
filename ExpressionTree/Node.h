#pragma once
#include<string>
#include<iostream>

class Node {
	friend std::ostream& operator<<(std::ostream& os, const std::shared_ptr<Node> node);
private:
	std::string symbol;
	virtual std::ostream& print(std::ostream& out) const = 0;

public:
	Node(const std::string& symbol);
	virtual ~Node() {}

	std::string getSymbol() const { return symbol; }

	virtual std::shared_ptr<Node> derivative(std::string var) const = 0;
	virtual double evaluate() const = 0;
};
