#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include "CalcFunctions.h"
using namespace std;


void mainMenu(char& mode) {
    cout << "Welcome to the calculator app!\n";
    cout << "Please choose a mode\n";
    cout << "B - BASIC OPERATIONS | S - STATISTICS\n";
    cout << "Enter here: ";
    cin >> mode;  
}
void simpleMenu(char& key) {
    cout << "\tBASIC MATH OPERATIONS\n";
    cout << "A - ADD\nS - SUBTRACT\nM - MULTIPLY\nD - DIVIDE\nQ - QUIT PROGRAM\n";
    cout << "__________________________________________________________\n";
    cout << "Please enter operation: ";
    cin.clear();
    cin.ignore(100000, '\n');
    cin >> key;
}

void statMenu(vector<double> data, char& key) {
    //order vector using selection sort
    sortData(data);
    cout << "Sorted Data: \n";
    for(int i = 0; i < data.size(); i++) {
        cout << data[i]; if (i < data.size()-1) cout << ", ";
    }
    cout << setprecision(3) << fixed;
    double mean = getMean(data);
    double variance= getVariance(data,mean);
    //print out standard deviation and variance
    cout << "\n\nMean: " << mean << endl;
    cout << "Population Variance: " << variance << endl;
    cout << "Population Standard Deviation " << sqrt(variance);
    cout << endl << endl;

    cout << "Enter here: ";
    cin.clear();
    cin.ignore(100000, '\n');
    cin >> key;
}

double getVariance (vector<double> data, double mean) {
    double sum = 0;
    for (int i = 0; i < data.size(); i++) {
        sum += pow((data[i]-mean),2);
    }
    return sum / data.size();
}

double getMean (vector<double> data) {
    double sum = 0;
    for (int i = 0; i < data.size(); i++) {
        sum += data[i];
    }
    return sum / data.size();
}
double add() {
    double a, b;
    cout << "Enter two values: ";
    cin >> a >> b;
    return a + b;
}

double subtract() {
    double a, b;
    cout << "Enter two values: ";
    cin >> a >> b;
    return a - b;
}

double multiply() {
    double a, b;
    cout << "Enter two values: ";
    cin >> a >> b;
    return a * b;
}

double divide() {
    double a, b;
    cout << "Enter two values: ";
    cin >> a >> b;
    if (b==0) {
        cout << "ERROR: Number cannot be divided by a zero!\n";
        return 0;
    }
    return a / b;
}

void getData(vector<double>& data) {
    double num;
    cout << "Please enter a set of values (seperating by space and end with non-number): ";
    while (cin >> num) {
        data.push_back(num);
    }
    cout << "\n\nAll data has been processed!\n";
    cin.clear();
}

void sortData(vector<double>& data) {
    int lowestIndex;
    for(int i = 0; i < data.size()-1; i++) {
        lowestIndex = i;
        for(int k = i + 1; k < data.size(); k++) {
            if (data[k] < data[lowestIndex])
                lowestIndex = k;
        }
        if (lowestIndex != i) {
            double temp = data[i];
            data[i] = data[lowestIndex];
            data[lowestIndex] = temp;
        }
    }
}