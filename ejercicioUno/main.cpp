#include <iostream>
#include "InfixToPostfix.h"

using namespace std;

int main(){
    InfixToPostFix* convertToPostFix = new InfixToPostFix();
    string expression = "(10-5+12)/3";
    string result = convertToPostFix->converter(expression);;
    cout <<"RESULTADO: " << result << endl;
    //cout << "Expresion a convertir: ";
    //cin >> expression;
    return 0;
    

    
    
    

}

