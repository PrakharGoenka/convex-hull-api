#include<stdio.h>
#include<iostream>
#include<vector>
#include"grahmscan.h"
#include"jarvismarch.h"
#include"quickhull.h"
#include"util.h"

using namespace std;

vector<pair<int,int>> getPoints()
{
    vector<pair<int,int>> points;
    int n;
    cout<<"\nEnter number of points\n";
    cin>>n;
    cout<<"Enter the points\n";
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        points.push_back(make_pair(x,y));
    }
    return points;
}

int main()
{
    cout<<"==============CONVEX HULL ALGORITHMS==============\n";
    SELECT_ALGORITHM:
    cout<<"\nSelect one of the following algorithms\n";
    cout<<"1. Grahm's Scan\n";
    cout<<"2. Jarvis March\n";
    cout<<"3. Quick Hull\n";
    cout<<"4. Exit\n";
    int option;
    cin>>option;
    vector<pair<int,int>> points = getPoints();
    switch (option)
    {
    case 1:
        grahmScan(points);
        break;
    case 2:
        jarvisMarch(points);
        break;
    case 3:
        // quickHull(points);
        break;
    case 4:
        exit(0);
        break;
    default:
        cout<<"\nInvalid input. Please try again.\n";
        goto SELECT_ALGORITHM;
        break;
    }
    
    return 0;
}