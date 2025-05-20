#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <numeric>

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void swapBasedInsertionSort(std::vector<int> &arr)
{
    int size = arr.size();
    for (int i = 1; i < size; i++)
    {
        int j = i;
        while (j > 0 && arr[j] < arr[j - 1])
        {
            swap(arr[j], arr[j - 1]);
            j--;
        }
    }
}

void shiftBasedInsertionSort(std::vector<int> &arr)
{
    int size = arr.size();
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

std::vector<int> generateRandomVector(int size, int maxVal = 100000)
{
    std::vector<int> vec(size);
    for (int &x : vec)
        x = rand() % maxVal;
    return vec;
}

long long averageTime(std::vector<long long> &times)
{
    return std::accumulate(times.begin(), times.end(), 0LL) / times.size();
}

int main()
{
    srand(time(0));
    const int N = 5000;    // Size of the array
    const int TRIALS = 10; // Number of times to run each

    std::vector<long long> swapTimes;
    std::vector<long long> shiftTimes;

    for (int t = 0; t < TRIALS; t++)
    {
        std::vector<int> original = generateRandomVector(N);

        // Swap-based sort
        std::vector<int> arr1 = original;
        auto start1 = std::chrono::high_resolution_clock::now();
        swapBasedInsertionSort(arr1);
        auto end1 = std::chrono::high_resolution_clock::now();
        swapTimes.push_back(std::chrono::duration_cast<std::chrono::milliseconds>(end1 - start1).count());

        // Shift-based sort
        std::vector<int> arr2 = original;
        auto start2 = std::chrono::high_resolution_clock::now();
        shiftBasedInsertionSort(arr2);
        auto end2 = std::chrono::high_resolution_clock::now();
        shiftTimes.push_back(std::chrono::duration_cast<std::chrono::milliseconds>(end2 - start2).count());
    }

    long long avgSwap = averageTime(swapTimes);
    long long avgShift = averageTime(shiftTimes);

    std::cout << "=== Average Time Over " << TRIALS << " Runs ===\n";
    std::cout << "Swap-based Insertion Sort:  " << avgSwap << " ms\n";
    std::cout << "Shift-based Insertion Sort: " << avgShift << " ms\n";

    if (avgSwap < avgShift)
        std::cout << "\n🔄 Swap-based is faster on average.\n";
    else if (avgShift < avgSwap)
        std::cout << "\n📥 Shift-based is faster on average.\n";
    else
        std::cout << "\n⏱️ Both are equally fast on average.\n";

    return 0;
}
