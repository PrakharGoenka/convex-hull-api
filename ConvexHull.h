#include <bits/stdc++.h>
#include "GrahamScan.h"
#include "JarvisMarch.h"
#include "QuickHull.h"
#include "PointSet.h"

using namespace std;

/*! \brief The ConvexHull API. Offers three implementation:
* 1. Graham Scan
* 2. Jarvis March
* 3. Quickhull
*
* A class based API. It has static methods to compute convex hull 
* corresponding to each of the offered implementations.
*/
class ConvexHull {
  public:

  /*! Static method to compute the convex hull of the given set of points
  * using Graham Scan algorithm.
  * \param point_set - A vector of pairs of doubles. It stores the coordinates
  * of the given points as an ordered pair
  * \return - A vector of pairs of doubles. It stores the coordinates
  * of the points on the computed convex hull, as an ordered pair.  * 
  */
  static vector <pair <double, double>> computeByGrahamScan (
    vector <pair <double, double>> point_set
  ) {
    vector <Point> hull_points = GrahamScan::getConvexHull(PointSet (point_set));
    return getPointCoordinates(hull_points);
  }

  /*! Static method to compute the convex hull of the given set of points
  * using Jarvis March algorithm.
  * \param point_set - A vector of pairs of doubles. It stores the coordinates
  * of the given points as an ordered pair
  * \return - A vector of pairs of doubles. It stores the coordinates
  * of the points on the computed convex hull, as an ordered pair.
  */
  static vector <pair <double, double>> computeByJarvisMarch (
    vector <pair <double, double>> point_set
  ) {
    vector <Point> hull_points = JarvisMarch::getConvexHull(PointSet (point_set));
    return getPointCoordinates(hull_points);
  }
  
  /*! Static method to compute the convex hull of the given set of points
  * using Quickhull algorithm.
  * \param point_set - A vector of pairs of doubles. It stores the coordinates
  * of the given points as an ordered pair
  * \return - A vector of pairs of doubles. It stores the coordinates
  * of the points on the computed convex hull, as an ordered pair.
  */
  static vector <pair <double, double>> computeByQuickHull (
    vector <pair <double, double>> point_set
  ) {
    vector <Point> hull_points = QuickHull::getConvexHull(PointSet (point_set));
    return getPointCoordinates(hull_points);
  }  

  private:

  /*! Private static method to extract the coordinates of points.
  * \param points - A vector of Point objects. It stores the points on the
  * computed convex hull.
  * \return - A vector of pairs of doubles. It stores the coordinates
  * of the points on the computed convex hull, as an ordered pair. 
  */
  static vector <pair <double, double>> getPointCoordinates(vector <Point> points) {
    vector <pair <double, double>> point_coordinates;
    for(Point p : points) {
      point_coordinates.push_back(p.coordinates);
    }
    return point_coordinates;
  }  
};
