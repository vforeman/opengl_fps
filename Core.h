#define CORE_H
#include <X11/Xlib.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glx.h>
#include <sys/time.h>

class Vlock{
public:
 timeval start,end;
 double FPS;//frames per second
 double mSPF;//milliseconds per frame
 double deltaTime;//frame time
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
  gettimeofday( &start , NULL );
 };

 //stop timer
 void MarkTime(){
  gettimeofday( &end , NULL );
  deltaTime = ( end.tv_usec - start.tv_usec ) / 1000.0;
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

