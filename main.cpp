#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <iostream>
#include <vector>
#include "Core.h"
#include "GameObject.h"
#include "WindowManager.h"
#include "PhysicsManager.h"
#include "GraphicsManager.h"
using namespace std;
//singleton class Core contains all references to opengl
Core V;

int main(){
 V.vlock.setFPS(25.0);
 V.MAXOBJECTS=10;

 WindowManager windowmanager;
 GraphicsManager graphicsmanager;
 FPCamera player;

 windowmanager.MakeWindow();
 windowmanager.ShapeWindow();
 graphicsmanager.BuildDisplayLists();

 while(windowmanager.GAMEON){
  V.vlock.Start();

  //calculate logic for 75% of frame time
  while( V.vlock.getDelta() < V.vlock.logicTime ){
   cout<< "Frame Count: " << V.vlock.frameCount << endl;
   cout<< "Delta Time: " << V.vlock.deltaTime << endl;
   cout<< "Logic Time: " << V.vlock.logicTime << endl;
   windowmanager.Handler();
  }
  cout<<"exit handle loop"<<endl;
  //render frame for final 25% of frame time
  graphicsmanager.RenderFrame(&player);

  // V.vlock.getDelta();
  // if(V.vlock.deltaTime<40.0){
  //  cout<<"sleeping for "<<((V.vlock.deltaTime)/1000.0)<<" milliseconds"<<endl;
  //  sleep((40.0 - V.vlock.deltaTime)/1000.0);

  // }
  cout<<"done loop"<<endl;
 }

 return 0;
}