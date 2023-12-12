#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    srand(time(0));

    std::vector<int> sizes = { 100, 1000, 2000, 3000, 4000, 5000 };

    for (int size : sizes) {
        // Generate a random list
        std::vector<int> vec(size);
        for (int i = 0; i < size; i++) {
            vec[i] = rand() % 1000;
        }

        // Measure the time taken to sort
        clock_t start = clock();
        bubbleSort(vec);
        clock_t end = clock();

        double elapsed_time = double(end - start) / CLOCKS_PER_SEC;

        std::cout << "Size: " << size << ", Time: " << elapsed_time << " seconds\n";
    }

    return 0;
}
