//Dry - dont repeat yourself
// encapculation - security - setter , getter 
// consturctor overloding 
// static data type 




// ============================================================
//  OPERATOR OVERLOADING IN C++
// ============================================================
//
// Operator overloading allows you to define custom behavior for
// C++ operators (+, -, *, /, ==, <, <<, >>, ++, --, etc.) when they are
// used with objects of your own classes.
//
// SYNTAX:
// return_type operator symbol (parameters) { ... }
//
// Example: Vector2D class with overloaded + operator
//


#include <iostream>

class Vector2D {
private:
    double x, y;

public:
    Vector2D(double x = 0, double y = 0) : x(x), y(y) {}
    Vector2D(double x , double y)
    {
        this -> x = x ;
        this -> y = y ;
    }

  //   () + ()
    Vector2D operator+(const Vector2D& other) const {
        return Vector2D(x + other.x, y + other.y);
    }

    Vector2D operator-(const Vector2D& other) const {
        return Vector2D(x - other.x, y - other.y);
    }

    Vector2D operator*(double scalar) const {
        return Vector2D(x * scalar, y * scalar);
    }

    bool operator==(const Vector2D& other) const {
        return (x == other.x && y == other.y);
    }
    friend std::ostream& operator<<(std::ostream& os, const Vector2D& v);
};

// Non-member overload of <<
std::ostream& operator<<(std::ostream& os, const Vector2D& v) {
    os << "(" << v.x << ", " << v.y << ")";
    return os;
}


int main()
{
    int x  = 5 ; 
    int y = 5 ;
   cout <<x++;
   cout <<++y;
}




//
// ============================================================
// INCREMENT (++) AND DECREMENT (--) OPERATORS
// ============================================================
//
// The ++ and -- operators come in two versions:
//
// 1. PREFIX  (++obj)   -> obj.operator++()
// 2. POSTFIX (obj++)   -> obj.operator++(int)  // dummy int parameter
//
// The dummy int parameter tells the compiler it's the postfix version.
// Postfix should return a COPY of the OLD value, then modify the object.
// Prefix should return a REFERENCE to the modified object.
//
// RULE OF THUMB:
// - Prefix: return Type& (efficient, chainable)
// - Postfix: return Type (copy of old value), takes int parameter
//

#include <iostream>  // Include iostream for input/output operations

int main() {  // Main function - program entry point
    
    // SIMPLE EXAMPLE - difference between prefix and postfix
    
    int num = 5;  // Declare an integer variable 'num' and initialize it to 5
    
    // ========== PREFIX EXAMPLE (++num) ==========
    // Prefix increments FIRST, then returns the new value
    
    std::cout << "Original num: " << num << std::endl;     
    std::cout << "++num: " << ++num << std::endl;           
    std::cout << "After ++num, num is: " << num << std::endl; 
    std::cout << std::endl;  
    // ========== POSTFIX EXAMPLE (num++) ==========
    num = 5;  // Assign 5 to num again
  
    std::cout << "Original num: " << num << std::endl;      
    std::cout << "num++: " << num++ << std::endl;        
    std::cout << "After num++, num is: " << num << std::endl;
    
    return 0; 
}

// OUTPUT EXPLANATION:
// 
// For PREFIX (++num):
// - Original num: 5
// - ++num: 6      <-- num became 6 BEFORE being printed
// - After ++num, num is: 6
//
// For POSTFIX (num++):
// - Original num: 5
// - num++: 5      <-- num was 5 when printed, THEN became 6
// - After num++, num is: 6
//
// KEY TAKEAWAY:
// - ++num increments FIRST, then uses the value
// - num++ uses the value FIRST, then increments

class Counter {
private:
    int value;

public:
    Counter(int v = 0) : value(v) {}

    Counter& operator++() {
        value++;          
        return *this;     
    }

    // POSTFIX ++ (c++)
    Counter operator++(int) {   // dummy int parameter
        Counter temp = *this;   // save old value
        value++;                // increment
        return temp;            // return old value (copy)
    }

    Counter& operator--() {
        value--;
        return *this;
    }

    Counter operator--(int) {
        Counter temp = *this;
        value--;
        return temp;
    }

    friend std::ostream& operator<<(std::ostream& os, const Counter& c) {
        os << "Counter(" << c.value << ")";
        return os;
    }
};

//
// IMPORTANT NOTES FOR ++ AND --:
// 1. Prefix is more efficient (no temporary copy)
// 2. Postfix must return by value (copy of old state)
// 3. The dummy int parameter is NEVER used — it's just a marker
// 4. Both can be overloaded as non-members, but typically they are members
// 5. For consistency, if you overload ++, also overload -- if it makes sense
//
// EXAMPLE USAGE:
// Counter c(5);
// ++c;      // calls operator++()
// c++;      // calls operator++(int)
// --c;      // calls operator--()
// c--;      // calls operator--(int)
//

//
// RULES AND BEST PRACTICES (SUMMARY):
// 1. You cannot create new operators (e.g., @, $, & is bitwise AND already)
// 2. You cannot change the number of operands an operator takes
//    (binary operators remain binary)
// 3. You cannot change operator precedence or associativity
// 4. Operators that MUST be members: =, [], (), ->
// 5. Operators that are often NON-members: <<, >>, +, - (for symmetry)
// 6. Keep semantics natural — overloaded operators should behave like
//    their built-in counterparts.
//
// COMMONLY OVERLOADED OPERATORS:
// - Arithmetic: +, -, *, /, %
// - Comparison: ==, !=, <, >, <=, >=
// - Assignment: =, +=, -=, *=, /=
// - Subscript: []
// - Function call: ()
// - I/O: <<, >>
// - Increment/Decrement: ++, --
//

