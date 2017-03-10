#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
#include "PinkNoise.h"

#define SIGNALLENGTH 65535
void naivedft(double[], double[], double[], double[]);
int main() {
  PinkNoise noisegen;
  double signal[SIGNALLENGTH];
  double inreal[SIGNALLENGTH];
  double inimag[SIGNALLENGTH];
  double outreal[SIGNALLENGTH];
  double outimag[SIGNALLENGTH];
  
  for (int i = 0; i < SIGNALLENGTH; i++){
    inreal[i] = noisegen.tick();
    std::cout << inreal[i] << " ";
  }
  std::cout << std::endl;
  naivedft(signal, inimag, outreal, outimag);

  for (int i = 0; i < SIGNALLENGTH; i++){
    std::cout << outreal[i] << " ";
  }
  std::cout << std::endl;
  
}

void naivedft(double* inreal, double* inimag, double* outreal, double* outimag) {
  int n = sizeof(inreal) / sizeof(double);
  for (int k = 0; k < n; k++) {  // For each output element
    double sumreal = 0;
    double sumimag = 0;
    for (int t = 0; t < n; t++) {  // For each input element
      double angle = 2 * M_PI * t * k / n;
      sumreal +=  inreal[t] * cos(angle) + inimag[t] * sin(angle);
      sumimag +=  inimag[t] * cos(angle) - inreal[t] * sin(angle);
    }
    outreal[k] = sumreal;
    outimag[k] = sumimag;
  }
}

