// Section 16
// Virtual functions

#include <iostream>

// dynamic binding vs static binding - The problem folder
/**
 * if no virtual, in a exameple like
 * Account *a = new Trust()
 * a->withdraw(), the method called would be the one from Account
 * with cirtual, the compiler will look for which object a is pointing to, and then apply the trust withdraw
 * 
 * other example is a method that receives a object, like
 * void display_account(const Account &a) {
 * a.display()
 * }
 * if a object Trust uses this mehtod without virtual, is a static binding,
 * so the method called is the one from Account (argument) and not the object passed
 * 
 * virtual functions are only dynamic bound if we call them by pointer or reference!!!!
 * otherwise they are statically bound
 */

// This class uses dynamic polymorphism for the withdraw method
class Account {
public:
    virtual void withdraw(double amount) {
        std::cout << "In Account::withdraw" << std::endl;
    }
};

class Checking: public Account  {
public:
    virtual void withdraw(double amount) {
        std::cout << "In Checking::withdraw" << std::endl;
    }
};

class Savings: public Account  {
public:
    virtual void withdraw(double amount) {
        std::cout << "In Savings::withdraw" << std::endl;
    }
};

class Trust: public Account  {
public:
    virtual void withdraw(double amount) {
        std::cout << "In Trust::withdraw" << std::endl;
    }
};

int main() {
    std::cout << "\n === Pointers ==== " << std::endl;
    Account *p1 = new Account();
    Account *p2 = new Savings();
    Account *p3 = new Checking();
    Account *p4 = new Trust();
    
    p1->withdraw(1000);
    p2->withdraw(1000);
    p3->withdraw(1000);
    p4->withdraw(1000);
    

    std::cout << "\n === Clean up ==== " << std::endl;
    delete p1;
    delete p2;
    delete p3;
    delete p4;
        
    return 0;
}

