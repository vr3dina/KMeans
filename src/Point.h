#pragma once
#include <vector>
#include <string>
#include <memory>

class Cluster;

class Point
{
public:
	Point();
	Point(const std::string& name, const std::vector<double> v);

	std::vector<double> values;
	std::string name;
	//int cluster_id = -1;
	//std::shared_ptr<Cluster> cluster;
	Cluster* cluster;

	Point& operator=(const Point& other);
	bool operator==(const Point& other);
	friend std::ostream& operator << (std::ostream& out, const Point& cluster);
};

