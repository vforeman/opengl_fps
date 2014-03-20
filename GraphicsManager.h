#define GRAPHICSMANAGER_H

class GraphicsManager{
public:
 Block * blocklist;
 FPCamera * p;//pointer to camera object

 //CONSTRUCTOR
 GraphicsManager(  ){
  //create an empty list of object pointers
  blocklist = new Block[ V.MAXOBJECTS ];
 };

 //draw frame
 void RenderFrame( FPCamera * P ){
  // p = P;//bind camera/player to graphics manager
  if( P->isDirty ){ P->Update(); }//
  glMatrixMode( GL_MODELVIEW );
  glLoadIdentity();
  glXSwapBuffers(V.dpy,V.win);
 };

 void BuildDisplayLists(){


 };

};


