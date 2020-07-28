
#ifndef SRC_TREE_H
#define SRC_TREE_H

#include <vector>

class Tree {
public:
	Tree(int estimate, int idx);

	void set_children(const std::vector<Tree>& children);
	friend bool operator< (const Tree& a, const Tree& b);
	friend bool operator> (const Tree& a, const Tree& b);
	friend bool operator== (const Tree& a, const Tree& b);

	// members
	std::vector<int> changed_indices{};
	std::vector<Tree> children_;
	int estimate_{ -1 };
	int idx_{ -1 };
private:

};

#endif  // SRC_TREE_H
