#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <math.h>
#include <GL/gl.h>
#include <stdio.h>

#include "constants.h"

using namespace sf;

class Player{
public:
  void draw(float px, float py, float sizeob){
    glBegin(GL_QUADS);
      glColor3f(ColorConv(128),ColorConv(128),ColorConv(128));
      glVertex2f( sizeob*delWind+px, sizeob+py);
      glVertex2f( sizeob*delWind+px, -sizeob+py);
      glVertex2f( -sizeob*delWind+px, -sizeob+py);
      glVertex2f( -sizeob*delWind+px, sizeob+py);
    glEnd();
  }

  void move(){
    if(Keyboard::isKeyPressed(Keyboard::Key::W)){
      x += sin(a * count) * 0.01;
      y += cos(a * count) * 0.01;
    }
    if(Keyboard::isKeyPressed(Keyboard::Key::S)){
      x -= sin(a * count) * 0.01;
      y -= cos(a * count) * 0.01;
    }
    if(Keyboard::isKeyPressed(Keyboard::Key::D)) count++;
    if(Keyboard::isKeyPressed(Keyboard::Key::A)) count--;
  }

  void output(){
    move();
    draw(x, y, sizeob);
  }



protected:
  float x = 0, y = 0;
  float sizeob = 0.1;
  float maxSpeed, speed;
  float count = 180, a = M_PI * 2 / count;
};


#endif
