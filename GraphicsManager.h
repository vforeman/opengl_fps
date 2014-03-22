#define GRAPHICSMANAGER_H

class GraphicsManager{
public:
 //Block * blocklist;
 FPCamera * p;//pointer to camera object
 GLuint index;

 //CONSTRUCTOR
 GraphicsManager(  ){
  //create an empty list of object pointers
  //blocklist = new Block[ V.MAXOBJECTS ];
 };

 //draw frame
 bool RenderFrame( FPCamera * P ){
  // p = P;//bind camera/player to graphics manager
  if( P->isDirty ){ P->Update(); }//

  glMatrixMode( GL_MODELVIEW );

  /**
  static background rendering
  **/
  glLoadIdentity();
  //DrawDisplayLists();
  DrawGround( 50 , -4 ,  50 ); //50 x 50 ground -4 elevation

  /**
  dynamic foreground rendering
  **/
  /*Block(1,1,-5).*/DrawBlock();
  DrawBlock( Vector3f( -2 , 2 , -3 ) );
  glXSwapBuffers( V.dpy , V.win );
  glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

  return true;
 };

 void BuildDisplayLists(){
  index=glGenLists(1);
  glNewList(index,GL_COMPILE);
   glBegin(GL_QUADS);
    glColor3f(1,0,0);
    glVertex3f(-20,-4,-20);
    glVertex3f(20,-4,-20);
    glVertex3f(20,-4,20);
    glVertex3f(-20,-4,20);
   glEnd();
  glEndList();

 };

 void DrawDisplayLists(){
  glCallList(index);
 };

 void DrawGround( float width , float elevation ,  float length ){
  Vector2f _worldSize = Vector2f( width, length);
  for(int xx = ( 0 - ( _worldSize.x / 2 ) ); xx < ( _worldSize.x / 2 ); ++xx)
  {
   for(int zz = (0 - ( _worldSize.y / 2 ) ); zz < ( _worldSize.y /2 ); ++zz)
   {
    DrawBlock( Vector3f( xx , elevation , zz ) );
   }
  }

 };

};


