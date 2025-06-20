// Section 16
// Using override
#include <iostream>

class Base {
public:
    virtual void say_hello() const {
        std::cout << "Hello - I'm a Base class object" << std::endl;
    }
    virtual ~Base() {}
};

class Derived: public Base {
public:
    virtual void say_hello()  const override {     
        // override is a secuirty to != signatures basically        
        // Notice I forgot the const - if != signatures, 
        // the funciton is statically bound, which mean when calling the method through pointer, the Base one will be called in both objects p1 and p2 
        std::cout << "Hello - I'm a Derived class object" << std::endl;
    }
    virtual ~Derived() {}
};


int main() {
    
    Base *p1 = new Base();      // Base::say_hello() - dynamic binding
    p1->say_hello();
    
    Derived *p2 = new Derived();    // Derived::say_hello() - static binding (bcs p2 is a pointer to a derived object, and a derived objected is instantiated)
    p2->say_hello();
    
    Base *p3 = new Derived();   //  Base::say_hello() - static binding  ?????   I wanted Derived::say_hello()
    p3->say_hello();
    
   
    return 0;
}

