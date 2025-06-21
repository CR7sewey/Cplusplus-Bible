// Section 17
// Shared Pointers
#include <iostream>
#include <memory>
#include <vector>
#include "Checking_Account.h"
#include "Savings_Account.h"
#include "Trust_Account.h"


class Test {
private:
    int data;
public:
    Test() : data{0} { std::cout << "Test constructor (" << data << ")" << std::endl; }
    Test(int data) : data {data} { std::cout << "Test constructor (" << data << ")" << std::endl; }
    int get_data() const {return data; }
    ~Test() {std::cout << "Test destructor (" << data << ")" << std::endl; }
};


void func(std::shared_ptr<Test> p) {
    std::cout << "Use count: " << p.use_count() << std::endl;
}

int main() {
   
    // use_count – the number of shared_ptr objects
    // managing the heap object
    // shared pointer does not allow to store vector/arrays in memory
    // can be copy, assigned and moved (push_back necessita de copy)
    // copia de um shared pointer, nao do objeto na heap!
   
//    std::shared_ptr<int> p1 {new int {100} };
//    std::cout << "Use count: "<< p1.use_count () << std::endl; 		// 1
//   
//    std::shared_ptr<int> p2 { p1 };			// shared ownwership
//    std::cout << "Use count: "<< p1.use_count () << std::endl; 		// 2
//
//    p1.reset();	// decrement the use_count; p1 is nulled out
//    std::cout << "Use count: "<< p1.use_count() << std::endl; 		// 0 
//    std::cout << "Use count: "<< p2.use_count() << std::endl; 		// 1
    
//    std::cout << "\n==========================================" << std::endl;
//    std::shared_ptr<Test> ptr = std::make_shared<Test>(100);
//    func(ptr); // 2 (bcs p is a copy of the pointer / heap object)
//    std::cout << "Use count: " << ptr.use_count() << std::endl; // 1
//    {
//        std::shared_ptr<Test> ptr1 = ptr;
//        std::cout << "Use count: " << ptr.use_count() << std::endl; // 2
//        {
//            std::shared_ptr<Test> ptr2 = ptr;
//            std::cout << "Use count: " << ptr.use_count() << std::endl;  // 3     
//            ptr.reset(); // ptr - 0; ptr2 - 2; ptr1 - 1
//        }
//        std::cout << "Use count: " << ptr.use_count() << std::endl; // ptr - 0;     
//
//    }
//    std::cout << "Use count: " << ptr.use_count() <<std:: endl; // 0

    std::cout << "\n==========================================" << std::endl;
    std::shared_ptr<Account> acc1 = std::make_shared<Trust_Account>("Larry", 10000, 3.1);
    std::shared_ptr<Account> acc2 = std::make_shared<Checking_Account>("Moe", 5000);
    std::shared_ptr<Account> acc3 = std::make_shared<Savings_Account>("Curly", 6000);
    // count - 1,1,1
    std::vector<std::shared_ptr<Account>> accounts;
    accounts.push_back(acc1); // count 2 bcs it makes a copy
    accounts.push_back(acc2); // count 2
    accounts.push_back(acc3); // count 2
    
    for (const auto &acc: accounts) {
        std::cout << *acc << std::endl;
        std::cout << "Use count: " << acc.use_count() << std::endl; // 2, 2, 2
    }
    
    std::cout << "==========================================" << std::endl;
    return 0;
}

