/*
 * Note that this is simple example code and does NOT conform to proper
 * header file or program structure. It is only meant to demonstrate
 * exception handling. 
 */

#include <iostream>
#include <cstdlib> 
#include <ctime> 
using namespace std;

// this is a "dummy" empty class for demo purposes
class BaseError {
};

// this is a "dummy" empty derived class for demo purposes
class DerivedError : public BaseError {
};

// this function will throw an int
void some_funtion1() {
    /* Assume this function does some processing,
     * something goes wrong and an exception is thrown*/
    throw 1;
}

// this function will throw a char
void some_funtion2() {
    /* Assume this function does some processing,
     * something goes wrong and an exception is thrown*/
    throw 'a';
}

// this function will throw a base object
void some_funtion3() {
    /* Assume this function does some processing,
     * something goes wrong and an exception is thrown*/
    //create an error object and throw it
    BaseError b;
    throw b;
}

// this function will throw a derived object
void some_funtion4() {
    /* Assume this function does some processing,
     * something goes wrong and an exception is thrown*/
    // create an error object and throw it
    DerivedError d;
    throw d;
}

// this function will randomly throw any of the above errors plus a float error
void some_funtion5() {
    /* Assume this function does some processing,
     * something goes wrong and an exception is thrown*/

    // make a random number 0 to 4
    int error = std::rand() % 5;
    
    switch(error){
        case 0:
            throw -1;
            break;
        case 1:
            throw 'b';
            break;
        case 2:
            BaseError b;
            throw b;
            break;
        case 3:
            DerivedError d;
            throw d;
            break;
        case 4:
            throw 3.14;
            break;
    }
}

int main() {
    // this is needed for some_function5() that uses rand()
    std::srand(std::time(NULL));

    try {
        // call some function that might throw an int error
        some_funtion1();
    } catch (int e) {
        // handle exception here
        cout << "The error thrown is: " << e << endl;
    }

    try {
        // call some function that might throw a char error
        some_funtion2();
    } catch (char e) {
        // handle exception here
        cout << "The error thrown is: " << e << endl;
    }

    try {
        // call some function that might throw a BaseError error
        some_funtion3();
    } catch (BaseError e) {
        // handle exception here
        cout << "The error thrown is a base class error." << endl;
    }

    try {
        // call some function that might throw a DerivedError error
        some_funtion4();
    } catch (DerivedError e) {
        // handle exception here
        cout << "The error thrown is a derived class error." << endl;
    }
    cout << endl;

    // let's try this a bunch of times to see what happens
    for (int i = 0; i < 20; i++) {

        // you can account for many types of exception which might be possible
        // or account for an error that you don't know is coming
        try {
            // call some function that might throw an error
            some_funtion5();
        } catch (DerivedError e) {
            // always catch derived error classes before base classes!
            cout << "The error thrown is a derived class error." << endl;
        } catch (BaseError e) {
            cout << "The error thrown is a base class error." << endl;
        } catch (int e) {
            cout << "The error thrown is: " << e << endl;
        } catch (char e) {
            cout << "The error thrown is: " << e << endl;
        } catch (...) {
            // this will catch anything that is not one of the above
            cout << "The error thrown is not one of the known cases." << endl;
        }

    }

    return 0;
}
