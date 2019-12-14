#ifndef __OUT_RESOURCES_H
#define __OUT_RESOURCES_H

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

// Consts declaration
const int FROM_INPUT = 1;
const int RANDOM = 2;
const int MAX_ROWS = 25;
const int MAX_COLUMNS = 80;
const char FREE = ' ';
const char WALL = '*';
const char PATH = '$';

// enums declaration
enum Error
{
	INVALID_INPUT_ERROR = 1,
	NO_SOLUTION_ERROR = 2,
	EMPTY_QUE_ERROR = 3,
	FULL_QUE_ERROR = 4,
	EMPTY_STACK_ERROR = 5
};

#endif // __OUT_RESOURCES_H