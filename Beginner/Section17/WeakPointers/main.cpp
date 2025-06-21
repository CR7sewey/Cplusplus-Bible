// Section 17
// Weak Pointers
#include <iostream>
#include <memory>

using namespace std;

/**
 * non-owning weak reference
 * does not participate in owning relatioship
 * always created from a shared ptr
 * does not change the count
 * used to prevent strong reference cycles which could prevent objects from being deleted or for a temp (like in a loop)
 */

class B;    // forward declaration

class A {
    std::shared_ptr<B> b_ptr;
public:
    void set_B(std::shared_ptr<B> &b) {
        b_ptr = b;
    }
    A() { cout << "A Constructor" << endl; }
    ~A() { cout << "A Destructor" << endl; }
};

class B {
    std::weak_ptr<A> a_ptr;     // make weak to break the strong circular reference
public:
    void set_A(std::shared_ptr<A> &a) {
        a_ptr = a;
    }
    B() { cout << "B Constructor" << endl; }
    ~B() { cout << "B Destructor" << endl; }
};

int main() {
    // if both shared, after the cycle, the pointers would point to each other
    // the destructor never got called (bcs there ia a reference), mem leak in the heap
    // with weak, we define the owner (in this case a). When a is destructed,
    // b loses the reference, so it is also destroyed

    shared_ptr<A> a  = make_shared<A>();
    shared_ptr<B> b = make_shared<B>();
    a->set_B(b);
    b->set_A(a);
    
    return 0;
}

