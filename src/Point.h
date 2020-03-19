#pragma once
#include <vector>
#include <string>

class Cluster;

class Point
{
public:
	Point(const std::string& name, const std::vector<double> v);

	std::vector<double> values;
	std::string name;
	Cluster* cluster;

	Point& operator=(const Point& other);
	bool operator==(const Point& other);
	friend std::ostream& operator << (std::ostream& out, const Point& cluster);
};

