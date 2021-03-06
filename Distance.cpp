// 1. f(N) = Euclidean Distance from N to goal
//    length of straight line between 2 options
//    E((i,j),(i',j')) = sqrt[(i-i')^2+(j-j')^2]

#include <vector>
#include <stdlib.h> //abs
#include <math.h>   //sqrt

using namespace std;

class Point {
public:
  int x;
  int y;
  int cost;
  Point* parent;
  Point() {
    this->x = 0;
    this->y = 0;
    this->cost = 0;
    this->parent = NULL;
  }
  Point(int _x, int _y, int _cost, Point *_parent) {
    this->x = _x;
    this->y = _y;
    this->cost = _cost;
    this->parent = _parent;
  }
};

class Distance {
  int mode;
  Point goal;

  double euclidean(Point current, bool addCost) const;
  double manhattan(Point current, bool addCost) const;

public:
  Distance(Point inputGoal, int inputMode);
  ~Distance();

  bool operator() (const Point& lhs, const Point& rhs) const
  {
    // depending on mode, evaluate lhs and rhs
    // if lhs is closer to the goal
    //   return true
    // else
    //   return false
    double lhsDistance;
    double rhsDistance;
    switch (mode) {
      case 0:
        // euclidean only
        lhsDistance = this->euclidean(lhs, false);
        rhsDistance = this->euclidean(rhs, false);
        return (lhsDistance>rhsDistance);
      case 1:
        // manhattan only
        lhsDistance = this->manhattan(lhs, false);
        rhsDistance = this->manhattan(rhs, false);
        return (lhsDistance>rhsDistance);
      case 2:
        // euclidean + Cost
        lhsDistance = this->euclidean(lhs, true);
        rhsDistance = this->euclidean(rhs, true);
        return (lhsDistance>rhsDistance);
      case 3:
        // manhattan + Cost
        lhsDistance = this->manhattan(lhs, true);
        rhsDistance = this->manhattan(rhs, true);
        return (lhsDistance>rhsDistance);
      default:
        return true;
    }
  }
};

Distance::Distance(Point inputGoal, int inputMode) {
  this->goal = inputGoal;
  this->mode = inputMode;
}

Distance::~Distance() {
}

double Distance::manhattan(Point current, bool addCost) const {
  int exes = abs(this->goal.x-current.x);
  int whys = abs(this->goal.y-current.y);
  double output = (double) (exes+whys);
  if (addCost) {
    output += ((double) current.cost);
  }
  return (double) output;
}

double Distance::euclidean(Point current, bool addCost) const {
  double exes = (double) abs(this->goal.x-current.x);
  double whys = (double) abs(this->goal.y-current.y);
  double output = sqrt (pow(exes,2) + pow(whys,2));
  if (addCost) {
    output += ((double) current.cost);
  }
  return output;
}
