# Sudoku Solver in C++

A project for automatic sudoku solving in c++. 

## Implementation

This project is written using c++ language features, and standard library. No 3rd party library is used. Given a sudoku table code first checks for guarantee moves, if it cannot find guarantee moves, it guesses one of the empty cells. 
If guess leads to a contradiction, code resets later changes after guess. Guesses are kept in a Tree based data structure.
If there was no contradiction in the given sudoku map, code would find a solution. However, for sudoku maps with low number of entries; it would take much time.
For most of the cases this shouldn't be a problem. If you encounter an error, or observe a challenging input for sudoku solver feel free to contact me.

## Getting Started

This Project is written in Visual Studio 19, with C++17 compiler. However code should be portable just download the src folder and compile and link files under it. 

### Prerequisites

You need a cpp compiler later than C++11 to be able to compile source files, in my machine I have used MSVC C++ 17

### Using
In main, Sudoku class expects a 81 length ```std::string``` or 81 length ```std::array<int, 81>``` during construction. This string is generated from 9x9 sudoku table whose elements read row wise. It assumes ```std::string``` consists of one of the following characters '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'.
'0' represents empty places in the sudoku table whose value to be found, and other characters represent their integer values. Encode your sudoku table as corresponding characters in the ```std::string``` sudoku_table or put them in ```std::array<int, 81>``` with their integer values (0 for unknown values as before), then run the program to see result.
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

can be encoded as following 
```cpp
std::string("109008000000013800000004002270000000048000706000070910407090080090800000030100004") 
```
or following 
```cpp 
std::array<int, 81>{1,0,9,0,0,8,0,0,0,0,0,0,0,1,3,8,0,0,0,0,0,0,0,4,0,0,2,2,7,0,0,0,0,0,0,0,0,4,8,0,0,0,7,0,6,0,0,0,0,7,0,9,1,0,4,0,7,0,9,0,0,8,0,0,9,0,8,0,0,0,0,0,0,3,0,1,0,0,0,0,4}
```

## Deployment

It would be nice to have web interface where user can enter sudoku table and get the result back, maybe I can add it in the future.


## Contributing

I didn't do extensive unit tests, if you can spot error, or have suggestions for improvement feel free to implement them and pull request


## Authors

* **Mustafa Akur** - *Initial work* - [akurmustafa](https://github.com/akurmustafa)


## License

This project is licensed under the MIT License
