#pragma once

double EPSILON = 0.00001;

class Operations {
public:
	static bool Equal(double a, double b) {
		return abs(a - b) < EPSILON;
	}

};