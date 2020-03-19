#pragma once
#include "Cluster.h"
#include <vector>

class KMeans
{
private:
	size_t cluster_count;
	unsigned int max_iterations;
	std::vector<Cluster> clusters;
	Cluster* get_nearest_cluster(const Point& point);
public:
	KMeans(int K, unsigned int iters = 10);
	std::vector<Cluster> run(std::vector<Point>& points);
};
