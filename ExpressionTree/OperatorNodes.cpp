#include"OperatorNodes.h"

OperatorNodes::OperatorNodes(std::shared_ptr<Node> left, std::shared_ptr<Node> right) : Node(), leftPtr(left), rightPtr(right) {
}