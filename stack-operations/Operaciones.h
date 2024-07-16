#ifndef OPERACIONES_H
#define OPERACIONES_H

#include <iostream>
#include <stack>
#include <string>

class Operaciones {
    public:
        static void sumar(std::stack<float>&);
        static void restar(std::stack<float>&);
        static void multiplicar(std::stack<float>&);
        static void dividir(std::stack<float>&);
        static void mensaje();
        static bool isNumber(std::string&);
        static bool operValida(std::stack<float>&);
};

bool Operaciones::operValida(std::stack<float> &stack){
    return (stack.size() >= 2) ? true : false;
}

void Operaciones::sumar(std::stack<float> &stack){
    if (operValida(stack)){
        float num1 = stack.top();
        stack.pop();
        float num2 = stack.top();
        stack.pop();
        stack.push(num2 + num1);
    }
    else{
        mensaje();
    }
}

void Operaciones::restar(std::stack<float> &stack){
    if (operValida(stack)){
        float num1 = stack.top();
        stack.pop();
        float num2 = stack.top();
        stack.pop();
        stack.push(num2 - num1);
    }
    else{
        mensaje();
    }
}

void Operaciones::multiplicar(std::stack<float> &stack){
    if (operValida(stack)){
        float num1 = stack.top();
        stack.pop();
        float num2 = stack.top();
        stack.pop();
        stack.push(num2 * num1);
    }
    else{
        mensaje();
    }
}

void Operaciones::dividir(std::stack<float> &stack){
    if (operValida(stack)){
        float num1 = stack.top();
        stack.pop();
        float num2 = stack.top();
        stack.pop();
        stack.push(num2 / num1);
    }
    else{
        mensaje();
    }
}

void Operaciones::mensaje(){
    std::cout << "Operación no válida" << std::endl;
}

bool Operaciones::isNumber(std::string &string){
    std::string::iterator it = string.begin();

    while (it != string.end() && std::isdigit(*it)){
        it++;
    }

    return !string.empty() && it == string.end();
    
}

#endif //OPERACIONES_H