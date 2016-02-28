#include "shape.h"

Shape::Shape() { }

Shape::Shape(vector<Point> vertices) {
	setVertices(vertices);
	color = WHITE;
}

void Shape::setVertices(vector<Point> vertices) {
	this->vertices = vertices;
	ymin = 2000;
	ymax = -1;
	int xmax = -1;
	int xmin = 2000;
	for (int i = 0; i < vertices.size(); i++) {
		if (vertices[i].y > vertices[(i+1)%vertices.size()].y) {
		  Line line;
		  line.phigh.y = vertices[i].y;
		  line.phigh.x = vertices[i].x;
		  line.plow.y = vertices[(i+1)%vertices.size()].y;
		  line.plow.x = vertices[(i+1)%vertices.size()].x;
		  lines.push_back(line);
		}
		else if (vertices[i].y < vertices[(i+1)%vertices.size()].y) {
		  Line line;
		  line.plow.y = vertices[i].y;
		  line.plow.x = vertices[i].x;
		  line.phigh.y = vertices[(i+1)%vertices.size()].y;
		  line.phigh.x = vertices[(i+1)%vertices.size()].x;
		  lines.push_back(line);
		}
		if (vertices[i].y > ymax) 
		  ymax = vertices[i].y;
		if (vertices[i].y < ymin)
		  ymin = vertices[i].y;
		if (vertices[i].x > xmax) 
		  xmax = vertices[i].x;
		if (vertices[i].x < xmin)
		  xmin = vertices[i].x;
	}
	centroid = Point((xmax+xmin)/2, (ymax+ymin)/2);
}

void Shape::setColor(Color32 color) {
	this->color = color;
}

int Shape::isIntersect(Line line, int y) {
	if (y == line.plow.y) {
		return 2;
	}
	else if (((y > line.plow.y) && (y < line.phigh.y)) || (y == line.phigh.y)) {
		return 1;
	}
	else 
		return 0;
}

void Shape::fill() {
  vector<Point> tipot;
  for (int y = ymin; y <= ymax; y++) {
  	tipot.clear();
    for (int j = 0; j < lines.size(); j++) {
      if (isIntersect(lines[j], y) == 2) {
      	lines[j].dx = abs(lines[j].phigh.x-lines[j].plow.x);
      	lines[j].dy = abs(lines[j].phigh.y-lines[j].plow.y);
      	lines[j].sx = lines[j].plow.x < lines[j].phigh.x ? 1 : -1;
      	lines[j].sy = lines[j].plow.y < lines[j].phigh.y ? 1 : -1;
      	lines[j].err = (lines[j].dx > lines[j].dy ? lines[j].dx : -1 * lines[j].dy)/2;
      	lines[j].curpoint = lines[j].plow;

      	tipot.push_back(lines[j].plow);
      }
      else if (isIntersect(lines[j], y) == 1) {
      	lines[j].e2 = lines[j].err;
      	if (lines[j].e2 > -1*lines[j].dx) { lines[j].err -= lines[j].dy; lines[j].curpoint.x += lines[j].sx; }
      	//if (lines[j].e2 < lines[j].dy) { lines[j].err += lines[j].dx; lines[j].curpoint.y += lines[j].sy; }
      	if (lines[j].e2 < lines[j].dy) { lines[j].err += lines[j].dx; lines[j].curpoint.y = y; }

      	tipot.push_back(lines[j].curpoint);
      }
    }
    sort(tipot.begin(), tipot.end());
    for (int i = 0; i < tipot.size()-1; i += 2) {
    	for (int x = tipot[i].x; x < tipot[i+1].x; x++) {
    		SetPixel(x, y, color);
    	}
    }
  }
}

void Shape::transform(int dx, int dy, float scale, float rotation) {
	float PI = 3.14159265;
    float rad = rotation * PI / 180.0f;
    centroid.x += dx;
    centroid.y += dy;
	for (int i = 0; i < vertices.size(); i++) {
		Point Pnew;
	   
	   //translate
	    Pnew.x = vertices[i].x + dx;
	    Pnew.y = vertices[i].y + dy;
	   
	    //scale
	    Pnew.x = centroid.x +(int)(double(Pnew.x - centroid.x) * scale);
	    Pnew.y = centroid.y +(int)(double(Pnew.y - centroid.y) * scale);

	    //rotate
	    int tx2 = Pnew.x - centroid.x, ty2 = Pnew.y - centroid.y;
	    Pnew.x = centroid.x + (int)((double)tx2 * cos(rad) - (double)ty2 * sin(rad));
	    Pnew.y = centroid.y + (int)((double)tx2 * sin(rad) + (double)ty2 * cos(rad));
	    vertices[i].x = Pnew.x;
	    vertices[i].y = Pnew.y;
	}
	lines.clear();
	setVertices(vertices);
	fill();
}