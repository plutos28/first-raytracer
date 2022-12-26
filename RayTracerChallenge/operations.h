#pragma once

double EPSILON = 0.00001;

class Operations {
public: 
	static bool equal(double a, double b) {
		return abs(a) - abs(b) < EPSILON;
	}
};