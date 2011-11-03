/*
 * Multibody.h
 *
 *  Created on: 06.Ağu.2011
 *      Author: burak
 */

#ifndef MULTIBODY_H_
#define MULTIBODY_H_

class  Multibody{
public:
/*
 * brief
 * Gets total system mass matrix
 * _matrix's size must be at least equal to system's mass matrix size.
 *
 * */
void GetMassMatrix(Matrix& _matrix);
/*
 * Gets activator vector(right hand side vector b)
 * _vector's size must be at least equal to system's coordinates count.
 *
 * */
void GetActivatorVec(Vector& _vector);//
/*
 * Adds body to body list
 *
 * */
template<typename orient_parameters,typename Scalar> void AddBody(Body<orient_parameters,Scalar>);


private:


/*
 * brief
 * Gets total parameter count of system
 */
unsigned long int GetTotalMassMatrixSize(void);



};

#endif /* MULTIBODY_H_ */
