#include <iostream>
#include <vector>

template <typename T>
void printVector(std::vector<T> &arr) {
  for (T &elem : arr) {
    std::cout << elem << " ";
  }
  std::cout << std::endl;
}

void merge(std::vector<int> &arr, int p, int q, int r) {
  int n1 = q - p + 1;
  int n2 = r - q;

  std::vector<int> L(n1, 0);
  std::vector<int> R(n2, 0);

  for (int i = 0; i < n1; i++) {
    L[i] = arr[p + i];
  }
  for (int i = 0; i < n2; i++) {
    R[i] = arr[q + 1 + i];
  }

  int i = 0;
  int j = 0;
  int k = p;

  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
  }
}

void mergeSort(std::vector<int> &arr, int p, int r) {
  if (p < r) {
    int q = p + (r - p) / 2;
    mergeSort(arr, p, q);
    mergeSort(arr, q + 1, r);
    merge(arr, p, q, r);
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

  mergeSort(input, 0, input.size() - 1);

  printVector(input);
  return 0;
}