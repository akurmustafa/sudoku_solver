# Sudoku Solver in C++

A project for automatic sudoku solving in c++. 

## Getting Started

This Project is written in Visual Studio 19, with C++17 compiler. However code should be portable just download the src folder and compile and link files under it. 

### Prerequisites

You need a cpp compiler later than C++11 to be able to recompile source files, in my machine I have used MSVC C++ 17

### Using
In main, Sudoku class expects a 81 length std::string during construction. This string is generated from 9x9 sudoku table whose elements read row wise. It assumes std::string consists of one of the following characters '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'.
'0' represents empty places in the sudoku table whose value to be found, and other characters represent their integer values. Encode your sudoku table as above int the std::string sudoku_table, then run the program to see result.
For Instance following table
| #1 | #2 | #3 | #4 | #5 | #6 | #7 | #8 | #9 |
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
| 1   |     | 9   |     |     | 8   |     |     |     |
|     |     |     |     | 1   | 3   | 8   |     |     |
|     |     |     |     | 6   | 4   |     |     | 2   |
| 2   | 7   |     |     |     |     |     |     |     |
|     | 4   | 8   |     |     |     | 7   |     | 6   |
|     |     |     |     | 7   |     | 9   | 1   |     |
| 4   |     | 7   |     | 9   |     |     | 8   |     |
|     | 9   |     | 8   |     |     |     |     |     |
|     | 3   |     | 1   |     |     |     |     | 4   |

<!---
_____________________________________
| 1 |   | 9 |   |   | 8 |   |   |   |
_____________________________________
|   |   |   |   | 1 | 3 | 8 |   |   |
_____________________________________
|   |   |   |   | 6 | 4 |   |   | 2 |
_____________________________________
| 2 | 7 |   |   |   |   |   |   |   |
_____________________________________
|   | 4 | 8 |   |   |   | 7 |   | 6 |
_____________________________________
|   |   |   |   | 7 |   | 9 | 1 |   |
_____________________________________
| 4 |   | 7 |   | 9 |   |   | 8 |   |
_____________________________________
|   | 9 |   | 8 |   |   |   |   |   |
_____________________________________
|   | 3 |   | 1 |   |   |   |   | 4 |

-->

can be encoded as following std::string "109008000000013800000004002270000000048000706000070910407090080090800000030100004"

## Deployment

It would be nice to have web interface where user can enter sudoku table and get the result back, maybe I can add it in the future.


## Contributing

I didn't do extensive unit tests, if you can spot error, or have suggestions for improvement feel free to implement them and pull request


## Authors

* **Mustafa Akur** - *Initial work* - [akurmustafa](https://github.com/akurmustafa)


## License

This project is licensed under the MIT License
