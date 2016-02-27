#ifndef SCANLINE_H
#define SCANLINE_H

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include "point.h"
#include "framebuffer.h"
#include "color32.h"

using namespace std;

typedef struct {
  Point plow; // plow adalah point dengan y minimum
  Point phigh; // plow adalah point dengan y maximum
  int dx;
  int dy;
  int sx;
  int sy;
  int err;
  int e2;
  Point curpoint;
} Line;

vector<Line> produceLines(vector<Point>, int &ymax, int &ymin);
int isIntersect(Line, int);
void sortTipot(vector<Point> &tipot);
void fill(vector<Line> &vl, int ymax, int ymin, Color32 color);

#endif
