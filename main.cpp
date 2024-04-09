#include <string>
#include<iostream>
#include<sstream>
#include<istream>
#include "GroupCalculator.h"
using namespace std;

int main()
{
    string input;
    int choice;
    Calculator* c = new Calculator();
    while (true) {
        cout << "[1] add set" << endl;
        cout << "[2] remove set" << endl;
        cout << "[3] union" << endl;
        cout << "[4] intersection" << endl;
        cout << "[5] power set" << endl;
        cout << "[6] print" << endl;
        cout << "[0] exit" << endl;
        getline(cin, input);
        stringstream st(input);
        st >> choice;
        if(!(st.eof())) {
            choice = 10;
            st.clear();
        }
        switch (choice)
        {
            case 1:
                c->AddGroup(); break;
            case 2:
                c->DeleteGroup(); break;
            case 3:
                c->UnionGroups(); break;
            case 4:
                c->InterGroups(); break;
            case 5:
                c->PowerGroup(); break;
            case 6:
                c->Print(); break;
            case 0:
                c->Exit(); break;
            default:
                cerr << "ERROR: invalid command; type 0 for exit" << endl;

        }
    }
    return 0;
}