// sudoku_solver.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <array>
#include <cassert>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

class Tree {
public:
	Tree(int estimate, int idx) {
		estimate_ = estimate;
		idx_ = idx;
	}

	void set_children(const std::vector<Tree>& children) {
		children_ = children;
	}

	friend bool operator< (const Tree& a, const Tree& b)
	{
		return a.estimate_ < b.estimate_;
	}
	friend bool operator> (const Tree& a, const Tree& b)
	{
		return a.estimate_ > b.estimate_;
	}
	friend bool operator== (const Tree& a, const Tree& b)
	{
		return a.estimate_ == b.estimate_;
	}

	std::vector<int> changed_indices{};
	std::vector<Tree> children_;
	int estimate_{ -1 };
	int idx_{ -1 };
private:

};


class Sudoku {
public:
	Sudoku(const std::string& data_in) {
		assert(data_in.size() == 81 && "input string is not valid!!");
		for (int i = 0; i < 81; ++i) {
			data[i] = data_in[i] - '0';
			if (data[i] != 0) {
				--rem_elem_num;
			}
		}
	}

	int check_map(const std::map<int, int>& cur_map) {
		int contradiction{ 0 };
		for (const auto& cur_elem : cur_map) {
			if (cur_elem.second > 1) {
				contradiction = 1;
				return 1;
			}
		}
		return contradiction;
	}

