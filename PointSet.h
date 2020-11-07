#ifndef POINTSET_H
#define POINTSET_H

#include <bits/stdc++.h>
#include "./Point.h"

using namespace std;

/*! Class to abstract a list of Point objects. 
*/
class PointSet {
  public:

  long long int number_of_points; /*!< Stores the number of point objects*/
  vector <Point> points; /*!< List of Point objects present in the pointset*/

  /*! Constructor for the PointSet class.
  * \param ps - Vector of pairs of doubles. Stores the list of coordinates 
  * of the points present in the point set.
  */
  PointSet(vector <pair <double, double>> ps) {
    number_of_points = ps.size();
    for(auto c : ps) {
      points.push_back(Point (c));
    }
  }

  /*! Method to return the vector area of triangle specified by the given points.
  * \param a - Point instance of the first point.
  * \param b - Point instance of the second point.
  * \param c - Point instance of the third point.
  * \return - Vector area of the triangle abc in double precisson
  */
  double triangleArea(Point a, Point b, Point c) {
    double area = (
      a.coordinates.first * (b.coordinates.second - c.coordinates.second)
      + b.coordinates.first * (c.coordinates.second - a.coordinates.second)
      + c.coordinates.first * (a.coordinates.second - b.coordinates.second)
    ) / 2;
      
    return area;
  }

  /*! Method to return the orientation of the given ordered triple of points.
  * Uses the sign of the vector area of the triangle formed by these points to
  * find the orientation.
  * \param a - Point instance of the first point.
  * \param b - Point instance of the second point.
  * \param c - Point instance of the third point.
  * \return - Relative orientation of the ordered points a, b, c
  * (1 for ACW, and -1 for CW)
  */
  int orientation(Point a, Point b, Point c) {
    double area = triangleArea(a, b, c);
    if(area > 0) {
      return 1;
    } else if(area < 0) {
      return -1;
    } else {
      return 0;
    }
  }

  /*! \brief Method to return the Point that is nearest in angle to the given point p
  * in the point set ps, in given direction (-1 for CW, 1 for ACW) 
  * Finds a point that has distinct coordinates wrt the given point,
  * assumes it to be the nearest, then iterates over the points and updates
  * the nearest point if orientation of the new point is in the given direction
  * wrt to current nearest.
  * \param point - Instance of the point to be taken as reference.
  * \param direction - Integer denoting the direction in which to find the
  * nearest point (1 for ACW, -1 for CW)
  * \return - Point instance of the point nearest to the given point
  */
  Point nearestPointByAngle(Point point, int direction) {
    for(auto p : points) {
      if(p.coordinates != point.coordinates) {
        Point nearest = p;
        for(auto q : points) {
          if(orientation(nearest, q, point) == direction) {
            nearest = q;
          }
        }
        return nearest;
      }
    }
    return point;
  }

  /*! Method to return the Euclidean distance between the two given points.
  * \param a - First Point instance.
  * \param b - Second Point instance.
  * * \return - Distance as a double precission decimal.
  */
  double getEuclideanDistance(Point a, Point b) {
    double distance = sqrt(
      pow(a.coordinates.first - b.coordinates.first, 2)
      + pow(a.coordinates.second - b.coordinates.second, 2)
    );
    return distance;
  }

  /*! Method to return the perpendicular distance of a point 'A' from the 
  * line segment 'BC'
  * \param a - Point instance whose distance has to be calculated.
  * \param b - Point instance corresponding to one endpoint of the base line.
  * \param c - Point instance corresponding to  endpoint of the base line.
  * \return - Distance as a double precission decimal.
  */
  double getPerpendicularDistance(Point a, Point b, Point c) {
    return abs((
        (b.coordinates.second - a.coordinates.second)
        *(c.coordinates.first - b.coordinates.first) 
      )
      - (
        (b.coordinates.first - a.coordinates.first)
        *(c.coordinates.second - b.coordinates.second)
      )
    );
  }

