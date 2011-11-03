/*
 * Body.h
 *
 *  Created on: 06.Ağu.2011
 *      Author: burak
 */

#ifndef BODY_H_
#define BODY_H_

/* \class Body
 *
 * Current:
 *
 *  --Implemented %100-NOT_TESTED ALL FUNCTIONS--
 *
 * Note:
 *
 * brief:
 *  Base class for all rigid bodies,flexible bodies
 *
 */
template<typename orient_parameters, typename Scalar>
class Body {

public:

	/* Current:
	 *
	 *  --Implemented %100-NOT_TESTED--
	 *
	 * Not:
	 *
	 *  Too many calculations,needs Eigen Alternative have i said Eigen alternative does not compile?)
	 *
	 * brief:
	 *  Default constructor with initialization
	 */
	Body(void) {
		m_parameters = orient_parameters();
		m_pos = Vector(3, 1);
		m_vel = Vector(3, 1);
	}
	/* Current:
	 *
	 *  --Implemented %100-NOT_TESTED--
	 *
	 * Not:
	 *
	 *
	 *
	 * brief:
	 *  Constructor overloading
	 */
	Body(Scalar mass) {
		m_parameters = orient_parameters();
		m_mass = mass;
		m_pos = Vector(3, 1);
		m_vel = Vector(3, 1);
	}

	/* Current:
	 *
	 *  --Implemented %100-NOT_TESTED--
	 *
	 * Not:
	 *
	 *
	 *
	 * brief:
	 *  Constructor overloading
	 */
	Body(Scalar mass, Vector& pos, Vector& vel) {
		m_mass = mass;
		m_pos = pos;
		m_vel = vel;
	}

	/*
	 *
	 * Function prototypes
	 *
	 */

	/* Current:
	 *
	 *  --Implemented %100-TESTED--
	 *
	 * Note:
	 *
	 *
	 * brief:
	 *
	 *  Get mass matrix of current coordinate system
	 *  (translation+orientation for "rigid" and translation+orientation+flexibility coordinates for "flexible body" )
	 *
	 */
	virtual Matrix GetMassMatrix(void)=0;

	/* Current:
	 *
	 *  --Implemented %100-TESTED--
	 *
	 * Note:
	 *
	 *
	 *
	 * brief:
	 *  Get right hand side of equality of system
	 */
	virtual Vector GetActivatorVec(void)=0;

	/*
	 *  Class Variables
	 *
	 */

	/*mass of body coordinates of translation*/
	Scalar m_mass;

	/*position of reference point*/
	Vector m_pos;

	/*velocity of reference point*/
	Vector m_vel;

	/*body orientation coordinates*/
	orient_parameters m_parameters;

	/*body external force list*/
	Force<Scalar>* m_forcelst;

	/*is body fixed on inertial frame??*/
	unsigned char m_is_fixed;

};

#endif /* BODY_H_ */
