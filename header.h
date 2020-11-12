#ifndef header
#define header

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

struct Animal{
	string id;
	double w1;
	double w2;
	Animal* next;
};

struct AnimalList{
	Animal* first;
	Animal* last;
};

void print_output(AnimalList* animals, int x);
AnimalList* read_file(string input_file);

AnimalList* read_file_ref(string input_file);

void main_testcases(string input_file, int x);
void main_debug(string input_file, int x);

#endif