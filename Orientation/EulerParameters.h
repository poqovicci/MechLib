/*
 * EulerParameters.h
 *
 *  Created on: 06.Ağu.2011
 *      Author: burak
 */

#ifndef EULERPARAMETERS_H_
#define EULERPARAMETERS_H_



template<typename Scalar>
class EulerParameters:public OrientationParameters<Scalar,4>{

public:

/*
 *  Typedefs
 */
	typedef OrientationParameters<Scalar,4> param;

/*
 * Using statements
 *
 */

/*using for direct accessing to base class members  */
	using param::m_parameters;
	using param::m_parameters_v;

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
	EulerParameters(void):
		param()
	{

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
	EulerParameters(Matrix& _matrix):
		param()
	{

	}

/*
 * Function prototypes
 *
 */

/* Current:
 *
 *  --Implemented %0-NOT_TESTED-
 *
 * Note:
 *
 *  We have ZXZ transformation but too many calculations and can we make it with seperate functions for each sequence?
 *
 * brief:
 *
 *  SetParameters from orientation matrix
 */
	void SetParameters(Matrix&);

/* Current:
 *
 *  --OK--
 *
 * Note:
 *
 *
 *
 * brief:
 *
 *  GetParameters in a vector structure
 */
	Vector GetParameters(void);

/* Current:
 *
 *  --OK--
 *
 * Note:
 *
 * Implemented by stack preassigning variables.
 *
 * TestNote:
 *
 * Tested only once and seems there is no error with it.
 *
 * brief:
 *
 *  Return position transformation matrix A that is r=A(q).*u
 */
	Matrix  GetPosTrans(void);

/* Current:
 *
 *  --OK--
 *
 * Note:
 *
 * Implemented thought nicely.
 *
 * TestNote:
 *
 * Tested only once and seems there is no error with it.
 *
 * brief:
 *
 *  Return velocity transformation matrix local_G that used in omega=G.*qdot
 */
	Matrix  GetVTransLocal(void);

/* Current:
 *
 *  --Implemented %100-NOT_TESTED-
 *
 * Note:
 *
 * Implemented nicely thought.
 *
 * TestNote:
 *
 * brief:
 *
 *  Returns velocity transformation matrix on common inertial frame. First it evaluates local velocity transformation matrix and
 *  then transforms it to global by multiplying it by orientation matrix.
 *
 */
	Matrix  GetVTransGlobal(void);

/* Current:
 *
 *  --OK--
 *
 * Note:
 *
 * Implemented nicely thought.
 *
 * TestNote:
 *
 * Tested only once seems OK.
 *
 * brief:
 *
 *  Returns velocity transformation matrix's time differentiation on local coordinates.
 *
 */
	Matrix  GetVTransDotLocal(void);

/* Current:
 *
 *  --Implemented %100-NOT_TESTED--
 *
 * Note:
 *
 * Implemented nicely thought.
 *
 * TestNote:
 *
 *
 *
 * brief:
 *
 *  Returns velocity transformation matrix's time differentiation on common inertial frame.First it evaluates local velocity transformation matrix's time differentiation and
 *  then transforms it to global by multiplying it by orientation matrix.
 *
 */
	Matrix  GetVTransDotGlobal(void);


/* Current:
 *
 *  --Implemented %0-NOT_TESTED-
 *
 * Note:
 *
 *
 *
 * TestNote:
 *
 * brief:
 *
 *  Returns angular velocity vector on common inertial frame.
 *
 *
 */
	Vector  GetAngularVelLocal(void);

/* Current:
 *
 *  --Implemented %0-NOT_TESTED-
 *
 * Note:
 *
 *
 *
 * TestNote:
 *
 * brief:
 *
 *  Returns angular velocity vector on common inertial frame.
 *
 *
 */
	Vector  GetAngularVelGlobal(void);

/*
 * Variables
 *
 */

private:

/*Define parameters' short name (might change these but how? we dont like defines for base class members)  */
#define e0     m_parameters[0]
#define	e1     m_parameters[1]
#define e2     m_parameters[2]
#define	e3     m_parameters[3]
#define e0dot  m_parameters_v[0]
#define	e1dot  m_parameters_v[1]
#define e2dot  m_parameters_v[2]
#define	e3dot  m_parameters_v[3]

};



template<typename Scalar> Matrix EulerParameters<Scalar>::GetPosTrans(void)
{

	Matrix m;
	m.resize(3,3); /*input matrix(left hand side matrix) might be larger than transformation matrix if so shrink it */
	Scalar e1e1 = e1*e1,
           e2e2 = e2*e2,
           e3e3 = e3*e3,
           e0e1 = e0*e1,
    	   e0e2 = e0*e2,
    	   e0e3 = e0*e3,
    	   e1e2 = e1*e2,
    	   e1e3 = e1*e3,
    	   e2e3 = e2*e3;

/*Row 1 assign*/
    m(0,0) = 1 - 2*e2e2 - 2*e3e3;
    m(0,1) = 2*( e1e2 - e0e3 );
    m(0,2) = 2*( e1e3 + e0e2 );

/*Row 2 assign*/
    m(1,0) = 2*( e1e2 + e0e3 );
    m(1,1) = 1 - 2*e1e1 - 2*e3e3;
    m(1,2) = 2*( e2e3 - e0e1 );

/*Row 3 assign*/
    m(2,0) = 2*( e1e3 - e0e2 );
    m(2,1) = 2*( e2e3 + e0e1 );
    m(2,2) = 1 - 2*e1e1 - 2*e2e2;

	return m;

}

template <typename Scalar> Matrix EulerParameters<Scalar>::GetVTransLocal(void)
{

	Matrix m;

/*Eigen checks size of matrix if it's equal to passed size then no operations made.If input matrix is large than shrink it. */
	m.resize(3,4);

/*Row 1 assign*/
	m(0,0) = 2*(-e1);
	m(0,1) = 2*(e0);
    m(0,2) = 2*(e3);
    m(0,3) = 2*(-e2);

/*Row 2 assign*/
	m(1,0) = 2*(-e2);
	m(1,1) = 2*(-e3);
    m(1,2) = 2*(e0);
    m(1,3) = 2*(e1);

/*Row 3 assign*/
	m(2,0) = 2*(-e3);
	m(2,1) = 2*(e2);
    m(2,2) = 2*(-e1);
    m(2,3) = 2*(e0);

    return m;

}

template<typename Scalar> Matrix EulerParameters<Scalar>::GetVTransDotLocal(void)
{
	Matrix m;

/*Eigen checks size of matrix if it's equal to passed size then no operations made.If input matrix is larger than return matrix, than shrink it. */
	m.resize(3,4);

/*Row 1 assign*/
	m(0,0) = 2*(-e1dot);
	m(0,1) = 2*(e0dot);
    m(0,2) = 2*(e3dot);
    m(0,3) = 2*(-e2dot);

/*Row 2 assign*/
	m(1,0) = 2*(-e2dot);
	m(1,1) = 2*(-e3dot);
    m(1,2) = 2*(e0dot);
    m(1,3) = 2*(e1dot);

/*Row 3 assign*/
	m(2,0) = 2*(-e3dot);
	m(2,1) = 2*(e2dot);
    m(2,2) = 2*(-e1dot);
    m(2,3) = 2*(e0dot);

    return m;

}

template<typename Scalar> Matrix EulerParameters<Scalar>::GetVTransGlobal(void)
{
	Matrix m,A;

/*Eigen checks size of matrix if it's equal to passed size then no operations made.If input matrix is larger than return matrix, than shrink it. */
	m.resize(3,4);

	A=GetPosTrans();
	m=A*GetVTransLocal();

	return m;
}

template<typename Scalar> Matrix EulerParameters<Scalar>::GetVTransDotGlobal(void)
{
	Matrix m,A;

/*Eigen checks size of matrix if it's equal to passed size then no operations made.If input matrix is larger than return matrix, than shrink it. */
	m.resize(3,4);

	A=GetPosTrans();
	m=A*GetVTransDotLocal();

	return m;
}

template<typename Scalar> Vector EulerParameters<Scalar>::GetAngularVelLocal(void)
{
	Vector v,prm;

/*Eigen checks size of matrix if it's equal to passed size then no operations made.If input matrix is larger than return matrix, than shrink it. */
	v.resize(3);

	prm.resize(4);
	prm(0)=e0dot;prm(1)=e1dot;
	prm(2)=e2dot;prm(3)=e3dot;

    v=GetVTransLocal()*prm;

	return v;
}

template<typename Scalar> Vector EulerParameters<Scalar>::GetAngularVelGlobal(void)
{
	Vector v;
    Matrix A;

/*Get local angular velocity*/
	v=GetAngularVelLocal();

/*Get transformation matrix with respect to inertial frame*/
    A=GetPosTrans();

/*Calculate angular velocity with respect to inertial frame*/
    v=A*v;

	return v;
}

template<typename Scalar> Vector EulerParameters<Scalar>::GetParameters(void){
	Vector v;

	v.resize(4);

	v[0]=this->e0;
	v[1]=this->e1;
	v[2]=this->e2;
	v[3]=this->e3;

	return v;
}
template<typename Scalar> void EulerParameters<Scalar>::SetParameters(Matrix& m){
double p1,p2,p3,p4;





}



#endif /* EULERPARAMETERS_H_ */
