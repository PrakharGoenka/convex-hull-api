#include <bits/stdc++.h>
#include "PointSet.h"
#include "Point.h"

using namespace std;

/*! A class to abstract an implementation of the Graham Scan Algorithm
* for finding the convex hull of a given set of points
*/
class GrahamScan {
  public:
  /*! Static method to compute the convex hull of the given set of points
  * using the Graham Scan algorithm.
  * \param ps - A vector of Point objects. It stores the given list of points
  *  whose convex hull has to be computed
  * \return - A vector of Point objects. It stores the list of points
  *  on the computed convex hull.
  */
  static vector <Point> getConvexHull(PointSet ps) {
    if(ps.number_of_points < 3) {
      return vector <Point> ();
    }

    Point reference = ps.getBottommostPoint();

    ps.removeCoincidentPoints(reference);
    ps.sortByAngle(reference, -1);
    
    if(ps.number_of_points < 2) {
      return vector <Point> ();
    }

    vector <Point> convex_hull;
    convex_hull.push_back(reference);
    convex_hull.push_back(ps.points[0]);
    convex_hull.push_back(ps.points[1]);

    for(long long int i = 2; i < ps.points.size(); i++) {
      while(convex_hull.size() > 1 and ps.orientation(
          convex_hull[convex_hull.size() - 2], convex_hull.back(), ps.points[i]
        ) >= 0
      ) {
        convex_hull.pop_back();
      }
      convex_hull.push_back(ps.points[i]);
    }

    return convex_hull;
  } 

};
