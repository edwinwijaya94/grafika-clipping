#include <iostream>
#include <stdlib.h>
using namespace std;

//Constant
#define NIL 0
#define LEFT 1
#define RIGHT 2
#define BOTTOM 4
#define TOP 8
#define windowHeight 600
#define windowWidth 800

//Find Region of x and y 
int findRegion(int x, int y){
  int code = NIL;
  if(y >= windowHeight)
  	code |= TOP;
  else if(y < 0)
  	code |= BOTTOM;
  if(x >= windowWidth)
  	code |= RIGHT;
  else if (x < 0)
  	code |= LEFT;
  
  return code;
}

bool clipLine(int x1, int y1, int x2, int y2, int &x3, int &y3, int &x4, int &y4){
  int code1, code2, codeout;
  bool accept = 0, done=0;
  code1 = findRegion(x1, y1); //the region outcodes for the endpoints
  code2 = findRegion(x2, y2);

  //Starting algorithm ...
  do{
    cout << "Code 1 : " << code1 << endl;
    cout << "Code 2 : " << code2 << endl;
    if(!(code1 | code2)){
    	//Trivial Accept, accept because both endpoints are in screen or on the border
    	cout << "Trivial Accept" << endl;
    	accept = done = 1;
    } 
    else if(code1 & code2){
	    //Trivial Reject, the line isn't visible on screen 
    	cout << "Trivial Rejection" << endl;
    	done = 1;
    }
    else{
      cout <<  "Others" << endl;
      int x, y;
      codeout = code1 ? code1 : code2;
      cout << "Code out : " << codeout << endl;

      if(codeout & 8){
   		cout << "TOP" << endl;
        x = x1 + (x2 - x1) * (windowHeight - y1) / (y2 - y1);
        y = windowHeight - 1;
      }
      else if(codeout & 4){
      	cout << "BOTTOM" << endl;
        x = x1 + (x2 - x1) * -y1 / (y2 - y1);
        y = 0;
      }
      else if(codeout & 2){
      	cout << "RIGHT" << endl;
        y = y1 + (y2 - y1) * (windowWidth - x1) / (x2 - x1);
        x = windowWidth - 1;
      }
      else{
      	cout << "LEFT" << endl;
        y = y1 + (y2 - y1) * -x1 / (x2 - x1);
        x = 0;
		int x1d = 400,y1d = 700,x2d = 900,y2d = 200;

      }

      if(codeout == code1){
      	cout << "First Endpoint was clipped" << endl;
        x1 = x; y1 = y;
        cout << "X1 : "<< x1 << "y1 : " << y1 << endl;
        code1 = findRegion(x1, y1);
        cout << "Code1 : " << code1 << endl;

      }
      else{
      	cout << "Second endpoint was clipped";
        x2 = x; y2 = y;
        cout << "X2 : "<< x2 << "y2 : " << y2 << endl;
        code2 = findRegion(x2, y2);
        cout << "Code2 : " << code1 << endl;
      }
    }

    cout << endl;
  }
  while(done == 0);

  if(accept)
  {
    x3 = x1;
    x4 = x2;
    y3 = y1;
    y4 = y2;
    return 1;
  }
  else
  {
    x3 = x4 = y3 = y4 = 0;
    return 0;
  }
}

int main()
{
	//PR : Klo Point core dumped
	int x3,x4,y3,y4;
	int x1a =200,y1a = 500,x2a = 700,y2a = 200;
	int x1b = -100,y1b = 200,x2b = 400,y2b = 500;
	int x1c = 400,y1c = 700,x2c = 900,y2c = 700;
	int x1d = 400,y1d = 700,x2d = 900,y2d = 200;

	cout << clipLine(x1d,y1d,x2d,y2d,x3,y3,x4,y4);

	return 0;
}