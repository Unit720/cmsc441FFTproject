#ifndef _PinkNoise_H
#define _PinkNoise_H

// Technique by Larry "RidgeRat" Trammell 3/2006
// http://home.earthlink.net/~ltrammell/tech/pinkalg.htm
// implementation and optimization by David Lowenfels

#include <cstdlib>
#include <ctime>

#define PINK_NOISE_NUM_STAGES 3

class PinkNoise {
public:
  PinkNoise() {
    srand ( time(NULL) ); // initialize random generator
    clear();
  }

  void clear() {
    for( size_t i=0; i< PINK_NOISE_NUM_STAGES; i++ )
      state[ i ] = 0.0;
    }
    
  double tick() {
    static const double RMI2 = 2.0 / double(RAND_MAX); // + 1.0; // change for range [0,1)
    static const double offset = A[0] + A[1] + A[2];

  // unrolled loop
    double temp = double( rand() );
    state[0] = P[0] * (state[0] - temp) + temp;
    temp = double( rand() );
    state[1] = P[1] * (state[1] - temp) + temp;
    temp = double( rand() );        
    state[2] = P[2] * (state[2] - temp) + temp;
    return ( A[0]*state[0] + A[1]*state[1] + A[2]*state[2] )*RMI2 - offset;
  }

protected:
  double state[ PINK_NOISE_NUM_STAGES ];
  static const double A[ PINK_NOISE_NUM_STAGES ];
  static const doublefloat P[ PINK_NOISE_NUM_STAGES ];
};

const double PinkNoise::A[] = { 0.02109238, 0.07113478, 0.68873558 }; // rescaled by (1+P)/(1-P)
const double PinkNoise::P[] = { 0.3190,  0.7756,  0.9613  };

#endif

