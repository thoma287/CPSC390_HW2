// 1. f(N) = Euclidean Distance from N to goal
//    length of straight line between 2 options
//    E((i,j),(i',j')) = sqrt[(i-i')^2+(j-j')^2]

#include <vector>
#include <stdlib.h> //abs
#include <math.h>   //sqrt

using namespace std;

struct Point {
  int x;
  int y;
  int cost;
  Point() {
    x = 0;
    y = 0;
    cost = 0;
  }
  Point(int _x, int _y, int _cost) {
    x = _x;
    y = _y;
    cost = _cost;
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
        cerr << "LHS DIST: " << lhsDistance << " LHS COOD: (" << lhs.x << "," << lhs.y << ")" << endl;
        rhsDistance = this->euclidean(rhs, false);
        cerr << "RHS DIST: " << rhsDistance << " RHS COOD: (" << rhs.x << "," << rhs.y << ")" << endl;
        return (lhsDistance<rhsDistance);
      case 1:
        // manhattan only
        lhsDistance = this->manhattan(lhs, false);
        rhsDistance = this->manhattan(rhs, false);
        return (lhsDistance<rhsDistance);
      case 2:
        // euclidean + Cost
        lhsDistance = this->euclidean(lhs, true);
        rhsDistance = this->euclidean(rhs, true);
        return (lhsDistance<rhsDistance);
      case 3:
        // manhattan + Cost
        lhsDistance = this->manhattan(lhs, true);
        rhsDistance = this->manhattan(rhs, true);
        return (lhsDistance<rhsDistance);
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
  int output = exes+whys;
  if (addCost) {
    output += current.cost;
  }
  return (double) output;
}

double Distance::euclidean(Point current, bool addCost) const {
  double exes = (double) abs(this->goal.x-current.x);
  double whys = (double) abs(this->goal.y-current.y);
  double output = sqrt (pow(exes,2) + pow(whys,2));
  if (addCost) {
    output += (double) current.cost;
  }
  return output;
}
