#include <iostream>
#include <vector>

template <typename T>
void printVector(std::vector<T> &arr) {
  for (T &elem : arr) {
    std::cout << elem << " ";
  }
  std::cout << std::endl;
}

void bubbleSort(std::vector<int> &arr) {
  for (int i = 0, n = arr.size(); i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        std::swap(arr[j], arr[j + 1]);
      }
    }
  }
}

int main(int argc, char **argv) {
  int n;
  std::cin >> n;
  std::vector<int> input;
  input.resize(n);

  for (int i = 0; i < n; i++) {
    std::cin >> input[i];
  }

  bubbleSort(input);

  printVector(input);
  return 0;
}