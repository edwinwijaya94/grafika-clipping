#ifndef LAYER_H
#define LAYER_H

#include <map>
#include <vector>
#include "shape.h"

using namespace std;

class Layer {
  private:
  	map<int, vector<Shape> > layer;
  	int size;
  public:
  	Layer();
  	Layer(int size);
  	void setSize(int size);
  	void addShape(int index, Shape shape);
  	void fill(int index, Color32 color);
  	void fillGradient(int index, Color32 color, int interval);
};

#endif