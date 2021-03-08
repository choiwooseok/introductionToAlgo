#include <iostream>
#include <vector>

template <typename T>
void printVector(std::vector<T> &arr) {
  for (T &elem : arr) {
    std::cout << elem << " ";
  }
  std::cout << std::endl;
}

void insertionSort(std::vector<int> &arr) {
  if (arr.size() <= 1) {
    return;
  }
  for (int j = 1, n = arr.size(); j < n; j++) {
    int key = arr[j];
    int i = j - 1;

    // arr[j] 의 위치가 나올때까지 한칸씩 밀어내기
    while (i >= 0 && arr[i] > key) {
      // printVector(arr);
      arr[i + 1] = arr[i];
      i -= 1;
    }
    arr[i + 1] = key;
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

  insertionSort(input);

  printVector(input);
  return 0;
}