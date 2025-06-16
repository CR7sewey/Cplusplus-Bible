// Section 13
// Copy Constructor - Deep Copy
#include <iostream>

using namespace std;

class Deep {
private:
    int *data;
public:
    void set_data_value(int d) { *data = d; }
    int get_data_value() { return *data; }
    // Constructor
    Deep(int d);
    // Copy Constructor
    Deep(const Deep &source);
    // Destructor
    ~Deep();
};

Deep::Deep(int d) {
    data = new int;
    *data = d;
}

Deep::Deep(const Deep &source)
    : Deep {*source.data} {
    cout << "Copy constructor  - deep copy" << endl;
}

Deep::~Deep() {
    delete data;
    cout << "Destructor freeing data" << endl;
}

void display_deep(Deep s) {
    cout << s.get_data_value() << endl;
}

int main() {
    
    Deep obj1 {100};
    display_deep(obj1); // o problema fica resolvido pois o ponteiro deste objeto tem outra ref na heap em relacao ao s da 36, embora o valor seja o msm
    // logo no destructor limpa o ponteiro da copia mas nao o do obj1
    // logo diferente addresses
    // em suma o problema esta que no emtodo é criado uma copia temp do obj, entao no copy construtor temos de dar um twist
    Deep obj2 {obj1}; 

    obj2.set_data_value(1000);
  
    return 0;
}

