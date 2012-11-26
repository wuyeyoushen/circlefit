#include "CircleFitter.h"
#include <limits>

using namespace std;

CircleFitter::CircleFitter(void)
{
  //initialize the Circle Fitter object

}

CircleFitter::Circle CircleFitter::Run(const std::vector<Point2D> &input)
{
  //compute here the parameters of the circle that fits the input data the best





  //returns a fake invalid circle
  return Circle(numeric_limits<float>::quiet_NaN(),
    numeric_limits<float>::quiet_NaN(),
    numeric_limits<float>::quiet_NaN());
}


CircleFitter::~CircleFitter(void)
{
}

std::ostream& operator<< (std::ostream& stream, const CircleFitter::Circle& c)
{
  stream<<"center "<<c._centerX<<" , "<<c._centerY<<endl;
  stream<<"radius "<<c._radius<<endl;
  return stream;
}
