#include <iostream>

using namespace std;

int main() {
    
    int scores[] {100, 95, 89};
    
    cout << "Value of scores: " << scores << endl;     
    
    int *score_ptr {scores};
    cout << "Value of score_ptr: " << score_ptr << endl;

    // ex: vamos supor que o endereço na memoria do array é 1000 ( o mesmo do 1º elemento)
    // o segundo do array é 1004, 1008 e so on se cada int for 4 bytes de mem
    
    cout << "\nArray subscript notation -------------------------" << endl;
    cout << scores[0] << endl; // 100 -> 1000
    cout << scores[1] << endl; // 95 -> 1004
    cout << scores[2] << endl; // 89 -> 1008
    
    cout << "\nPointer subscript notation -------------------------" << endl;
    cout << score_ptr[0] << endl; // 1000
    cout << score_ptr[1] << endl; // 1004
    cout << score_ptr[2] << endl; // 1008
    
    cout << "\nPointer offset notation-------------------------" << endl;
    cout << *score_ptr << endl;  // 100 (*1000)
    cout << *(score_ptr + 1) << endl; // 95 (*(1000+4))
    cout << *(score_ptr +2) << endl;
    
    cout << "\nArray offset notation-------------------------" << endl;
    cout << *scores << endl;
    cout << *(scores + 1) << endl;
    cout << *(scores +2) << endl;
    
    cout << endl;
    return 0;
}