//
// ============================================================
// EXERCISES 
// ============================================================
//
// For each question, write the function signature and implementation
// inside a class `Fraction` that represents a rational number (numerator/denominator).
// Assume denominator is always positive (simplified fraction is optional but recommended).
//
// Start with this class skeleton (mentally — do NOT write code in answers):
//
// class Fraction {
// private:
//     int num, den;
// public:
//     Fraction(int n = 0, int d = 1);  // constructor, ensures d > 0
//     // TODO: overload operators here
// };
//
// ------------------------------------------------------------
// QUESTION 1:
// Overload the + operator so you can add two Fraction objects.
// Example: Fraction(1,2) + Fraction(1,3) should equal Fraction(5,6)
//
// Write the declaration (inside class) and definition (outside class)
// as comments in your solution.
//
// ------------------------------------------------------------
// QUESTION 2:
// Overload the * operator for multiplication of two Fraction objects.
// Example: Fraction(2,3) * Fraction(3,4) = Fraction(6,12) simplified to Fraction(1,2)
//
// ------------------------------------------------------------
// QUESTION 3:
// Overload the == operator to compare two Fraction objects for equality.
// Example: Fraction(1,2) == Fraction(2,4) should be true
//
// ------------------------------------------------------------
// QUESTION 4:
// Overload the < operator to compare two Fraction objects.
// Example: Fraction(1,3) < Fraction(1,2) should be true
//
// ------------------------------------------------------------
// QUESTION 5 (challenging):
// Overload the += operator as a member function.
// This modifies the left operand and returns a reference to it.
// Example: Fraction f(1,4); f += Fraction(1,4); // f becomes 1/2
//
// ------------------------------------------------------------
// QUESTION 6 (mixed type):
// Overload the * operator to allow Fraction * int AND int * Fraction.
// Example: Fraction(1,2) * 3 == Fraction(3,2)  AND  3 * Fraction(1,2) == Fraction(3,2)
// Hint: One should be a member, the other a non-member function.
//
// ------------------------------------------------------------
// QUESTION 7 (output):
// Overload the << operator so you can print a Fraction as "num/den".
// Example: std::cout << Fraction(3,4); // prints "3/4"
// This must be a non-member function.
//
// ------------------------------------------------------------
// QUESTION 8 (thinking):
// Can you overload the % operator for Fraction? Why or why not?
// Write your answer as a comment — no code required.
//
// ------------------------------------------------------------
// QUESTION 9 (prefix ++):
// Overload the PREFIX ++ operator for Fraction.
// It should add 1 to the fraction and return a reference to the modified object.
//
// Write the declaration (inside class) and definition.
// Example: Fraction f(1,4); ++f; // f becomes 5/4
// Hint: Adding 1 means num/den + 1 = (num + den)/den
//
// ------------------------------------------------------------
// QUESTION 10 (postfix ++):
// Overload the POSTFIX ++ operator for Fraction.
// It should add 1 to the fraction but return a COPY of the OLD value.
//
// Write the declaration and definition.
// Example: Fraction f(1,4); Fraction old = f++; // old = 1/4, f = 5/4
//
// ------------------------------------------------------------
// QUESTION 11 (prefix --):
// Overload the PREFIX -- operator for Fraction.
// It should subtract 1 from the fraction and return a reference to the modified object.
//
// Write the declaration and definition.
// Example: Fraction f(3,2); --f; // f becomes 1/2
// Hint: Subtracting 1 means num/den - 1 = (num - den)/den
//
// ------------------------------------------------------------
// QUESTION 12 (postfix --):
// Overload the POSTFIX -- operator for Fraction.
// It should subtract 1 from the fraction and return a COPY of the OLD value.
//
// Write the declaration and definition.
// Example: Fraction f(3,2); Fraction old = f--; // old = 3/2, f = 1/2
//
// ------------------------------------------------------------
// QUESTION 13 (chaining):
// Show (by writing as a comment) what the following code would do
// if you have correctly implemented prefix ++ and postfix ++:
//
// Fraction f(1,4);
// Fraction g = ++(f++);
//
// Write step-by-step what happens and what final values f and g have.
// (No code — just explanation in comments)
//
// ------------------------------------------------------------
// QUESTION 14 (thinking):
// Should ++ and -- for Fraction be member or non-member functions?
// Why? Write your answer as a comment.
//
// ------------------------------------------------------------
// END OF EXERCISES (Questions 1-14)
// ============================================================
//
// EXAMPLE ANSWER FORMAT FOR Q1:
//
// // ANSWER 1:
// // Declaration inside class:
// // Fraction operator+(const Fraction& other) const;
// //
// // Definition outside class:
// // Fraction Fraction::operator+(const Fraction& other) const {
// //     int newNum = num * other.den + other.num * den;
// //     int newDen = den * other.den;
// //     return Fraction(newNum, newDen); // assume constructor simplifies
// // }
//
// EXAMPLE ANSWER FORMAT FOR Q9:
//
// // ANSWER 9:
// // Declaration inside class:
// // Fraction& operator++();   // prefix
// //
// // Definition outside class:
// // Fraction& Fraction::operator++() {
// //     num = num + den;   // add 1 (which is den/den)
// //     // optionally simplify fraction here
// //     return *this;
// // }
//
// EXAMPLE ANSWER FORMAT FOR Q10:
//
// // ANSWER 10:
// // Declaration inside class:
// // Fraction operator++(int);   // postfix
// //
// // Definition outside class:
// // Fraction Fraction::operator++(int) {
// //     Fraction old = *this;    // copy old value
// //     num = num + den;         // add 1
// //     return old;              // return old value
// // }
//