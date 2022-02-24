#include <iostream>
#include <random>
#include <ctime>
#include <algorithm> 
using namespace std;

bool isExists(int number, int *n) {
    for (int i{ 0 }; i < sizeof(n); i++) {
        if (n[i] == number) {
            return true;
        }
    }
    return false;
}

bool comparator(int a, int b) {
    return (a > b);
}

int* arrayGenerator(int n) {
    srand(time(NULL));
    int* arraysSize = new int[n];
    int** arrays = new int*[n];
    int size{ 0 };
    for (int i{ 0 }; i < n; i++) {
        size = rand() % 10 + 1;
        while (isExists(size, arraysSize)) {
            size = rand() % 10 + 1;
        }
        

        int* newArray = new int[size];
        arraysSize[i] = size;
        
        arrays[i] = (int*) malloc(sizeof(int) * size);
        int* p = arrays[i];
        for (int j{ 0 }; j < size; j++) {
            newArray[j] = rand() % 10 + 2;
        }
        if (i % 2 != 0) {
            sort(newArray, newArray + size);
        }
        else {
            sort(newArray, newArray + size, comparator);
        }
        for (int j{ 0 }; j < size; j++) {
            *p = newArray[j];
            p++;
        }
        size = 0;
        delete[] newArray;
    }
    
    
    delete[] arraysSize;
    return *arrays;

    
    
}


int main()
{
    srand(time(NULL));
    int n{ 0 };
    cin >> n;
    

    arrayGenerator(n);
    
    
}
