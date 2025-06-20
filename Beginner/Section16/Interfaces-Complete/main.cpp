// Section 16
// Interfaces - complete

#include <iostream>

/**
 * a logica é. O print usado quando é called o cout é o print de cada, que fexz overrinde ao da I_Pritnabel
 * no entanto, o metodo que o chama, é o friend operator da I_P.., que em si não pode ser virtual,
 * ou seja, seria statically bound.
 */

class I_Printable { // assim todos nao temos o problema de antes (por a friend nao ser virtual)
    friend std::ostream &operator<<(std::ostream &os, const I_Printable &obj);
public:
    virtual void print(std::ostream &os) const = 0;
    virtual ~I_Printable {};
};

std::ostream &operator<<(std::ostream &os, const I_Printable &obj) {
    obj.print(os); // calls the print method from I_Printable object passed
    return os;
}


class Account : public I_Printable {
public:
    virtual void withdraw(double amount) {
        std::cout << "In Account::withdraw" << std::endl;
    }
    virtual void print(std::ostream &os) const override {
        os << "Account display";
    }
    virtual ~Account() {  }
};

class Checking: public Account  {
public:
    virtual void withdraw(double amount) {
        std::cout << "In Checking::withdraw" << std::endl;
    }
     virtual void print(std::ostream &os) const override {
        os << "Checking display";
    }
    virtual ~Checking() {  }
};


class Savings: public Account {
public:
    virtual void withdraw(double amount) {
        std::cout << "In Savings::withdraw" << std::endl;
    }
     virtual void print(std::ostream &os) const override {
        os << "Savings display";
    }
    virtual ~Savings() {  }
};

class Trust: public Account  {
public:
    virtual void withdraw(double amount) {
        std::cout << "In Trust::withdraw" << std::endl;
    }
     virtual void print(std::ostream &os) const override {
        os << "Trust display";
    }
    virtual ~Trust() {  }
};

class Dog : public I_Printable {
public:
  virtual void print(std::ostream &os) const override {
        os << "Woof woof";
    } 
};

void print(const I_Printable &obj) {
    std::cout << obj << std::endl;
}


int main() {
    
    Dog *dog = new Dog();
    std::cout << *dog<< std::endl;  
    
    print(*dog);
    
    Account *p1 = new Account(); // dyna. binding
    std::cout << *p1<< std::endl;
        
    Account *p2 = new Checking();
    std::cout << *p2<< std::endl;  

//    Account a; // static binding
//    std::cout << a<< std::endl;
//    
//    Checking c;
//    std::cout << c << std::endl;
//
//    Savings s;
//    std::cout << s << std::endl;
//    
//    Trust t;
//    std::cout << t << std::endl;
        
    delete p1;
    delete p2;
    delete dog;
    return 0;
}
