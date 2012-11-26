#pragma once
#include<ostream>
#include<vector>
#include "Point2D.h"

class CircleFitter
{
public: 
  struct Circle
  {
    float _centerX,_centerY,_radius;
    Circle(float centerX, float centerY, float radius):
      _centerX(centerX),_centerY(centerY),_radius(radius)
      {}
    friend std::ostream& operator<< (std::ostream& stream, const Circle& c);
  };

protected:
  //add here member variables that can be shared by different calls to the Run function 

public:
  
  CircleFitter(void);//initialize the object 

  Circle Run(const std::vector<Point2D> &input);//returns the circle fitting the input sampled points
  
  ~CircleFitter(void);
};

