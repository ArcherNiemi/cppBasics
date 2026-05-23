#include <iostream>
#include <ctime>

void createRandomArray(int* array, int size);
void basicSort(int* array, int size);
void advancedSort1(int* array, int size);
void advancedSort2(int* array, int size);
void printArray(int* array, int size);

int main() {
    std::cout << "Start\n";

    std::srand(std::time(nullptr));

    int simulations = 1000000;

    int arraySize = 100;
    
    int randomArray[arraySize];

    for(int i = 0; i < simulations; i++){
        createRandomArray(randomArray,arraySize);
        advancedSort2(randomArray,arraySize);
    }

    std::cout << "End";

    return 0;
}

void createRandomArray(int* array, int size){
    for(int i = 0; i < size; i++){
        array[i] = std::rand() % size + 1;
    }
}

void basicSort(int* array, int size){ //18.1
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size-1; j++){
            int num1 = array[j];
            int num2 = array[j+1];
            if(num1 > num2){
                array[j+1] = num1;
                array[j] = num2;
            }
        }
    }
}

void advancedSort1(int* array, int size){ //10.3
    for(int i = 0; i < size-1; i++){
        int num1 = array[i];
        int num2 = array[i+1];
        if(num1 > num2){
            array[i+1] = num1;
            array[i] = num2;
            i -= 2;
        }
    }
}

void advancedSort2(int* array, int size){ //9.7
    for(int i = 0; i < size-1; i++){
        if(array[i] > array[i+1]){
            int temp = array[i];
            array[i] = array[i+1];
            array[i+1] = temp;
            i -= 2;
        }
    }
}

void printArray(int* array, int size){
    std::cout << "array\n";
    for(int i = 0; i < size; i++){
        std::cout << array[i] << '\n';
    }
    std::cout << "array\n";}