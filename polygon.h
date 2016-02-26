#ifndef POLYGON_H
#define POLYGON_H

#include <iostream>
#include <vector>
#include "point.h"
#include "framebuffer.h"
#include "color32.h"

using namespace std;

Point getPivot(vector<Point> vertices);
Point transformPoint(Point P, Point centroid, float scale, float rotation);

void drawPolygon(vector<Point>);
void drawPolygon(vector<Point> Pol, float scale, float rotation );
#endif
