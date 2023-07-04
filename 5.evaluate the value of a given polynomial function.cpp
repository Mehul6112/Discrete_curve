#include <bits/stdc++.h>

int evaluate_polynomial(std::vector<int> coefficients, int n) {
    int result = 0;
    
    for (int i = 0; i < coefficients.size(); i++) {
        result += coefficients[i] * pow(n, i);
    }
    
    return result;
}

int main() {
    std::vector<int> coefficients = {9, 2, 4};
    int n = 5;
    int result = evaluate_polynomial(coefficients, n);
    std::cout << "f(" << n << ") = " << result << std::endl;
    
    return 0;
}
