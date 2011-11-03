/*
 * parameters.h
 *
 *  Created on: 03.Ağu.2011
 *      Author: burak
 */

#ifndef ORIENT_PARAMETERS_H_
#define ORIENT_PARAMETERS_H_




template<typename Scalar,unsigned char paramcount>
class OrientationParameters{

/*
 *  Typedefs
 */
	typedef OrientationParameters<Scalar,paramcount> OrientP;

/*
 * Using statements
 *
 */

public:

/* Current:
 *
 *  --Implemented<<%100-NOT_TESTED--
 *
 * Note:
 *
 *
 * brief:
 *
 *  Default constructor
 */

	OrientationParameters(void):count(paramcount)
	{


    }

/*
 * Function prototypes
 *
 */

/* brief:
 *
 *  SetParameters from orientation matrix
 *
 */
	void SetParameters(Matrix&);

/* brief:
 *
 *  Return position transformation matrix A that is r=A(q).*u
 *
 */
	Matrix  GetPosTrans(void);

/* brief:
 *
 *  Return velocity transformation matrix local_G that used in omega=G.*qdot
 *
 */
	Matrix  GetVTransLocal(void);

/* brief:
 *
 *  Returns velocity transformation matrix on common inertial frame. First it evaluates local velocity transformation matrix and
 *  then transforms it to global by multiplying it by orientation matrix.
 *
 */
	Matrix  GetVTransGlobal(void);

/* brief:
 *
 *  Returns velocity transformation matrix's time differentiation on local coordinates.
 *
 */
	Matrix  GetVTransDotLocal(void);

/* brief:
 *
 *  Returns velocity transformation matrix's time differentiation on common inertial frame.First it evaluates local velocity transformation matrix's time differentiation and
 *  then transforms it to global by multiplying it by orientation matrix.
 *
 */
	Matrix  GetVTransDotGlobal(void);

/* brief:
 *
 *  Returns angular velocity vector on common inertial frame.
 *
 */
	Vector  GetAngularVelLocal(void);

/* brief:
 *
 *  Returns angular velocity vector on common inertial frame.
 *
 */
	Vector  GetAngularVelGlobal(void);

/*Operators*/

	OrientP operator+ (OrientP);
	OrientP operator+= (OrientP);
	void operator<< (Scalar*);
	OrientP operator-= (OrientP);
	unsigned char operator== (OrientP);
/*
 *  Variables
 */

/*Parameters' list */
	Scalar m_parameters[paramcount];

/*Parameters' time differentiation list*/
	Scalar m_parameters_v[paramcount];

/*Parameters count*/
    unsigned char count;
};





#endif /* ORIENT_PARAMETERS_H_ */
