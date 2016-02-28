#ifndef SHAPE_H
#define SHAPE_H

#include <vector>
#include <algorithm>
#include "point.h"
#include "line.h"
#include "color32.h"
#include "framebuffer.h"

using namespace std;

class Shape {
  private:
  	vector<Point> vertices;
	vector<Line> lines;
	int ymax;
	int ymin;  
	Point centroid;
	Color32 color;
	int isIntersect(Line, int);
  public:
    Shape();
    Shape(vector<Point> vertices);
    void setVertices(vector<Point> vertices);
    void setColor(Color32 color);
    void fill();
    void transform(int dx, int dy, float scale, float rotation);
};

#endif