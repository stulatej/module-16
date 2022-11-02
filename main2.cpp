#include <iostream>
#include <string>

int main() {
    std::string first;
    std::string second;
    std::cout<<"Enter string 1 ";
    std::cin>>first;
    std::cout <<"Enter string 2 ";
    std::cin >>second;
    first +=second;
    double number = std::stod(first);
    std::cout<<number<<std::endl;

}