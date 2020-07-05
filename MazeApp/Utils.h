#ifndef __UTILS_H
#define __UTILS_H

#pragma warning(disable: 4996)
#pragma warning(disable: 26451)
#pragma warning(disable: 6386)

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

// Consts declaration
const int MAX_ROWS = 25;
const int MAX_COLUMNS = 80;
const char FREE = ' ';
const char WALL = '*';
const char PATH = '$';

// Enums declaration
enum SelectionType
{
	FROM_INPUT = 1,
	RANDOM = 2
};

enum ErrorType
{
	INVALID_INPUT_ERROR = 1,
	NO_SOLUTION_ERROR = 2,
	EMPTY_QUE_ERROR = 3,
	FULL_QUE_ERROR = 4,
	EMPTY_STACK_ERROR = 5
};

#endif // __UTILS_H