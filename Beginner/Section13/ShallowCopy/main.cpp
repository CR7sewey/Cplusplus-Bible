// Section 13
// Copy Constructor - Shallow Copy
// Note: this program will crash
#include <iostream>

using namespace std;

class Shallow {
private:
    int *data;
public:
    void set_data_value(int d) { *data = d; }
    int get_data_value() { return *data; }
    // Constructor
    Shallow(int d);
    // Copy Constructor
    Shallow(const Shallow &source);
    // Destructor
    ~Shallow();
};

Shallow::Shallow(int d) {
    data = new int;
    *data = d;
}

Shallow::Shallow(const Shallow &source) 
    : data(source.data) {
        cout << "Copy constructor  - shallow copy" << endl;
}

Shallow::~Shallow() {
    delete data;
    cout << "Destructor freeing data" << endl;
}

void display_shallow(Shallow s) {
    cout << s.get_data_value() << endl;
}

int main() {
    
    Shallow obj1 {100};
    display_shallow(obj1); // copy + destructor logo perde o ponteiro (pois a copia s No display aponta para a mesma que o ponteiro do this)
    // tanto s como obj1 apontam para a mesma ref na heap!
    // como é eliminado, o obj1 (data) aponta para algo invalido!
    Shallow obj2 {obj1}; // ja com eliminado o ponteiro na 44; apontam para a *data do obj1
    obj2.set_data_value(1000); // crash - compilador
    // ele faz o mesmo processo do copy construtor, so que nesme momento o obj1 apinta para uma memoria invalida!
    // ao passar 1000, ele faz dereferece do ponteiro e passa a valer 1000 tanto para o obj1 como para o 2
    // o problema agora é ao fazer o delete, pois ele vai fazer de ambos os ponteiros, primeiro do obj2 e dps do 1
    // so que quando for fazer do 1, como ja fez o do dois, ta a fazer delete de algo invalido
    
    return 0;
}

