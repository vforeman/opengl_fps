#define GAMEOBJECT_H
#include "vmath.h"
/*
concrete classes:
FPCamera, Bullet, Enemy, Background, Tool
*/

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
 float scale;
 Face faces[6];//{front,top,back,bottom,left,right}
 Vector3f b_center;
 Vector3f b_speed;
 Vector3f b_hue;
 Quaternion<float> b_orientation;

 Block(){
  b_hue = faces[0].f_hue;
  b_center = Vector3f(.05,.05,.05);
  b_orientation = Quaternion<float>();
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
 Vector3f c_posnow;//current position
 Vector3f c_mouse;//coords of the mouse
 Quaternion<float> c_orientation;
 bool isDirty,looky,lookx,move;
 float pitch, heading;//angle parameter for rotation matrices
 FPCamera(){
  c_mouse = Vector3f( 0 , 0 , 1 );
  c_posnow = Vector3f();
  c_orientation = Quaternion<float>().fromAxisRot( c_posnow , 0.0 );
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
  glPushMatrix();

  glMatrixMode( GL_PROJECTION );
  glLoadIdentity();
  gluPerspective( 65 , 1 , 0.001 , 100.0 );

  glTranslatef( 0 + c_mouse.x , 1 + c_mouse.y , 0 + c_mouse.z );
  glRotatef( pitch , 0 , 1 , 0 );
  glRotatef( heading , 1 , 0 , 0 );


  glPopMatrix();
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

};

