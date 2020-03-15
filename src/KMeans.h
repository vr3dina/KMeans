#pragma once
#include <vector>
#include "Cluster.h"

class KMeans
{
private:
	int cluster_count;
	int max_iterations;
	std::vector<Cluster*> clusters;
	//cluster_ptr get_nearest_cluster(const Point& point);
	Cluster* get_nearest_cluster(const Point& point);
public:
	KMeans(int K, unsigned int iters = 10);
	std::vector<Cluster*> run(std::vector<Point>& points);
};
