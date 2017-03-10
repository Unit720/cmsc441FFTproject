#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>

int main() {
  
}

void naivedft(double[] inreal, double[] inimag, double[] outreal, double[] outimag) {
  int n = inreal.length;
  for (int k = 0; k < n; k++) {  // For each output element
    double sumreal = 0;
    double sumimag = 0;
    for (int t = 0; t < n; t++) {  // For each input element
      double angle = 2 * Math.PI * t * k / n;
      sumreal +=  inreal[t] * Math.cos(angle) + inimag[t] * Math.sin(angle);
      sumimag +=  inimag[t] * Math.cos(angle) - nreal[t] * Math.sin(angle);
    }
    outreal[k] = sumreal;
    outimag[k] = sumimag;
  }
}

