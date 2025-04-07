#include <iostream>
#include <algorithm>

bool customCompare(float a, float b)
{
    return a > b; // Sort in descending order
}

float *AllocateArray(int size);
void SortArray(float *array, int size);

int main()
{
    int n;
    std::cout << "Set n: ";
    std::cin >> n;

    float *vet = AllocateArray(n);
    SortArray(vet, n);

    std::cout << "Sorted inputs: ";
    for (int i = 0; i < n; i++)
    {
        std::cout << vet[i] << " ";
    }
    std::cout << std::endl;

    delete[] vet; // Free the allocated memory
    return 0;
}

float *AllocateArray(int size)
{
    float *vet = new float[size];

    for (int i = 0; i < size; i++)
    {
        std::cout << "Waiting for input " << i << ": ";
        std::cin >> vet[i];
    }

    std::cout << "Inputs: ";
    for (int i = 0; i < size; i++)
    {
        std::cout << vet[i] << " ";
    }
    std::cout << std::endl;

    return vet;
}

void SortArray(float *array, int size)
{
    std::sort(array, array + size, customCompare);
}
