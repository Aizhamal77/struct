#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include <cmath>

using namespace std;

class Token {
public:
    virtual float getNum() = 0;  
    virtual char getOperator() = 0;  
    virtual ~Token() {}
};

class Operator : public Token {
private:
    char oper;

public:
    Operator(char c) : oper(c) {}

    char getOperator() override {
        return oper;
    }

    float getNum() override {
        return 0.0f;
    }
};

class Num : public Token {
private:
    float value;

public:
    Num(float v) : value(v) {}

    float getNum() override {
        return value;
    }

    char getOperator() override {
        return '\0';
    }
};

class Stack {
private:
    Token* tokens[100];
    int top;

public:
    Stack() : top(-1) {}

    void push(Token* token) {
        if (top < 99) {
            tokens[++top] = token;
        }
        else {
            cout << "Ñòåê ïåðåïîëíåí!" << endl;
        }
    }

    Token* pop() {
        if (top >= 0) {
            return tokens[top--];
        }
        else {
            cout << "Ñòåê ïóñò!" << endl;
            return nullptr;
        }
    }

    bool isEmpty() const {
        return top == -1;
    }
};

float compute(Stack& stack) {
    stack.push(new Num(6.02)); 

    while (!stack.isEmpty()) {
        Token* token = stack.pop();
        if (token->getOperator() == '\0') {  
            cout << "×èñëî: " << token->getNum() << endl;
        }
        else { 
            cout << "Îïåðàòîð: " << token->getOperator() << endl;
        }
        delete token; 
    }

    return 0; 
}

int main() {
    setlocale(LC_ALL, "Rus");

    Stack stack;
    stack.push(new Operator('+')); 
    stack.push(new Num(3.14159)); 
    compute(stack);

    return 0;
}
