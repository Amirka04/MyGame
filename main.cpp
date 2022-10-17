#include <SFML/Graphics.hpp>
#include <math.h>
#include <stdio.h>
#include <GL/gl.h>

#include "player.h"
#include "constants.h"


using namespace sf;

int main(){

  Player Rects;

  RenderWindow win(VideoMode(WindowW, WindowH), "My Game");
  win.setFramerateLimit(60);
  

  while(win.isOpen()){
    Event ev;
    while(win.pollEvent(ev)){
      if(ev.type == Event::Closed)
        win.close();
    }

    glClearColor(0.4, 0.4, 0.4, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    Rects.output();

    win.display();
    win.clear();
  }

  return 0;
}
