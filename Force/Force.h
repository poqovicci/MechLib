/*
 * force.h
 *
 *  Created on: 03.Ağu.2011
 *      Author: burak
 */

#ifndef FORCE_H_
#define FORCE_H_


template<typename Scalar>
class Force
{


public:
	Force()
	{
	}
	Force(Scalar fx,Scalar fy,Scalar fz)
	{
	    p_var(0)=fx;
	    p_var(1)=fy;
	    p_var(2)=fz;

	}

    Vector p_var;
};










#endif /* FORCE_H_ */
