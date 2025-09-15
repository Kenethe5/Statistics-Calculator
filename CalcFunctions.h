#ifndef CALC_H
#define CALC_H

#include <iostream>
#include <vector>
using namespace std;

void mainMenu(char&);

void simpleMenu(char&);
double add();
double subtract();
double multiply();
double divide();

void statMenu(vector<double>,char&);
void getData(vector<double>&);
double getVariance(vector<double>,double);
double getMean(vector<double>);

void sortData(vector<double>&);


#endif