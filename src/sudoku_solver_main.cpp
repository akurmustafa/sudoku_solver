// sudoku_solver_main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "src/sudoku.h"

#include <iostream>
#include <string>

int main()
{
	// std::string sudoku_table{ "400000009800600000000005100000000068020003000000000004005000200000430000070080000" };
	std::string sudoku_table{ "109008000000013800000004002270000000048000706000070910407090080090800000030100004" };
	Sudoku sudoku{ sudoku_table };
	std::cout << "Starting Position\n";
	sudoku.print_data();
	if (sudoku.check_initial_sudoku_table()) {
		std::cout << "Check the sudoku table, it is not valid!";
	}
	else {
		sudoku.solve(true, 1);
		std::cout << "Solution\n";
		sudoku.print_data();
	}

	return 0;
}

