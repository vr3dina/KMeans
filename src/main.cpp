#include "KMeans.h"
#include "vector_os.h"

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<Point> read_data(const string& file_path)
{
	vector<Point> points;
	ifstream fin(file_path);
	while (!fin.eof())
	{
		string name;
		double v1, v2;
		fin >> name >> v1 >> v2;
		points.push_back({ name, {v1, v2} });
	}
	return points;
}

//#define LOG_ITER //comment this to show results only!

int main()
{
	int k;
	cout << "Enter cluster clount: ";
	cin >> k;
	KMeans k_means(k);

	string file_path = "res/data.txt";
	//string file_path = "res/Text.txt";
	vector<Point> points = read_data(file_path);
	cout << "Input data:" << points << endl << endl;
	auto res = k_means.run(points);
	cout << res << endl;

	return 0;
}
