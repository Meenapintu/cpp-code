#include <iostream>
#include <vector>

int main() {
  std::vector<int> inptr = {2,3,4};
  std::vector<int> keep_cols = {4,5};
  for (auto j=0; j<3 && inptr.at(j)<=10 && inptr.at(j)>=3; j++) {
    std::cout << j << " " << inptr[j] << "\n";
  }
  return 0;
}
