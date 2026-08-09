// composition , refrence  = https://www.geeksforgeeks.org/cpp/object-composition-delegation-in-c-with-examples/
// inharitance , refrence = https://www.geeksforgeeks.org/cpp/inheritance-in-c/
// polymorphism , refrence = https://www.geeksforgeeks.org/cpp/virtual-function-cpp/
//questions to solve 
// what is a virtual function ? 
// #include <iostream>
// using namespace std;

// // Simple class
// class A {
// public:
//     int x;

//     // COnstructor initializing
//     // the data members
//     A() { x = 0; }

//     A(int a)
//     {
//         cout << "Constructor A(int a) is invoked" << endl;
//         x = a;
//     }
// };

// // Complex class
// class B {
//     int data;
//     A objA;

// public:
//     // COnstructor initializing the
//     // data members
//     B(int a)
//         : objA(a)
//     {
//         data = a;
//     }

//     // Function to print values
//     // of data members in class
//     // A and B
//     void display()
//     {
//         cout << "Data in object of class B = " << data
//              << endl;
//         cout << "Data in member object of "
//              << "class A in class B = " << objA.x;
//     }
// };

// // Driver code
// int main()
// {
//     // Creating object of class B
//     B objb(25);

//     // Invoking display function
//     objb.display();
//     return 0;
// }


#include <iostream>
#include <string>
using namespace std;

#include <iostream>
using namespace std;
class Vehicle
{
private:
    string Brand;
    int Number_of_doors;
    int Top_speed;

public:
    Vehicle(const string & = "", int = 0, int = 0);
    virtual void honk();
    void turboBoost();
};
class Car : public Vehicle
{
public:
    Car(const string & = "", int = 0, int = 0);
    virtual void honk();
};
class SportCar : public Vehicle
{
public:
    SportCar(const string & = "", int = 0, int = 0);
    virtual void honk();
};
Vehicle::Vehicle(const string &brand, int doors, int top_speed)
{
    Brand = brand;
    if (doors >= 0)
        Number_of_doors = doors;
    else
        Number_of_doors = 0;
    if (top_speed >= 0)
        Top_speed = top_speed;
    else
        Top_speed = 0;
}
void Vehicle::honk()
{
    cout << "Vehicle honked\n";
}
void Vehicle::turboBoost()
{
    Top_speed += 10;
}
Car::Car(const string &brand, int doors, int top_speed) : Vehicle(brand, doors, top_speed)
{
}
void Car::honk()
{
    cout << "Car honked\n";
}
SportCar::SportCar(const string &brand, int doors, int top_speed) : Vehicle(brand, doors, top_speed)
{
}
void SportCar::honk()
{
    cout << "Sport Car honked\n";
}
int main()
{
    SportCar sport("Ferrari", 2, 350);
    sport.honk();
    sport.turboBoost();
    Vehicle *vehicle = &sport;
    vehicle->honk();
    return 0;
}





// // ============================================
// // QUESTION 1: MULTILEVEL INHERITANCE
// // Create a Vehicle -> Car -> SportsCar hierarchy
// // ============================================

// // TODO: Create Vehicle class (Base Class)
// // - Data member: brand (string)
// // - Constructor that takes brand and prints: "Vehicle created: [brand]"
// // - Virtual method void honk() that prints: "Beep beep!"
// class Vehicle {
//     // Your code here
// };

// // TODO: Create Car class (Derived from Vehicle)
// // - Data member: numDoors (int)
// // - Constructor that takes brand and number of doors
// // - Must call Vehicle constructor properly
// // - Print: "Car created with [numDoors] doors"
// // - Override honk() to print: "Car horn: Honk Honk!"
// class Car {
//     // Your code here
// };

// // TODO: Create SportsCar class (Derived from Car)
// // - Data member: topSpeed (int)
// // - Constructor that takes brand, number of doors, and top speed
// // - Must call Car constructor properly
// // - Print: "SportsCar created with top speed [topSpeed] km/h"
// // - Override honk() to print: "SportsCar horn: BEEP BEEP!"
// // - Add method void turboBoost() that prints: "Turbo boost activated! Speed: [topSpeed] km/h"
// class SportsCar {
//     // Your code here
// };

// // ============================================
// // MAIN FUNCTION - Test your implementation
// // ============================================
// int main() {
//     // TODO: Create a SportsCar object
//     // brand: "Ferrari", doors: 2, topSpeed: 350
    
//     // TODO: Call honk() on the object
    
//     // TODO: Call turboBoost() on the object
    
//     // TODO: Create a Vehicle pointer pointing to the SportsCar object
//     // Call honk() through this pointer
    
//     // Question: Does it call SportsCar's honk() or Vehicle's honk()?
//     // Question: What happens if you remove 'virtual' from Vehicle's honk()?
    
//     return 0;
// }




// #include <iostream>
// using namespace std;

// // ============================================
// // QUESTION 2: HYBRID INHERITANCE WITH DIAMOND PROBLEM
// // Create a Student-Athlete management system
// // Fix the diamond problem using virtual inheritance
// // ============================================

// // TODO: Create Person class (Virtual Base Class)
// // - Data members: name (string), age (int)
// // - Constructor that initializes name and age
// // - Virtual method void display() that prints: "Name: [name], Age: [age]"
// class Person {
//     // Your code here
// };

// // TODO: Create Student class (Derived from Person - academic info)
// // - Data member: rollNumber (int)
// // - Constructor that takes name, age, and roll number
// // - Must call Person constructor properly
// // - Override display() to also print: "Roll Number: [rollNumber]"
// // REMEMBER: Use virtual inheritance to avoid diamond problem!
// class Student {
//     // Your code here
// };

// // TODO: Create Athlete class (Derived from Person - sports info)
// // - Data member: sport (string)
// // - Constructor that takes name, age, and sport
// // - Must call Person constructor properly
// // - Override display() to also print: "Sport: [sport]"
// // REMEMBER: Use virtual inheritance to avoid diamond problem!
// class Athlete {
//     // Your code here
// };

// // TODO: Create AthleteStudent class (Derived from BOTH Student AND Athlete)
// // - Data member: scholarshipPercentage (int)
// // - Constructor that takes name, age, roll number, sport, and scholarship percentage
// // - Must properly initialize BOTH Student and Athlete (and Person directly!)
// // - Override display() to show ALL information
// // - Add method void trainingSchedule() that prints:
// //   "[name] trains [sport] at 6 AM, studies after 4 PM"
// class AthleteStudent {
//     // Your code here
// };

// // ============================================
// // MAIN FUNCTION - Test your implementation
// // ============================================
// int main() {
//     // TODO: Create an AthleteStudent object:
//     // Name: "John Smith"
//     // Age: 20
//     // Roll Number: 12345
//     // Sport: "Basketball"
//     // Scholarship: 75%
    
//     // TODO: Call display() on this object
    
//     // TODO: Call trainingSchedule() on this object
    
//     // Question: Without 'virtual' inheritance, how many Person objects
//     //           would exist in AthleteStudent? (Diamond Problem)
//     // Question: Why do we need to call Person constructor directly
//     //           in AthleteStudent when using virtual inheritance?
    
//     return 0;
// }