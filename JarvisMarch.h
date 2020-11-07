#include <bits/stdc++.h>
#include "PointSet.h"
#include "Point.h"

using namespace std;

/*! A class to abstract an implementation of the Jarvis March Algorithm
* for finding the convex hull of a given set of points
*/
class JarvisMarch {
  public:
  /*! Static method to compute the convex hull of the given set of points
  * using the Jarvis March algorithm.
  * \param ps - A vector of Point objects. It stores the given list of points
  *  whose convex hull has to be computed
  * \return - A vector of Point objects. It stores the list of points
  *  on the computed convex hull.
  */
  static vector <Point> getConvexHull(PointSet ps) {
    if(ps.number_of_points < 3) {
      return vector <Point> ();
    }

    vector <Point> convex_hull;

    Point leftmost_point = ps.getLeftmostPoint();

    Point hull_point = leftmost_point;
    do {
      convex_hull.push_back(hull_point);
      hull_point = ps.nearestPointByAngle(hull_point, -1);
    } while (leftmost_point.coordinates != hull_point.coordinates);

    return convex_hull;
  }
};
