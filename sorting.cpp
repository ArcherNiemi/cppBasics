#include <iostream>
#include <ctime>
#include <algorithm>
#include <utility> // for std::swap

// QuickSort helpers
int partition(int* array, int low, int high)
{
    // Median-ish pivot choice
    int pivot = array[(low + high) / 2];

    while (low <= high)
    {
        while (array[low] < pivot)
            low++;

        while (array[high] > pivot)
            high--;

        if (low <= high)
        {
            std::swap(array[low], array[high]);
            low++;
            high--;
        }
    }

    return low;
}

void quickSort(int* array, int low, int high)
{
    if (low >= high)
        return;

    int index = partition(array, low, high);

    if (low < index - 1)
        quickSort(array, low, index - 1);

    if (index < high)
        quickSort(array, index, high);
}

void createRandomArray(int* array, int size);
void basicSort(int* array, int size);
void advancedSort1(int* array, int size);
void advancedSort2(int* array, int size);
void advancedSort3(int* array, int size);
void standardSort(int* array, int size);
void gptSort(int* array, int size);
void printArray(int* array, int size);

int main() {
    std::cout << "Start\n";

    std::srand(std::time(nullptr));

    int simulations = 5000000;

    int arraySize = 100;
    
    int randomArray[arraySize];

    for(int i = 0; i < simulations; i++){
        createRandomArray(randomArray,arraySize);
    }

    std::cout << "End";

    return 0;
}

void createRandomArray(int* array, int size){ //4.1
    for(int i = 0; i < size; i++){
        array[i] = std::rand() % size + 1;
    }
}

void basicSort(int* array, int size){ //104.6 - 4.1 = 100.5
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

void advancedSort1(int* array, int size){ //56.7 - 4.1 = 52.6
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

void advancedSort2(int* array, int size){ //54.8 - 4.1 = 50.7
    for(int i = 0; i < size-1; i++){
        if(array[i] > array[i+1]){
            int temp = array[i];
            array[i] = array[i+1];
            array[i+1] = temp;
            i -= 2;
        }
    }
}

void advancedSort3(int* array, int size){ //8.1 - 4.1 = 4.0
    int newArray[size] = {0};
    for(int i = 0; i < size; i++){
        newArray[array[i]-1]++;
    }
    int currentIndex = 0;
    for(int i = 0; i < size; i++){
        while(newArray[i] != 0){
            newArray[i]--;
            array[currentIndex] = i+1;
            currentIndex++;
        }
    }
}

void standardSort(int* array, int size) { //23.8 - 4.1 = 19.7
    std::sort(array, array + size);
}

void gptSort(int* array, int size){ //23.4 - 4.1 = 19.3
    if (size <= 1)
        return;

    quickSort(array, 0, size - 1);
}

void printArray(int* array, int size){
    std::cout << "array\n";
    for(int i = 0; i < size; i++){
        std::cout << array[i] << '\n';
    }
    std::cout << "array\n";
}