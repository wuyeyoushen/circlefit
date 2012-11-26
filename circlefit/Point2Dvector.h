#pragma once
#include "Point2D.h"
#include <vector>

//represents a vector of Point2D that can be loaded from the matlab output file
class Point2Dvector: 
  public std::vector<Point2D>
{
public:
  Point2Dvector(const std::string &filename);
  ~Point2Dvector(void);
};

