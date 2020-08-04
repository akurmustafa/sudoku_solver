
#ifndef SRC_SUDOKU_H
#define SRC_SUDOKU_H

#include "src/tree.h"

#include <array>
#include <map>
#include <set>
#include <string>

class Sudoku {
public:
	Sudoku(const std::string& data_in);
	Sudoku(const std::array<int, 81>& data_in);


	void print_data() const;
	void solve(bool print_on = false, int print_every = 100);
	int check_initial_sudoku_table();

private:
	Tree* get_cur_guess();
	Tree* get_cur_guess_parent();
	int check_map(const std::map<int, int>& cur_map);
	int one_step_v2();

	// members
	Tree top_estimate_start{ 0, -1 };
	int rem_elem_num{ 81 };
	int best_possible_estimate_num{ 9 };
	int best_estimate_idx{ -1 };
	std::set<int> best_estimate_forbiddens{};
	std::array<int, 81> data{};
};

#endif  // SRC_SUDOKU_H
