#pragma once
#include "Point.h"

#include <string>
#include <vector>
//#include <memory>

//using cluster_ptr = std::shared_ptr<Cluster>;

class Cluster
{
private:
	std::vector<Point> points;
	Point central_point;

public:
	//Cluster();
	Cluster(Point& p);

	void set_central_point(Point& p);
	void add_point(Point& point);
	void remove_point(Point& point);
	Point get_central_point() const;
	size_t get_total_points() const;
	const std::vector<Point>& get_points() const;

	Cluster& operator=(const Cluster&);
	//Cluster& operator=(Cluster&&);

	friend std::ostream& operator << (std::ostream& out, const Cluster& cluster);
};
