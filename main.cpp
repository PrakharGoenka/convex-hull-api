#include <bits/stdc++.h>
#include "ConvexHull.h"

using namespace std;
using namespace std::chrono;

vector<vector <pair <double, double>>> getInputFromFile()
{
  vector<vector <pair <double, double>>> testCases;
  vector <pair <double, double>> points;
  ifstream ifile("input.txt", std::ios::in);

  //check to see that the file was opened correctly:
  if (!ifile.is_open()) {
      std::cerr << "There was a problem opening the input file!\n";
      exit(1);
  }

  //Read data from file
  int n;
  while(ifile>>n)
  {
    double x = 0.0, y = 0.0;
    while (n--) {
      ifile>>x;
      ifile>>y;
      points.push_back(make_pair(x,y));
    }
    testCases.push_back(points);
    points.clear();
  }
  return testCases;
}

void printHull(vector <pair <double, double>> hull)
{
  for(int i=0;i<hull.size();i++)
    cout<<"\n"<<hull[i].first<<" "<<hull[i].second;
}

int main() {
  vector<vector <pair <double, double>>> testCases;
  testCases = getInputFromFile();
  
  for(int i=0;i<testCases.size();i++)
  {
    cout<<"\n\n\nTest "<<i+1<<"\nNumber of points : "<<testCases[i].size(); 
    vector <pair <double, double>> points = testCases[i];
    vector <pair <double, double>> hull;
    clock_t start,end;
    double time_taken;

    start = clock();
    hull = ConvexHull::computeByGrahamScan(points);
    end = clock();
    time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout<<"\n\n Grahm's Scan Algorithm";
    cout<<"\n Execution Time in seconds: "<<fixed<<setprecision(3)<<time_taken;
    printHull(hull);
    hull.clear();

    start = clock();
    hull = ConvexHull::computeByJarvisMarch(points);
    end = clock();
    time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout<<"\n\n Jarvis March Algorithm";
    cout<<"\n Execution Time in seconds: "<<fixed<<setprecision(3)<<time_taken;
    printHull(hull);
    hull.clear();

    start = clock();
    hull = ConvexHull::computeByQuickHull(points);
    end = clock();
    time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout<<"\n\n QuickHull Algorithm (not ordered)";
    cout<<"\n Execution Time in seconds: "<<fixed<<setprecision(3)<<time_taken;
    printHull(hull);
    cout<<"\n\n Number of hull points : "<<hull.size();
    hull.clear();
    points.clear();
  }
  return 0;
}