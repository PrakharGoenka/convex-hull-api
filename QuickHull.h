#include <bits/stdc++.h>
#include "PointSet.h"
#include "Point.h"

using namespace std;

/*! A class to abstract an implementation of the Quickhull Algorithm
* for finding the convex hull of a given set of points
*/
class QuickHull {
  public:
  /*! Static method to compute the convex hull of the given set of points
  * using the Quickhull algorithm.
  * \param ps - A vector of Point objects. It stores the given list of points
  *  whose convex hull has to be computed
  * \return - A vector of Point objects. It stores the list of points
  *  on the computed convex hull.
  */
  static vector <Point> getConvexHull(PointSet ps) {
    Point l = ps.getLeftmostPoint();
    Point r = ps.getRightmostPoint();

    set <Point> hull;

    findHullPoints(ps, l, r, 1, hull);/*!< Find hull points above the line l-r*/
    findHullPoints(ps, l, r, -1, hull);/*!< Find hull points below the line l-r*/

    vector <Point> convex_hull;
    for(Point p : hull) {
      convex_hull.push_back(p);
    }

    return convex_hull;    
  }

  private:

  /*! Private static method to recursively find the farthest point for the 
  * Quickhull algorithm
  * \param ps - The instance of PointSet on which the computations have to done
  * \param p1 - The intance of the leftmost point of the point set ps
  * \param p2 - The intance of the rightmost point of the point set ps
  * \param side - Integer to specify which side of the line p1-p2 should be searched
  * (1 for above the line, and -1 for below it)
  * \param hull - A set of point objects to store the currently found hull points
  * \return - void 
  */
  static void findHullPoints(
    PointSet ps,
    Point p1,
    Point p2, 
    int side, 
    set <Point> &hull
  ) { 
    long long int maxDistPoint = -1; 
    double maxDist = 0; 
  
    for(long long int i = 0; i < ps.points.size(); i++) { 
      if(ps.orientation(p1, p2, ps.points[i]) == side) {
        double dist = ps.getPerpendicularDistance(p1, p2, ps.points[i]);
        
        if(dist > maxDist) {
          maxDistPoint = i;
          maxDist = dist;
        }
      }    
    } 
  
    if (maxDistPoint == -1) { 
      hull.insert(p1); 
      hull.insert(p2);
    } else {
      findHullPoints(
        ps,
        ps.points[maxDistPoint], 
        p1, 
        -ps.orientation(ps.points[maxDistPoint], p1, p2),
        hull
      ); 
      findHullPoints(
        ps,
        ps.points[maxDistPoint], 
        p2, 
        -ps.orientation(ps.points[maxDistPoint], p2, p1),
        hull
      ); 
    }
  } 
};
