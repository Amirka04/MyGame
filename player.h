#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <math.h>
#include <GL/gl.h>
#include <stdio.h>

// подключаемые наши инструменты
#include "constants.h"
#include "MathPhysic.h"


using namespace sf;

class Player{
public:
  // рисование
  void draw(float px, float py){
    glBegin(GL_QUADS);
      glColor3f(ColorConv(128),ColorConv(128),ColorConv(128));
      for(int i = 0; i < 4; i++){
        glVertex2f((coordX[i]/1.5*cos(count) - coordY[i]/1.5*sin(count))*delWind+px, (coordX[i]/1.5*sin(count) + coordY[i]/1.5*cos(count))+py );
      }
    glEnd();
  }

  // движение
  void move(){
    if(Keyboard::isKeyPressed(Keyboard::Key::W)){
      x += sin(count) * 0.01 * delWind *-1;
      y += cos(count) * 0.01;
    }
    if(Keyboard::isKeyPressed(Keyboard::Key::S)){
      x -= sin(count) * 0.01 * delWind * -1;
      y -= cos(count) * 0.01;
    }
    if(Keyboard::isKeyPressed(Keyboard::Key::A)) count+=0.03;
    if(Keyboard::isKeyPressed(Keyboard::Key::D)) count-=0.03;
  }

  // главный вызов методов
  void output(){
    move();
    draw(x, y);
  }


protected:
  // координаты
  float x = 0, y = 0;
  // угол поворота
  float count = 0;
  // высота и длина танка
  float sizeobW = 0.1, sizeobH = 0.2;
  // координаты вершин
  float *coordX = new float[4]{sizeobW, sizeobW, -sizeobW, -sizeobW};
  float *coordY = new float[4]{sizeobH, -sizeobH, -sizeobH, sizeobH};
};


#endif
