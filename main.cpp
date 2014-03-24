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


 //list of enemy positions;
 Vector3f enemyPosition[4]={ Vector3f() , Vector3f() , Vector3f() , Vector3f()};






 windowmanager.MakeWindow();
 windowmanager.ShapeWindow();
 graphicsmanager.BuildDisplayLists();

 while(graphicsmanager.RenderFrame(&player)){
  V.vlock.Start();

  //calculate logic for 75% of frame time
  while( V.vlock.getDelta() < V.vlock.logicTime ){

   windowmanager.Handler(&player);

  }
  cout << V.vlock.frameCount << endl;
 }

 return 0;
}