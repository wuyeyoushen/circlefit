#include <iostream>
#include "Point2Dvector.h"
#include "CircleFitter.h"
#include "../libs/clapack.h"
using namespace std;

void solve_sample()
{
  //solves system
  // x+y=10
  // x-y=20
  //see help @http://www.netlib.org/lapack/lug/node38.html
  //see help @http://www.netlib.org/clapack/CLAPACK-3.1.1/SRC/sgetrs.c
  long int info;
  long int n =2;
  long int one(1);
  float a[]={ 1.0f, 1.0f, 1.0f, -1.0f};
  float b[]={ 10.0f, 20.0f };
  long int piv[2];
  sgetrf_(&n,&n,a,&n,piv,&info);
  cout<<info<<endl;
  sgetrs_("N",&n,&one,a,&n,piv,b,&n,&info);
  
  cout<<info<<endl;
  cout<<b[0]<<"\t"<<b[1]<<endl;
}

//main function: accepts as input parameter a matlab file containing the points sampled on the circle
int main(int argc, char* argv[])
{
  solve_sample();
  try
  {
    if(argc<2)
      throw runtime_error("not enought parameters!");

    string inputfilename=argv[1];
    
    Point2Dvector points(inputfilename);//read input points
    
    CircleFitter cf;//initialize the circle fitter object

    CircleFitter::Circle fitted_circle=cf.Run(points);//solves the fitting problem

    cout<<"The optimal parameters are:\n"<<fitted_circle<<endl;//outputs the result
  }
  catch(std::exception &e)
  {
    cout<<"catched error: "<< e.what()<<endl;
  }

  return 0;
}

