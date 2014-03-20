#include "vmath.h"
#include <iostream>
#include <sys/time.h>
using namespace std;

/*
timeval t1, t2;
 double elapsedTime=0.0;
 //gettimeofday(&t1, NULL);
  //gettimeofday(&t2, NULL);

    // compute and print the elapsed time in millisec
  //elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
  //elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
  //cout << elapsedTime << " ms.\n";
*/

int main(){
 timeval t1 , t2;
 double elapsedTime = 0.0;
 gettimeofday( &t1 , NULL );
 cout<< ( Vector3f( 1 , 2 , 3 ) - Vector3f( 1 , 1 , 1 ) ).toString() << endl;
 cout<< Quaternion<float>( 1.1 , 1.1 , 1.1 , 1.1 ).toString();

 gettimeofday( &t2 , NULL );

 //compute and print the elapsed time in millisec
 //elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
 elapsedTime += ( t2.tv_usec - t1.tv_usec ) / 1000.0;   // us to ms
 cout << elapsedTime << " ms. \n";

 return 0;
}
