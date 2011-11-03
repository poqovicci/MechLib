#include "Mech.h"
#include <stdio.h>
#include <stddef.h>
#include <iostream>

using namespace std;
using namespace Mech;
typedef EulerParameters<double> Eparameters;
typedef Eigen::Matrix<double,2,2> mtr;


int main(void){
	Eparameters p=Eparameters();
	Vector3 v1,v2;
	Rigidbody<Eparameters,double> rigidbdy;



	p.e0=1;
	p.e1=0;
	p.e2=1;
	p.e3=1;

	p.e0dot=1;
	p.e1dot=1;
	p.e2dot=1;
	p.e3dot=1;


	Vector v=p.GetPosTrans()*p.GetAngularVelLocal();
	Matrix mtr=p.GetVTransGlobal();
    cout<<mtr<<"\n\n"<<p.GetParameters();
    Rigidbody<Eparameters,double> rb;
    rb.


    return 0;


}
