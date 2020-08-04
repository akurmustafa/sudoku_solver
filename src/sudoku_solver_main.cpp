// sudoku_solver_main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "src/sudoku.h"

#include <array>
#include <iostream>
#include <string>

int main()
{
	// std::string sudoku_table{ "400000009800600000000005100000000068020003000000000004005000200000430000070080000" };
	// std::string sudoku_table{ "109008000000013800000004002270000000048000706000070910407090080090800000030100004" };
	std::string sudoku_table{ 
		"000000500"
		"000000003"
		"900640000"
		"008070000"
		"003000002"
		"000060040"
		"670000090"
		"000005800"
		"400000000" };
	// std::array<int, 81> sudoku_table_arr{ 1,0,9,0,0,8,0,0,0,0,0,0,0,1,3,8,0,0,0,0,0,0,0,4,0,0,2,2,7,0,0,0,0,0,0,0,0,4,8,0,0,0,7,0,6,0,0,0,0,7,0,9,1,0,4,0,7,0,9,0,0,8,0,0,9,0,8,0,0,0,0,0,0,3,0,1,0,0,0,0,4 };
	std::array<int, 81> sudoku_table_arr{
		4,0,0,6,0,0,0,1,0,
		0,0,0,0,0,0,6,0,0,
		0,0,0,0,0,9,8,0,2,
		0,7,0,4,0,0,0,0,0, 
		0,0,0,0,6,0,0,0,0, 
		1,0,5,9,0,0,0,4,0, 
		5,0,0,0,0,0,0,8,0, 
		2,0,8,1,0,0,0,0,0, 
		0,0,0,0,0,0,7,3,0};
	
	// Sudoku sudoku{ sudoku_table };
	Sudoku sudoku{ sudoku_table_arr };
	std::cout << "Starting Position\n";
	sudoku.print_data();
	if (sudoku.check_initial_sudoku_table()) {
		std::cout << "Check the sudoku table, it is not valid!";
	}
	else {
		sudoku.solve(true);
		std::cout << "Solution\n";
		sudoku.print_data();
	}

	return 0;
}
