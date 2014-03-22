#define CORE_H
#include <X11/Xlib.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glx.h>
#include <sys/time.h>

#define green {0,1,0,1}
#define cyan {0,1,1,1}
#define yellow {1,1,0,1}
#define red {1,0,0,1}
#define blue {0,0,1,1}
#define magenta {1,0,1,1}

//Vertex array for faces of a cube
GLfloat faces[6][4][3] ={

 { { .9, .9, .9}, { .9,-.9, .9}, { .9,-.9,-.9}, { .9, .9,-.9} },
 { { .9, .9,-.9}, { .9,-.9,-.9}, {-.9,-.9,-.9}, {-.9, .9,-.9} },
 { {-.9, .9,-.9}, {-.9,-.9,-.9}, {-.9,-.9, .9}, {-.9, .9, .9} },
 { {-.9, .9, .9}, {-.9,-.9, .9}, { .9,-.9, .9}, { .9, .9, .9} },
 { {-.9, .9,-.9}, {-.9, .9, .9}, { .9, .9, .9}, { .9, .9,-.9} },
 { { .9,-.9, .9}, { .9,-.9,-.9}, {-.9,-.9,-.9}, {-.9,-.9, .9} }

};

//Vertex array for normals of the cube
GLfloat normals[6][4][3] ={

 { { 1, 0, 0} , { 1, 0, 0} , { 1, 0, 0} , { 1, 0, 0} },
 { { 0, 0,-1} , { 0, 0,-1} , { 0, 0,-1} , { 0, 0,-1} },
 { {-1, 0, 0} , {-1, 0, 0} , {-1, 0, 0} , {-1, 0, 0} },
 { { 0, 0, 1} , { 0, 0, 1} , { 0, 0, 1} , { 0, 0, 1} },
 { { 0, 1, 0} , { 0, 1, 0} , { 0, 1, 0} , { 0, 1, 0} },
 { { 0,-1, 0} , { 0,-1, 0} , { 0,-1, 0} , { 0,-1, 0} }

};



//Vertex array of Colours for the cube
GLfloat colors[6][4][4] ={
 {green,green,green,green},
 {cyan,cyan,cyan,cyan},
 {yellow,yellow,yellow,yellow},
 {red,red,red,red},
 {blue,blue,blue,blue},
 {magenta,magenta,magenta,magenta},
};

class Vlock{
public:
 timeval start,end;
 double FPS;//frames per second
 double mSPF;//milliseconds per frame
 long double deltaTime;//frame time
 double logicTime;//max time allotted to event handling
 double renderTime;//max time allotted to rendering
 double logicPercentage;//percentage of mSPF for logic
 double renderPercentage;//percentage of mSPF for render
 int frameCount;//number of frames counted this run

 //CONSTRUCTOR
 Vlock(){
  //DEFAULT allottment times
  logicPercentage = 0.75;
  renderPercentage = 0.25;
  frameCount=0;
 };


 //start timer
 void Start(){
  deltaTime = 0.0;
  ++frameCount;
  while(gettimeofday( &start , NULL )!=0){}
 };

 //stop timer
 void MarkTime(){
  while(gettimeofday( &end , NULL )!=0){}
  deltaTime = ( end.tv_usec - start.tv_usec ) / 1000.0;
  if(deltaTime<0){
   deltaTime=logicTime+30;
  }
 };

 //calculate time partitions
 void setFPS(double fps){
  FPS = fps;
  mSPF = 1000.0 / FPS;
  logicTime = mSPF * logicPercentage;
  renderTime = mSPF * renderPercentage;
 };

 //calculate and return deltaTime
 double getDelta(){
  MarkTime();
  return deltaTime;
 };

};


extern struct Core{
 int MAXOBJECTS;
 Display *dpy;
 Window win;
 XVisualInfo *vi;
 Colormap cmap;
 GLXContext glc;
 XSetWindowAttributes swa;
 XWindowAttributes gwa;
 XEvent xev;
 Vlock vlock;
 enum Shape { SPHERE };
}V;

