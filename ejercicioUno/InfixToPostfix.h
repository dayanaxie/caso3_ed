#include <iostream>
#include "Stack.h"

using namespace std;

class InfixToPostFix{
    public:
    // verificar que el caracter sea un operdor o no
    bool isOperator(char currentChar){
	    if (currentChar == '+' || currentChar == '-' || currentChar == '*' ||currentChar == '/' ||currentChar == '%'){
		    return true;
	    }
	    else{
		    return false;
	    }
    }
    // precedencia de los operadores
    int precedence(char currentChar) {
        
        if (currentChar == '/' || currentChar == '*' || currentChar == '%'){
            return 2;
        }
        else if(currentChar == '+' || currentChar == '-'){
            return 1;
        }
        else{
            return -1;
        }
    }
    string converter(string pExpression){
        Stack<char>* stack = new Stack<char>();
        string resultPostFix;
        int currentChar = 0;
        while(currentChar < pExpression.length()){
            if(isOperator(pExpression[currentChar])){
                resultPostFix += pExpression[currentChar];
            }
            // si es un parentesis abierto se agrega 
            else if(pExpression[currentChar] == '('){
                stack->push(pExpression[currentChar]);
            }
            // si es un parentesis cerrado se agregan los numeros que estan en el centro y se vacia la pila
            else if(pExpression[currentChar] == ')'){
                while(stack->top() != '('){
                    resultPostFix += stack->top();
                    stack->pop();
                }
                stack->pop();
            }
            else{
                // se revisa que la pila no este vacia y se verifica la precendencia
                while(!stack->isEmpty() && precedence(pExpression[currentChar]) <= precedence(stack->top())){
                    resultPostFix += stack->top();
                    stack->pop();
                }
                stack->push(pExpression[currentChar]);
            }

        
        ++currentChar;
        }
        return resultPostFix;
    }
};

