#include <iostream>

int main(){
    std::string input;

    std::cout << "Enter Basic Formula: ";
    std::getline(std::cin, input);

    int count = 0;

    std::string inputPart = "";
    for(int i = 0; i < size(input); i++){
        if(input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/'){
            break;
        }
        inputPart.push_back(input[i]);
        count++;
    }

    double num1 = std::stoi(inputPart);
    inputPart = "";

    char operation = input[count];

    for(int i = count+1; i < size(input); i++){
        inputPart.push_back(input[i]);
    }

    double num2 = std::stoi(inputPart);

    double output;
    if(operation == '+'){
        output = num1 + num2;
    } else if(operation == '-'){
        output = num1 - num2;
    } else if(operation == '*'){
        output = num1 * num2;
    }else if(operation == '/'){
        output = num1 / num2;
    }

    std::cout << output;

    return 0;
}