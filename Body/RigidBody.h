/*
 * rigid.h
 *
 *  Created on: 03.Ağu.2011
 *      Author: burak
 */

#ifndef RIGID_H_
#define RIGID_H_

#define Ixx 0
#define Ixy 1
#define Ixz 2
#define Iyx 3
#define Iyy 4
#define Iyz 5
#define Izx 6
#define Izy 7
#define Izz 8



template <typename orient_parameters,typename Scalar>
class Rigidbody:public Body<orient_parameters,Scalar>{

	typedef Body<orient_parameters,Scalar> base;

public:

/* Current:
 *
 *  --Implemented <%100-NOT_TESTED--
 *
 * Note:
 *
 *  Some other initializations might be required
 *
 * brief:
 *
 *  Default constructor
 */
	Rigidbody(void):
		base()
	{
		m_inertia=Vector(8,1);
    }

/* Current:
 *
 *  --Implemented <%100-NOT_TESTED--
 *
 * Note:
 *
 *  Some other initializations might be required
 *
 * brief:
 *
 *  Constructor overload
 */
	Rigidbody(Scalar mass,Vector& inertia):
		base(mass)
	{
		m_inertia=inertia;
	}

/* Current:
 *
 *  --Implemented <%100-NOT_TESTED-
 *
 * Note:
 *
 *
 *
 * brief:
 *
 *  Constructor overload
 */
	Rigidbody(Scalar mass,Vector& inertia,Vector& pos,Vector& vel):
		base(mass,pos,vel)
	{
		m_inertia=inertia;
	}

/*
 *
 * Function Prototypes
 *
 */


/* Current:
 *
 *  --Implemented %0-NOT_TESTED-
 *
 * Note:
 *
 *
 *
 * brief:
 *
 * Gets external force vector with respect to inertial frame
 */

	virtual Vector GetActivatorVec(void);

/* Current:
 *
 *  --Implemented %0-NOT_TESTED-
 *
 * Note:
 *
 *
 *
 * brief:
 *
 *  Returns mass matrix with respect to specified template parameters
 */

	virtual Matrix GetMassMatrix(void);



private:

/* Current:
 *
 *  --Implemented %0-NOT_TESTED-
 *
 * Note:
 *
 *
 *
 * brief:
 *
 * Gets external force vector with respect to inertial frame
 */
	Vector GetForceVec(void);

/* Current:
 *
 *  --Implemented %0-NOT_TESTED-
 *
 * Note:
 *
 *
 *
 * brief:
 *
 *  Returns quadratic inertia vector on velocities with respect to gravitation center reference point base.
 */
	Vector3 GetInertiaVector(void);

/* Current:
 *
 *  --Implemented %0-NOT_TESTED-
 *
 * Note:
 *
 *
 *
 * brief:
 *
 *  Gets External torque vector
 */
	Vector3 GetTorqueVec(void);

/* Current:
 *
 *  --Implemented %0-NOT_TESTED-
 *
 * Note:
 *
 *
 *
 * brief:
 *
 *  Returns self generalized parameter constraint matrix.Returns null matrix if there is no constraint with all parameters.
 */
	Matrix GetSelfConstraintJacobien(void);

/*
 *  Variables
 */
public:
/*Local Inertia matrix*/
	Matrix m_inertia;

/*Gravitation center in local coordinates*/
	LocalVector m_gpos;

};


template<typename orient_parameters,typename Scalar>
Matrix Rigidbody<orient_parameters,Scalar>::GetMassMatrix(void)
{
	Matrix mtr;



	return mtr;
}

template<typename orient_parameters,typename Scalar>
Vector Rigidbody<orient_parameters,Scalar>::GetActivatorVec(void)
{
	Vector v;


	return v;
}
template<typename orient_parameters,typename Scalar>
Vector Rigidbody<orient_parameters,Scalar>::GetForceVec(void){

	Vector v(6);

    	 v(0)=this->base.m_forcelst->p_var(0);
    	 v(1)=this->base.m_forcelst->p_var(1);
    	 v(2)=this->base.m_forcelst->p_var(2);
    	 v(3)=this->base.m_forcelst->p_var(3);
    	 v(4)=this->base.m_forcelst->p_var(4);
    	 v(5)=this->base.m_forcelst->p_var(5);

	return v;

}





#endif /* RIGID_H_ */
