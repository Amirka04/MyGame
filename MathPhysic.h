#ifndef MATHPHISIC_H
#define MATHPHISIC_H

#include <iostream>
#include <cmath>

using namespace std;

class physics{
protected:
  float boosts; // ускорение
  float speed; // скорость
  float MinSpeedIsNone; // Минимальныя скорость для поворота, если машина не едет
  float delSpeedInRotate; // Величина при которой мы будем уменьшать нашу скорость

public:
  void boost();
  void SpeedObject();
};


#endif
