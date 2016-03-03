#include "../src/bsboard.h"
#include <iostream>
using std::cout;
using std::endl;



int main(){
    board test;
    test.place("Destroyer", 27, 'D');
    cout << "placing destroyer at 27 D" << endl;
    test.print(); 
    cout << "marking hit at F 10 on enemy board" << endl;
    test.settheirBoard(95, 'H');
    test.print();
    cout << "placing sub at 84 U" << endl;
    test.place("Sub", 84 , 'U');
    test.print();
    cout << "marking miss at 34 on enemy board" << endl;
    test.settheirBoard(34, 'M');
    test.print();
    cout << "placing carrier 98 U" << endl;
    test.place("Carrier", 98, 'U');
    test.print();
    cout << "placing battleship 0 R" << endl;
    test.place("Battleship", 0, 'R');
    test.print();
    cout << endl << "DONE ALL TESTS" << endl;
    return 0;
}
