// ============================================================================
// CONSTRUCTOR OVERLOADING
// ============================================================================

// CONSTRUCTOR OVERLOADING
// Each constructor must have a different number or type of parameters
// The compiler knows which one to use based on arguments you pass when creating an object

// Example:
// class Car
// {
//     int plate;
//     string model;
//     
// public:
//     // Constructor 1: Default
//     Car() : plate(0), model("Unknown") {}
//     
//     // Constructor 2: Takes only plate (different NUMBER of parameters)
//     Car(int p) : plate(p), model("Unknown") {}
//    
//     // Constructor 3: Takes plate AND model (different NUMBER)
//     Car(int p, string m) : plate(p), model(m) {}
//     
//     // Constructor 4: Takes model first, then plate (different ORDER of types)
//     Car(string m, int p) : model(m), plate(p) {}
// };

// create a a class named student and overload it's constructor 4 times (id,name)

// ============================================================================
// FRIEND FUNCTION
// ============================================================================

// FRIEND FUNCTION
// A regular function (NOT a class member) that can access PRIVATE members of a class
// Declared INSIDE the class with 'friend' keyword
// Defined OUTSIDE the class (no ClassName:: prefix)
// Breaks encapsulation - use only when necessary!

// Example:
// class Car
// {
// private:
//     int plate;
//     
// public:
//     Car(int p) : plate(p) {}
//     
//     // Declaring friendship
//     friend void showPlate(const Car& c);
// };
// 
// // Defining friend function (NO Car:: here!)
// void showPlate(const Car& c)
// {
//     cout << "Plate: " << c.plate << endl;  // Direct access to private!
// }

// ============================================================================
// call by value and or refrence 
// ============================================================================

// WITHOUT reference - COPIES the ENTIRE Car object
// void showPlate(Car c)  // <-- Creates a brand new Car object (slow, memory heavy)
// {
//     cout << c.getPlate();
// }

// // WITH reference - NO COPY, just an alias to original
// void showPlate(Car& c)  // <-- No new object created (fast, efficient)
// {
//     cout << c.getPlate();
// }

// ============================================================================
// QUESTIONS FOR YOU TO IMPLEMENT
// ============================================================================

// 1. Constructor Overloading - Basic
// Question: Create a class called "Book" with private members (title, author, pages, price).
// Overload 3 constructors:
// - Default constructor: title="Unknown", author="Unknown", pages=0, price=0.0
// - Constructor with title and author only: sets these, pages=0, price=0.0
// - Constructor with all 4 parameters: sets all values
// Create objects using each constructor in main() and display their values.


// 2. Constructor Overloading - Validation
// Question: Create a class called "Time" with private members (hours, minutes, seconds).
// Overload 3 constructors:
// - Time(int seconds): converts seconds to hours/minutes/seconds
// - Time(int minutes, int seconds): combines them into proper time
// - Time(int hours, int minutes, int seconds): validates (hours 0-23, minutes 0-59, seconds 0-59)
// If validation fails, set all to 0.
// Add a display() method that shows "HH:MM:SS".


// 3. Constructor Overloading - Delegation
// Question: Create a class called "Rectangle" with private members (width, height).
// Overload 4 constructors using CONSTRUCTOR DELEGATION (calling one constructor from another):
// - Rectangle(): delegates to Rectangle(1,1)
// - Rectangle(int side): delegates to Rectangle(side, side)
// - Rectangle(int w, int h): sets width and height (validate > 0, else set to 1)
// - Rectangle(Rectangle &other): copy constructor
// Add methods: area(), perimeter(), isSquare().


// 4. Friend Function - Basic
// Question: Create a class called "Box" with private members (length, width, height).
// Add a friend function called "calculateVolume()" that takes a Box object and returns its volume.
// The function should directly access private members (no getters!).
// In main(), create a Box object and display its volume using the friend function.


// 5. Friend Function - Two Classes
// Question: Create TWO classes: "Meter" and "Centimeter". Both store a distance in their respective units (private).
// Create a friend function "addDistances()" that takes Meter and Centimeter objects, converts both to centimeters,
// adds them, and returns the result as a Meter object.
// The friend function must access private members of BOTH classes.
// Add display methods to both classes.


// 6. Friend Function - Comparison (Hard)
// Question: Create a class called "Student" with private members (name, score).
// Add a friend function "compareStudents()" that takes two Student objects and returns:
// - The name of the student with higher score
// - If scores are equal, return "Tie"
// The friend function must also access a private method "isPassing()" that returns true if score >= 60.
// No getters allowed - everything through friend access.
#include <iostream>
#include <string>
using namespace std;

class Student
{
friend string compareStudents(Student &s1,Student &s2);
private:
    string name;
    int score;
    bool isPassing()
    {
        if (score>=60)
            return true;
    }
public : 
    Student(string n,int s)
    {
        name = n;
        score = s;
    }
};
string compareStudents(Student &s1,Student &s2)
{
    string Tievalue = "Tie";
    if(s1.score > s2.score)
        return s1.name;
    if(s2.score>s1.score)
        return s2.name;
    else
        return Tievalue;
};
int main()
{
    Student obj1("hamid",100);
    Student obj2("gholamreza",100);
    cout<<compareStudents(obj1,obj2);
}
// 7. Friend Function + Constructor Overloading Combined (Very Hard)
// Question: Create a class called "Fraction" with private members (numerator, denominator).
// Overload constructors:
// - Fraction(): numerator=0, denominator=1
// - Fraction(int n): numerator=n, denominator=1
// - Fraction(int n, int d): validates denominator != 0
// Add friend functions:
// - multiplyFractions(): takes two Fractions, returns new Fraction (product)
// - divideFractions(): takes two Fractions, returns new Fraction (quotient)
// - simplify(): takes a Fraction and returns simplified version (use GCD)
// In main(), demonstrate constructor overloading for creating fractions and use all friend functions.


// 8. Multiple Friend Functions - Bank Account System (Very Hard)
// Question: Create a class "BankAccount" with private members (accountNumber, balance, ownerName).
// Add friend functions for ALL of these operations (no member functions except constructors!):
// - deposit(): adds money to account (validate positive amount)
// - withdraw(): removes money (validate sufficient balance)
// - transfer(): transfers money between TWO accounts
// - displayAccount(): prints all account details (formatted)
// - applyInterest(): adds 5% interest to balance
// Overload constructors:
// - Default: accountNumber="0000", balance=0, ownerName="Unknown"
// - With ownerName only: accountNumber="0000", balance=0
// - With ownerName and initial deposit: accountNumber="0000"
// - With ALL parameters: validates accountNumber has exactly 4 digits
// In main(), create accounts using different constructors and test all friend functions.