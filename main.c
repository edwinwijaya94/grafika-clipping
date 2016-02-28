#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "framebuffer.h"
#include "image.h"
#include "bitmap.h"
#include "input.h"
#include "point.h"
#include "polygon.h"
//#include "scanline.h"	
#include "shape.h"
#include "file.h"
#include "layer.h"
#include "matrix.h"

#include <iostream>
#include <vector>

using namespace std;

//screen size
long int width, height;

int ClampInt(int x, int min, int max){
	return x > max ? max : (x < min ? min : x);
}

int main(){	
	//Image windowImage = LoadBitmapAsImage("images/window.bmp");
	//Image mapImage = LoadBitmapAsImage("images/map.bmp");
	// string shape;
	// cin >> shape;
	
	InitFramebuffer(&width, &height);
	//set_conio_terminal_mode();

	vector<string> filenames;
    filenames.push_back("points.txt");

	map<string, vector<Point> > points = getPointsFromFile(filenames);
	printf("points size: %d\n",points.size());
	// for(map<string, vector<Point>>::iterator it=points.begin(); it!=points.end(); it++){
	// 	cout<<"it:"<<it->first<<endl;
	// }
	//cout<<points["pesawat"]P[0]<<endl;
	
	//test polygon
	ClearScreen();
	vector<Point> Ptriangle = points["triangle"];
	vector<Point> Psquare = points["square"];
	//printf("Pol size: %d\n",Pol.size());

	//int ymax_global, ymin_global;
	//vector<Line> lines = produceLines(Pol, ymax_global, ymin_global);
	//fill(lines, ymax_global, ymin_global, (Color32){255,255,255,255});
	//printf("a\n");

	//vector<Point> Pol = {Point{200,300},Point{300,300},Point{300,500}};
	
	// drawPolygon(Pol, 1.5, 45, (Color32){255,0,0,255});
	// //drawPolygon(Pol, (Color32){255,0,0,255});
	// Pol = {Point{450,300},Point{550,300},Point{550,500}};
	// drawPolygon(Pol, 1.5, 90, (Color32){255,0,0,255});

	initMatrix();

	// Shape shape(Ptriangle);
	// shape.fill();
	// shape.transform(200, -100, 1.5, 45.0);	
	// shape.transform(350, 200, 0.5, 90.0);

	Shape shape2(Psquare);
	Shape shape3(Psquare);
	shape3.transform(100, -100, 1.0, 0.0);

	vector<Point> Pol = {Point{400,200},Point{600,200},Point{500,300},Point{300,300}};
	Shape shape4(Pol);
	vector<Point> Pol2 = {Point{500,300},Point{600,200},Point{600,400},Point{500,500}};
	Shape shape5(Pol2);

	// shape2.fill();
	// shape2.transform(300, -200, 1.0, 45.0);	
	// shape2.transform(300, 300, 1.0, 45.0);

	Layer layer(3);
	layer.addShape(0, shape2);
	layer.addShape(2, shape3);
	//layer.addShape(1, shape4);
	//layer.addShape(1, shape5);
	shape4.fillGradient(RED, 1);
	shape5.fill((Color32){100, 0, 0, 255});
	layer.fillGradient(0, RED, 1);

	SwapBuffers();
	printf("a\n");
	// usleep(2000000);
	
	/*float scrollRate = 6;
	float minScale = 1;
	float maxScale = 2;
	float scale = minScale;
	int winW = 800/2;
	int winH = 600/2;
	
	while(1){
		ClearScreen();
		DrawImage(width/2, height/2, &mapImage, scale, 0);
		DrawImage(width/2, height/2, &windowImage, 1, 0);
		SwapBuffers();
		char c = getch();
		if(c == 'w'){ //scroll up
			mapImage.pivot.y -= (int)(scrollRate/scale); 
		} 
		else if(c == 's'){ //scroll down
			mapImage.pivot.y += (int)(scrollRate/scale); 
		}
		else if(c == 'a'){ //scroll left
			mapImage.pivot.x -= (int)(scrollRate/scale);
		}
		else if(c == 'd'){ //scroll right
			mapImage.pivot.x += (int)(scrollRate/scale);
		}
		else if(c == 'g'){ //zoom in
			scale += 0.1;
		}
		else if(c == 'h'){ //zoom out
			scale -= 0.1;
		}
		else if(c == 'x'){
			break;
		}
		scale = scale > maxScale ? maxScale : (scale < minScale ? minScale : scale);
		
		int scaledWinW = (int)((float)winW/scale);
		int scaledWinH = (int)((float)winH/scale);
		mapImage.pivot.x = ClampInt(mapImage.pivot.x, scaledWinW, mapImage.w - scaledWinW);
		mapImage.pivot.y = ClampInt(mapImage.pivot.y, scaledWinH, mapImage.h - scaledWinH);

	}
	FreeImage(&mapImage);
	FreeImage(&windowImage);*/
	
	return 0;
}