  /*! Method to return the leftmost point in the point set.
  * If there are multiple such points, it returns the topmost. 
  * Takes the first point as first guess, then constantly improves the guess.
  * \return - Point instance of the leftmost point of the point set.
  */
  Point getLeftmostPoint() {
    Point leftmost = points[0];

    for(auto p : points) {
      if(
        p.coordinates.first < leftmost.coordinates.first
        or (
          p.coordinates.first == leftmost.coordinates.first
          and p.coordinates.second > leftmost.coordinates.second
        )
      ) {
        leftmost = p;
      } 
    }

    return leftmost;
  }

  /*! Method to return the rightmost point in the point set.
  * If there are multiple such points, it returns the topmost.
  * Takes the first point as first guess, then constantly improves the guess.
  * \return - Point instance of the rightmost point of the point set.
  */
  Point getRightmostPoint() {
    Point rightmost = points[0];

    for(auto p : points) {
      if(
        p.coordinates.first > rightmost.coordinates.first
        or (
          p.coordinates.first == rightmost.coordinates.first
          and p.coordinates.second > rightmost.coordinates.second
        )
      ) {
        rightmost = p;
      } 
    }

    return rightmost;
  }

  /*! Method to return the bottommost point in the point set. If there are multiple
  * such points, it returns the leftmost. Takes the first point as first guess,
  * then constantly improves the guess.
  * \return - Point instance of the bottommost point of the point set.
  */
  Point getBottommostPoint() {
    Point bottommost = points[0];

    for(auto p : points) {
      if(
        p.coordinates.second < bottommost.coordinates.second
        or (
          p.coordinates.second == bottommost.coordinates.second
          and p.coordinates.first < bottommost.coordinates.first
        )
      ) {
        bottommost = p;
      } 
    }

    return bottommost;
  }

  /*! Method to return an interior / non-extreme point of the convex point set.
  * Such a point can not belong to the convex hull of the point set.
  * Finds three non collinear points from the set, and returns their centroid.
  * \return - Point instance of an interior point (not necessarily on the set)
  */
  Point getInteriorPoint() {
    Point first = points[0];
    for(auto p : points) {
      if(first.coordinates != p.coordinates) {
        Point second = p;
        for(auto q : points) {
          if(orientation(first, second, q) != 0) {
            Point third = q;
            double x = (
              first.coordinates.first
              + second.coordinates.first 
              + third.coordinates.first
            ) / 3;

            double y = (
              first.coordinates.second
              + second.coordinates.second 
              + third.coordinates.second
            ) / 3;
            return Point (make_pair(x, y));
          }
        }
      }
    }
    return points[0];
  }

  /*! Custom comparator function for sorting instances of points wrt to the 
  * line reference - origin, in the given direction.
  * \param a - The first point instance
  * \param b - The second point instance
  * \param reference - The point instance to be taken as reference
  * \param direction - Integer to specify the direction in which to sort
  * (-1 for CW, 1 for ACW)
  * \return - true if a and b are in the correct order, and false otherwise
  */
  bool comparator(Point a, Point b, Point pivot_point, int direction) {
    int relative_orientation = orientation(pivot_point, a, b);
    if(relative_orientation == 0)
        return ((getEuclideanDistance(pivot_point,b) >= getEuclideanDistance(pivot_point,a))? true : false); 
    return ((relative_orientation==-1)?true:false);
  }

  /*! Method to sort the point set according to the angle that the points make
  * with the line reference - origin, in the given direction (-1 for CW, 1 for ACW)
  * \param pivot_point - The point instance to be taken as reference
  * \param direction - Integer to specify the direction in which to sort
  * (-1 for CW, 1 for ACW)
  */
  void sortByAngle(Point pivot_point, int direction) {
    sort(points.begin(), points.end(), 
      [this, pivot_point, direction](Point a, Point b) {
        return comparator(a, b, pivot_point, direction);
      }
    );
  }

  /*! Method to remove points coincident with the given origin.
  * \param origin - The point instance to be taken as origin
  */
  void removeCoincidentPoints(Point origin) {
    vector <Point> points_updated;
    for(long long int i = 0; i < number_of_points; i++) {
      if(points[i].coordinates != origin.coordinates) {
        points_updated.push_back(points[i]);
      }
    }
    points = points_updated;
  }
};

#endif /*POINTSET_H*/