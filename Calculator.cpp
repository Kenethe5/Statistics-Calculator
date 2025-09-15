#include <iostream>
#include <vector>
#include <iomanip>
#include "CalcFunctions.h"
using namespace std;

int main() {
    char mode, key;
   
    double answer;
    mainMenu(mode);
    while (mode != 's' && mode != 'S' && mode != 'b' && mode != 'B') {
        cout << "ERROR: " << mode << " is not a valid key\n";
        cin.clear();
        cin.ignore(10000000, '\n');
        mainMenu(mode);
    }
 
    if (mode == 'b' || mode == 'B') {
        do {
        simpleMenu(key);
        switch (key) {
                case 'a':
                case 'A':
                    answer = add();
                    cout << "Answer: " << answer << endl;
                    break;
                case 's':
                case 'S':
                    answer = subtract();
                    cout << "Answer: " << answer << endl;
                    break;
                case 'm':
                case 'M':
                    answer = multiply();
                    cout << "Answer: " << answer << endl;
                    break;
                case 'd':
                case 'D':
                    answer = divide();
                    cout << "Answer: " << answer << endl;
                    break;
                case 'q':
                case 'Q':
                    cout << "You have quit the program.\n";
                    break;
                default:
                    cout << "ERROR: Invalid Entry\n";
            }
        } while (key != 'q' && key != 'Q');
    }
    //STATISTICS MODE
    else if (mode == 's' || mode == 'S') {
        vector<double> numbers;
        getData(numbers);
        do {
            //menu
            cout << "Unsorted Data: \n";
            for (int i = 0; i < numbers.size(); i++) {
                cout << numbers[i]; if (i < (numbers.size() - 1)) cout << ", ";
            }
            cout << endl;
            statMenu(numbers,key);
            cout << endl;
            //cin >> key;
        } while (key != 'q' && key != 'Q');
    }

    cout << "\n===================================================\n";
    

    return 0;
}