	int one_step() {
		best_possible_estimate_num = 9;
		int contradiction{ 0 };
		auto cur_guess = get_cur_guess();
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				if (data[i * 9 + j] == 0) {
					int sum_of_possible_nums{ 135 };  // 11+12+..+18+19
					
					std::set<int> forbidden_nums{};
					std::map<int, int> forbidden_nums_idx{};
					// check same row
					for (int m = 0; m < 9; ++m) {
						int cur_idx = i * 9 + m;
						int cur_val = data[cur_idx];
						if (cur_val != 0) {
							forbidden_nums.insert(cur_val);
							++forbidden_nums_idx[cur_val];
						}
					}
					contradiction = check_map(forbidden_nums_idx);
					if (contradiction) {
						return contradiction;
					}

					forbidden_nums_idx.clear();
					// check same column
					for (int m = 0; m < 9; ++m) {
						int cur_idx = m * 9 + j;
						int cur_val = data[cur_idx];
						if (cur_val != 0) {
							forbidden_nums.insert(cur_val);
							++forbidden_nums_idx[cur_val];
						}
					}
					contradiction = check_map(forbidden_nums_idx);
					if (contradiction) {
						return contradiction;
					}
					
					forbidden_nums_idx.clear();
					// check same square
					int row_start = (i / 3) * 3;
					int col_start = (j / 3) * 3;
					for (int m = 0; m < 3; ++m) {
						for (int n = 0; n < 3; ++n) {
							int cur_idx = (row_start + m) * 9 + col_start + n;
							int cur_val = data[cur_idx];
							if (cur_val != 0) {
								forbidden_nums.insert(cur_val);
								++forbidden_nums_idx[cur_val];
							}
						}
					}
					contradiction = check_map(forbidden_nums_idx);
					if (contradiction) {
						return contradiction;
					}
					if (forbidden_nums.size() == 9) {
						contradiction = 1;
						return contradiction;
					}
					if (best_possible_estimate_num > 9 - forbidden_nums.size()) {
						best_possible_estimate_num = 9 - forbidden_nums.size();
						best_estimate_idx = i * 9 + j;
						best_estimate_forbiddens = forbidden_nums;
					}
					if (forbidden_nums.size() == 8) {  // we can determine number now
						int sum_of_forbiddens{ 0 };
						for (auto cur_forbidden : forbidden_nums) {
							sum_of_forbiddens += (10 + cur_forbidden);
						}
						data[i * 9 + j] = sum_of_possible_nums - sum_of_forbiddens - 10;
						cur_guess->changed_indices.push_back(i * 9 + j);
						--rem_elem_num;
					}

				}
			}
		}
		return contradiction;
	}

	void solve(bool print_on = false, int print_every = 100) {
		int prev_rem_elem_num{ 0 };
		int new_elem_found{ 0 };
		int count{ 0 };
		do {
			/*if (count == 17) {
				std::cout << "for debugging\n";
			}*/
			prev_rem_elem_num = rem_elem_num;
			int contradiction = one_step();
			new_elem_found = prev_rem_elem_num - rem_elem_num;
			if (contradiction) {
				auto cur_guess = get_cur_guess();
				/*if (new_elem_found != cur_guess->changed_indices.size()) {
					std::cout << "for debugging\n";
				}*/
				if (data[cur_guess->idx_] == 0) {
					std::cout << "shouldnt happen\n";
				}
				data[cur_guess->idx_] = 0;
				++rem_elem_num;
				for (auto cur_idx : cur_guess->changed_indices) {
					if (data[cur_idx] == 0) {
						std::cout << "shouldnt happen\n";
					}
					data[cur_idx] = 0;
					++rem_elem_num;
				}
				auto cur_guess_parent = get_cur_guess_parent();
				cur_guess_parent->children_.pop_back();
				while (cur_guess_parent->children_.size() == 0) {
					data[cur_guess_parent->idx_] = 0;
					++rem_elem_num;
					for (auto cur_idx : cur_guess_parent->changed_indices) {
						if (data[cur_idx] == 0) {
							std::cout << "shouldnt happen\n";
						}
						data[cur_idx] = 0;
						++rem_elem_num;
					}
					cur_guess_parent = get_cur_guess_parent();
					cur_guess_parent->children_.pop_back();
				}

				cur_guess = get_cur_guess();
				if (data[cur_guess->idx_] != 0) {
					std::cout << "shouldnt happen\n";
				}
				data[cur_guess->idx_] = cur_guess->estimate_;
				--rem_elem_num;
			}
			else if (new_elem_found == 0) {
				std::vector<Tree> estimates{};
				for (int i = 1; i < 10; ++i) {
					if (best_estimate_forbiddens.count(i) == 0) {
						estimates.push_back(Tree(i, best_estimate_idx));
					}
				}
				auto cur_guess = get_cur_guess();
				cur_guess->set_children(estimates);
				cur_guess = &cur_guess->children_.back();
				data[cur_guess->idx_] = cur_guess->estimate_;
				--rem_elem_num;
			}
			if (print_on && count % print_every == 0) {
				std::cout << "COUNT: " << count << "\n";
				std::cout << "Remaining Elem Num: " << rem_elem_num << "\n";
				int rem_elem_num_check{ 0 };
				for (int i = 0; i < 81; ++i) {
					if (data[i] == 0) {
						++rem_elem_num_check;
					}
				}
				std::cout << "Remaining Elem Num (Check): " << rem_elem_num_check << "\n";
				print_data();
			}
			++count;
		} while (rem_elem_num > 0 && count < 1000000);
		
	}
	Tree* get_cur_guess() {
		Tree* cur_estimate = &top_estimate_start;
		while (cur_estimate->children_.size() != 0) {
			cur_estimate = &cur_estimate->children_.back();
		}
		return cur_estimate;
	}

	Tree* get_cur_guess_parent() {
		Tree* cur_estimate = &top_estimate_start;
		Tree* parent_estimate = nullptr;
		while (cur_estimate->children_.size() != 0) {
			parent_estimate = cur_estimate;
			cur_estimate = &cur_estimate->children_.back();
		}
		return parent_estimate;
	}

	void print_data() const {
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				std::cout << data[i * 9 + j] << ", ";
			}
			std::cout << "\n";
		}
	}
private:
	Tree top_estimate_start{ 0, -1 };
	int rem_elem_num{ 81 };
	int best_possible_estimate_num{ 9 };
	int best_estimate_idx{ -1 };
	std::set<int> best_estimate_forbiddens{};
	std::array<int, 81> data{};
};

int main()
{
	// std::string sudoku_table{ "400000009800600000000005100000000068020003000000000004005000200000430000070080000" };
	std::string sudoku_table{ "109008000000013800000004002270000000048000706000070910407090080090800000030100004" };
	Sudoku sudoku{ sudoku_table };
	std::cout << "Starting Position\n";
	sudoku.print_data();
	sudoku.solve(true);
	std::cout << "Solution\n";
	sudoku.print_data();
	std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
