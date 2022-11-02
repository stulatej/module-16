#include <iostream>
#include <string>
#include <sstream>

std::string result (double number1, char operation, double number2){
    double result;
    if (operation == '+') {
        result = number1+number2;
        return std::to_string(result);
    }if (operation == '-') {
        result = number1-number2;
        return std::to_string(result);
    }if (operation == '*') {
        result = number1*number2;
        return std::to_string(result);
    }if (operation == '/') {
        result = number1/number2;
        return std::to_string(result);
    } else {
        return "Incorrect!";
    }
}

int main () {
    //ввод строки пользователем
    std::string operations;
    std::cout<<"Enter operation: ";
    std::cin>>operations;
    //text
    std::stringstream text;
    text<<operations;

    //парс
    double number1, number2;
    char operation;
    text >> number1 >> operation >> number2;
    std::cout << number1 << " " << operation<<" " << number2 << " " << " = "
    << result (number1, operation, number2) << std::endl;



}