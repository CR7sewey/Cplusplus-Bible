// Section 16
// The problem
#include <iostream>
#include <memory>

// static vs dynamic binding - see virtual functions
/**
 * 
 */

class Base {
public:
    void say_hello() const {
        std::cout << "Hello - I'm a Base class object" << std::endl;
    }
};

class Derived: public Base {
public:
    void say_hello()  const {   
        std::cout << "Hello - I'm a Derived class object" << std::endl;
    }
};

void greetings(const Base &obj) {
    std::cout << "Greetings: " ;
    obj.say_hello();
}

int main() {
    Base b;
    b.say_hello(); // line 13 - static
    
    Derived d;
    d.say_hello(); // line 20 - static
    
    // both are a Base class
    greetings(b); // line 13 - the problem with static!
    greetings(d); // line 13 - the problem with static!
    
    Base *ptr = new Derived(); // ptr can hold the address of any Base object (like Derived)
    ptr->say_hello(); // line 13 - the problem with static! - Base::say_hello
    
    std::unique_ptr<Base> ptr1 = std::make_unique<Derived>(); //works statically with smart pointers as well
    ptr1->say_hello();
    
    
    
   delete ptr;
    
    return 0;
}

