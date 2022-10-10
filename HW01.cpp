#include <iostream>
#include <string>
#include <stack>

using namespace std;

string infixToPrefix(string);
string prefixToInfix(string);

int main(){
    
    string operation, newOperation;
    int i;
    
    cout << "Please enter your operation: ";
    getline(cin, operation);
    
    if(operation[0] != '('){
        cout << "Please use parentheses around all operands.\n";
        return 1;
    }
    
    for(i = 0; i <= operation.length(); i++){
        if(operation[i] == ' '){
            cout << "Please do not use spaces in the operation.\n";
            return 1;
        }
    }
    
    cout << "Thank you." << endl;
    cout << "Original operation: " << operation << endl;
    
    for(i = 0; i <= operation.length(); i++){
        if(isdigit(operation[i])){
            cout << "New operation: " << infixToPrefix(operation) << endl;
            break;
        }else if(operation[i] == '/' || operation[i] == '*' || operation[i] == '+' || operation[i] == '-'){
            cout << "New operation: " << prefixToInfix(operation) << endl;
            break;
        }
    }
    
    return 0;
}


string infixToPrefix(string operation){
    
    string newOperation = operation;
    stack<string> operators;
    int i, t;
    
    for(i = operation.length() - 1; i >= 0; --i){
        if(operation[i] == '/' || operation[i] == '*' || operation[i] == '+' || operation[i] == '-'){
            string k;
            k.push_back(operation[i]);
            operators.push(k);
            newOperation = newOperation.substr(0, i) + newOperation.substr(i+1);
        }
    }
    
    t = newOperation.length() - 1;
    
    for(i = t; i >= 0; --i){
        if(newOperation[i] == ')'){
            for(int k = i - 1; k >=0; --k){
                if(newOperation[k] == '('){
                    string x = operators.top();
                    operators.pop();
                    newOperation = newOperation.substr(0, k+1) + x + newOperation.substr(k+1);
          }
        }
      }
    }
    
    return newOperation;
    }

string prefixToInfix(string operation){
    string newOperation = operation;
    stack <string> t;
    int i;
    
    for(i = operation.length() - 1; i >= 0; --i){
        if(operation[i] == '(' || operation [i] == ')'){
        }else if(operation[i] == '/' || operation[i] == '*' || operation[i] == '+' || operation[i] == '-'){
            string k = t.top();
            t.pop();
            string y = t.top();
            t.pop();

            string g = k + operation[i] + "" + y;
            t.push(g);
        }else{
            string k;
            k.push_back(operation[i]);
            t.push(k);
        }
    }

    newOperation = t.top();
    t.pop();
    
    newOperation = '(' + newOperation + ')';
    
    return newOperation;
}

/*
 
               *    *
          *              *
     *       *    *           *
*       *                 *        *
                _..  *
  ___..-"""-.  `)^|   .-"""-..___
 `-...___ '=.'-.'  \-'.=' ___...-'
         `\  '  _|_  '  /`
           '--;  |  ;--'
              /\   /\
             ( /;-;\ )
              '-...-'
 
 */


