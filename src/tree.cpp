
#include "src/tree.h"

#include <vector>

Tree::Tree(int estimate, int idx) {
	estimate_ = estimate;
	idx_ = idx;
}

void Tree::set_children(const std::vector<Tree>& children) {
	children_ = children;
}

bool operator< (const Tree& a, const Tree& b)
{
	return a.estimate_ < b.estimate_;
}

bool operator> (const Tree& a, const Tree& b)
{
	return a.estimate_ > b.estimate_;
}

bool operator== (const Tree& a, const Tree& b)
{
	return a.estimate_ == b.estimate_;
}
