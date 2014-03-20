#define WINDOWMANAGER_H

static int GLAttr[]={
 GLX_RGBA,
 GLX_RED_SIZE,6,
 GLX_GREEN_SIZE, 6,
 GLX_BLUE_SIZE, 6,
 GLX_DEPTH_SIZE,24,
 GLX_DOUBLEBUFFER,
 None
};

class WindowManager{
public:
 bool GAMEON;

 WindowManager(){//constructor
  GAMEON = true;
 }

 void MakeWindow(){
  V.dpy=XOpenDisplay(0);
  V.vi=glXChooseVisual(V.dpy,DefaultScreen(V.dpy),GLAttr);
  V.cmap=XCreateColormap(V.dpy,RootWindow(V.dpy,V.vi->screen),V.vi->visual,AllocNone);
  V.glc=glXCreateContext(V.dpy,V.vi,NULL,GL_TRUE);
  V.swa.colormap=V.cmap;
  V.swa.border_pixel=0;
  V.swa.event_mask=ExposureMask|ButtonPressMask|StructureNotifyMask|KeyPressMask|PointerMotionMask;
  V.win=XCreateWindow(V.dpy,RootWindow(V.dpy,V.vi->screen),
   0,0,600,600,0,
   V.vi->depth,
   InputOutput,
   V.vi->visual,
   CWBorderPixel|CWColormap|CWEventMask,
   &V.swa);
  XSetStandardProperties(V.dpy,V.win,
   "pRESIDENT EVIL",
   "pRESIDENT EVIL",
   None,None,None,NULL);
  glXMakeCurrent(V.dpy,V.win,V.glc);
  XMapWindow(V.dpy,V.win);
 };

 void ShapeWindow(){
  glEnable(GL_DEPTH_TEST);
  XGetWindowAttributes(V.dpy,V.win,&V.gwa);
  glViewport(0,0,V.gwa.width,V.gwa.height);
  glClearDepth(100.0);
  glClearColor(1,1,1,1);
 };

 void Handler(){
  if(XPending(V.dpy)){
   XNextEvent(V.dpy,&V.xev);
   ///handle keyboard presses
   if(V.xev.type==KeyPress){
    char buffer[31];
    KeySym keysym;
    XLookupString(&V.xev.xkey,buffer,30,&keysym,NULL);
    ///close window and exit on escape key press
    if(keysym == XK_Escape){
     glXMakeCurrent(V.dpy,None,NULL);
     glXDestroyContext(V.dpy,V.glc);
     XDestroyWindow(V.dpy,V.win);
     XCloseDisplay(V.dpy);
     exit(0);
    }
    if(keysym == XK_Up){}
    if(keysym == XK_Down){}
    if(keysym == XK_Right){}
    if(keysym == XK_Left){}
    if((keysym == XK_q)||(keysym == XK_Q)){}
   }
  }
 };




};

