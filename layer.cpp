#include "layer.h"

Layer::Layer() { }

Layer::Layer(int size) {
	for (int i = 0; i < size; i++) {
		vector<Shape> shapes;
		layer[i] = shapes;
	}
	this->size = size;
}

void Layer::setSize(int size) {
	this->size = size;
	layer.clear();
	for (int i = 0; i < size; i++) {
		vector<Shape> shapes;
		layer[i] = shapes;
	}
}

void Layer::addShape(int index, Shape shape) {
	layer[index].push_back(shape);
}

void Layer::fill(int index, Color32 color) {
	for (int j = 0; j < layer[index].size(); j++) {
		layer[index][j].fill(color);
	}
}

void Layer::fillGradient(int index, Color32 color, int interval) {
	for (int j = 0; j < layer[index].size(); j++) {
		layer[index][j].fillGradient(color, interval);
	}
}