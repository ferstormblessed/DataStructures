#include <vector>
#include "Operaciones.h"

using namespace std;

int main() {

    vector<string> entries;

    entries.push_back("7");
    entries.push_back("4");
    entries.push_back("-");
    entries.push_back("5");
    entries.push_back("*");

    std::stack<float> my_stack;

    for (int i = 0; i < entries.size(); i++){
        if (!Operaciones::isNumber(entries[i])) { 
            (entries[i] == "+") ? Operaciones::sumar(my_stack) :
            (entries[i] == "-") ? Operaciones::restar(my_stack) :
            (entries[i] == "*") ? Operaciones::multiplicar(my_stack) :
            (entries[i] == "/") ? Operaciones::dividir(my_stack) : 
            Operaciones::mensaje();
        }
        else{
            my_stack.push(stoi(entries[i]));
        }
    }

    for (int i = 0; i < my_stack.size(); i++){
        cout << my_stack.top() << endl;
        my_stack.pop();
    }

    return 0;
}