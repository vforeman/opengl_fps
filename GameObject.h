#define GAMEOBJECT_H
#include "vmath.h"







/*
concrete classes:
FPCamera, Bullet, Enemy, Background, Tool
*/
void DrawBlock(){
  glPushMatrix();

       //Enable vertex arrays we want to draw with
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_NORMAL_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    //Connect the arrays themselves
    glVertexPointer(3, GL_FLOAT, 0, faces);
    glNormalPointer(GL_FLOAT, 0, normals);
    glColorPointer(4, GL_FLOAT, 0, colors);

    //Draw command - draw everything
    glDrawArrays(GL_QUADS, 0, 6*4);


    //Disable vertex arrays that are no longer in use
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_NORMAL_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);

  glPopMatrix();


};

void DrawBlock(Vector3f pos){
 glPushMatrix();
   glTranslatef(pos.x,pos.y,pos.z);
   /*if( ( pos.x / 2 ) == 1 ){ glRotatef( 90.0 , 1.0 , 0.0 , 0.0 ); }*/
      //Enable vertex arrays we want to draw with
   DrawBlock();

 glPopMatrix();


};

class Vertex{
public:
 Vector3f v_pos;
 Vector3f v_hue;
};

class Face: public Vertex{
public:
 float radius;
 Vertex vertex[4];
 Vector3f f_norm;
 Vector3f f_pos;
 Vector3f f_hue;

 ///Constructor
 Face(){
  f_hue = Vector3f(0,1,0);//default green
  vertex[0].v_pos = Vector3f(0,0,0);
  vertex[1].v_pos = Vector3f(0.1,0,0);
  vertex[2].v_pos = Vector3f(0.1,0.1,0);
  vertex[3].v_pos = Vector3f(0,0.1,0);
  f_pos = Vector3f(.05,.05,0.0);
 };

 //calculate normal vector
 Vector3f CalcNorm(){

 };
};




class Block: public Vertex{
public:
 Vector3f b_position;
 Vector3f b_dimension;

 Block(float x, float y , float z){
  setPosition( x , y , z );
 };

 Vector3f getPosition(){
  return b_position;
 };

 Vector3f getDimension(){
  return b_dimension;
 };

 void setDimension(float l , float h , float w){
  b_dimension = Vector3f( l , h , w );
 };

 void setPosition(float x, float y, float z){
  b_position = Vector3f(x , y , z);
 };


};

class BackgroundObject: public Block{
public:
  Vector2f area;

  //CONSTRUCTOR



};

class FPCamera{
public:
 Vector3f c_posthen;//last position
 Vector3f c_pos;//current position
 Vector3f c_mouse;//coords of the mouse
 Quaternion<float> c_orientation;
 bool isDirty,looky,lookx,move;
 float pitch, heading;//angle parameter for rotation matrices
 FPCamera(){
  c_mouse = Vector3f( 0 , 0 , 1 );
  c_pos = Vector3f();
  c_orientation = Quaternion<float>().fromAxisRot( c_pos , 0.0 );
  isDirty = true;
  looky = false;
  lookx = false;
  move = false;
  pitch = 0.0;
  heading = 0.0;
 };

 //update the prjection matrix if needed
 void Update(){
  setDirty( true );
  //glPushMatrix();

  glMatrixMode( GL_PROJECTION );
  glLoadIdentity();
  gluPerspective( 65 , 1 , 0.001 , 100.0 );
  glTranslatef(0,0,-1);

  glTranslatef( 0 + c_pos.x , 1 + c_pos.y , 0 + c_pos.z );
  glRotatef( pitch , 0 , 1 , 0 );
  glRotatef( heading , 1 , 0 , 0 );


  //glPopMatrix();
 };

 //rotate up or down, rotates around
 //the x-axis based on the variable mouse.y
 void LookY(float ang){

 };

 //rotate up or down, rotates around
 //the y-axis based on the variable mouse.x
 void LookX(float ang){

 };

 //
 void Move(){

 };

 //set the value of isDirty, true = render
 void setDirty(bool b){
  isDirty = b;
 };

 void Forward(){

  ++c_pos.z;

 };

 void Backward(){

  --c_pos.z;
 };

 void Left(){

  ++c_pos.x;
 };

 void Right(){

  --c_pos.x;
 };
};

