// ============================================================================
// CONST METHODS & CONST MEMBERS
// ============================================================================

// CONST MEMBERS: Must be initialized in constructor initialization list, never changes
// CONST METHODS: Promise not to modify members, can be called on const objects

// Example:
// class Example {
//     const int id;           // Const member
// public:
//     Example(int i) : id(i) {}  // Const must be initialized here
//     int getId() const {        // Const method
//         return id;
//     }
// };

// ============================================================================
// STATIC MEMBERS & STATIC METHODS
// ============================================================================

// STATIC MEMBERS: Shared across ALL objects of the class
// - Only ONE copy exists, not one per object
// - Must be defined outside the class (in .cpp file)
// - Can be accessed without creating any objects

// STATIC METHODS: Can only access static members
// - Can be called without an object: ClassName::methodName()
// - Cannot access 'this' pointer (no object exists)
// - Cannot access non-static members

// Example:
// class Example {
//     static int total;        // Static member - shared by all objects
//     int myValue;             // Non-static - each object has its own
// public:
//     Example() { total++; }
//     static int getTotal() {  // Static method
//         return total;        // OK: accessing static member
//         // return myValue;   // ERROR: cannot access non-static!
//     }
// };
// int Example::total = 0;
// int main()
// {
//     int count = Example::getTotal();  // No object needed!
//     Example obj;
//     obj.total = 0;

// }
// // MUST define static member outside class
// 
// // Called like this:

// STATIC CONST MEMBERS: Special case - can be initialized inside class
// Example: static const double PI = 3.14159;

// ============================================================================
// QUESTIONS 
// ============================================================================

// 1. Const  - Counter
// Question: Create class "Tracker" with:
// - const int id (auto-generated from static counter)
// - static int nextId
// - const method "peek()" returns id and increments peekCount
// - static method "getNextId()" returns nextId
// In main(), create const Tracker object and call peek() twice, show peekCount = 2
#include <iostream>
using namespace std;
class Tracker
{
    private: 
    static int peakcount;
    int id;
    static int nextId;
    public:
        Tracker(int id,int nextId)
        {
            this->id = id;
            this->nextId = nextId;
        }
       int  peak() const
       {
            peakcount++;
            return id;
       }
       static int getNextId()
       {
            return nextId;
    
       }
       static int getpeakcount()
       {
        return peakcount;
       }
};
int Tracker::nextId = 0;
int Tracker::peakcount = 0;
int main()
{
    const Tracker obj(1,3);
    obj.peak();
    obj.peak();
    cout<<Tracker::getpeakcount();
}


// 2. Static Members - Bank
// Question: Create class "BankAccount" with:
// - const int accountNumber (auto from static counter)
// - double balance
// - static double totalMoney (sum of all balances)
// - static const double INTEREST_RATE = 0.05
// - Constructor takes balance, updates totalMoney
// - const method "getBalance() const" returns balance
// - static method "getTotalMoney()" returns totalMoney
// - destructor subtracts balance from totalMoney
// In main(): create 3 accounts, show totalMoney, destroy 1 account, show totalMoney again

// 3. Static Methods - Math (No objects allowed!)
// Question: Create class "Math" with ONLY static members:
// - static const double PI
// - static int square(int x)
// - static bool isEven(int x)
// - static int max(int a, int b)
// Make constructor private so no objects can be created
// In main(): call all methods without creating Math object

// 4. Const + Static + Mutable Combined (Hard)
// Question: Create class "Logger" with:
// - const string name
// - mutable int logCount
// - static int totalLogs (across ALL loggers)
// - static const int MAX_LOGS = 100
// - Constructor: takes name, sets const member
// - const method "log(string message)": prints message, increments logCount AND totalLogs
// - const method "getStats()": prints name, logCount, totalLogs
// - static method "isFull()": returns true if totalLogs >= MAX_LOGS
// In main(): create 2 loggers, call log() on const objects, show totalLogs shared

// 5. Friend + Const + Static (Very Hard - 5 lines of code only!)
// Question: Create class "Secret" with:
// - const int code
// - static int totalSecrets
// - mutable int accessCount
// - Constructor takes code, increments totalSecrets
// - const method "getCode() const" returns code, increments accessCount
// - friend function "hack(const Secret& s)" that:
//   * Returns the code (using getCode() - not direct access!)
//   * Prints totalSecrets (using static method or direct)
//   * Prints accessCount (direct access - friend can see private)
// In main(): create const Secret object, call hack() on it