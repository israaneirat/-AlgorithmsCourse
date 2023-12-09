#include <iostream>
#include <chrono>
using namespace std;
//israa mofeed neirat

// Declare the factorial functions
int factorial_iterative(int n);
int factorial_recursive(int n);

double measure_time(int (*func)(int), int n) {
  auto start = chrono::high_resolution_clock::now();
  func(n);
  auto end = chrono::high_resolution_clock::now();
  return chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0;
}

int main() {
  int n_numbers;
  // Prompt the user for input
 cout << "How many numbers would you like to enter? ";
  cin >> n_numbers;
  // Process the numbers
  for (int i = 0; i < n_numbers; i++) {
    // Prompt the user for input
    cout << "Enter number " << i + 1 << ": ";
    int n;
    cin >> n;
    // Calculate the factorial
    double iterative_time = measure_time(factorial_iterative, n);
    double recursive_time = measure_time(factorial_recursive, n);
    // Print the results
    cout << "n = " << n << endl;
    cout << "Iterative time = " << iterative_time << " ms" << endl;
    cout << "Recursive time = " << recursive_time << " ms" << endl;
  }
  return 0;
}
// Implement the factorial functions
int factorial_iterative(int n) {
  int res = 1;
  for (int i = 1; i <= n; i++) {
    res *= i;
  }
  return res;
}
int factorial_recursive(int n) {
  if (n <= 1) {
    return 1;
  } else {
    return n * factorial_recursive(n - 1);
  }
}
