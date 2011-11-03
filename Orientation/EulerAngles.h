/*
 * EulerAngles.h
 *
 *  Created on: 06.Ağu.2011
 *      Author: burak
 */

#ifndef EULERANGLES_H_
#define EULERANGLES_H_




template<typename Scalar,typename Sequence1,typename Sequence2,typename Sequence3>
class EulerAngles:public OrientationParameters<Scalar,3>{

	typedef OrientationParameters<Scalar,3> param;

public:

/* Current:
 *
 *  --Implemented %100-TESTED<<%100--
 *
 * Not:
 *
 *
 * brief:
 *
 *  Default constructor with initialization
 */
	EulerAngles(void):param()
	{
		unsigned char i=0;

		while(i<param::count-1)
	    {
			param::parameters[i]=0;
			i++;
		}
	}

/*
 * Function prototypes
 *
 */


/* Current:
 *
 *  --Implemented<<%100-NOT_TESTED-
 *
 * Note:
 *
 *  We have ZXZ transformation but too many calculations and can we make it with seperate functions for each sequence?
 *
 * brief:
 *
 *  SetParameters from orientation matrix
 */
	void SetParameters(Mech::Matrix&);

/* Current:
 *
 *  --Implemented<<%100-NOT_TESTED-
 *
 * Note:
 *
 *
 * brief:
 *
 *  Return position transformation matrix A that is r=A(q).*u
 */
	Matrix  GetPosTrans(unsigned int,unsigned int,unsigned int );

/* Current:
 *
 *  --Implemented<<%100-NOT_TESTED--
 *
 * Note:
 *
 *
 * brief:
 *
 *  Return velocity transformation matrix local_G that used in omega=G.*qdot
 */
	Matrix  GetVTransLocal(void);

/* Current:
 *
 *  --Implemented<<%100-NOT_TESTED--
 *
 * Note:
 *
 *
 * brief:
 *
 *  Returns velocity transformation matrix on common inertial frame
 */
	Matrix  GetVTransGlobal(void);

/* Current:
 *
 *  --Implemented<<%100-NOT_TESTED--
 *
 * Note:
 *
 *
 * brief:
 *
 *  Returns velocity transformation matrix's time differentiation on local coordinates
 */
	Matrix  GetVTransDotLocal(void);

/* Current:
 *
 *  --Implemented<<%100-NOT_TESTED--
 *
 * Note:
 *
 *
 * brief:
 *
 *  Returns velocity transformation matrix's time differentiation on common inertial frame
 */
	Matrix  GetVTransDot(void);
/*
 * Variables
 *
 */


};



/*
 *
 * Class's function implementations
 *
 */

template<typename Scalar,typename Sequence1,typename Sequence2,typename Sequence3>
void EulerAngles<Scalar,Sequence1,Sequence2,Sequence3>::SetParameters(Mech::Matrix& trans_matrix)
{
    /*FOR EULER ANGLES ZXZ
	   double cospsi,sinpsi,costheta,sintheta,sinphi,cosphi;
	   param::parameters[2]=atan((trans_matrix(2,0))/(trans_matrix(2,1)));
       cospsi=cos(param::parameters[2]);
       sinpsi=sin(param::parameters[2]);
	   param::parameters[1]=atan((trans_matrix(2,1)/trans_matrix(2,2))/cospsi);
	   costheta=cos(param::parameters[1]);
       sintheta=sin(param::parameters[1]);
	   cosphi=trans_matrix(1,2)/(-sintheta);
	   sinphi=(trans_matrix(1,0)-costheta*cosphi*sinpsi)/cospsi;
	   param::parameters[0]=atan(sinphi/cosphi);

	   //Eigen implementation ZXZ
       Mech::Vector3 p;
	   p=trans_matrix.eulerAngles(2,0,2);
       param::parameters[0]=p(0,0);
       param::parameters[0]=p(1,0);
       param::parameters[0]=p(2,0);
	   //

	*/

}

template<typename Scalar,typename Sequence1,typename Sequence2,typename Sequence3>
Matrix EulerAngles<Scalar,Sequence1,Sequence2,Sequence3>::GetPosTrans(unsigned int retSeq1,unsigned int reqSeq2,unsigned int retSeq3)
{
	   Matrix temp(3,3);
	 /*FOR EULER ANGLES ZXZ
	   Scalar* parameters=param::parameters;
	   Scalar phi=parameters[0],theta=parameters[1],psi=parameters[2];
	   Scalar sinphi=sin(phi),cosphi=cos(phi),sintheta=sin(theta),costheta=cos(theta),sinpsi=sin(psi),cospsi=cos(psi);
	   // (16 flops)
	   temp(0,0)=(cospsi*cosphi-costheta*sinphi*sinpsi);
       temp(0,1)=(-sinpsi*cosphi-costheta*sinphi*cospsi);
	   temp(0,2)=(sintheta*sinphi);
	   temp(1,0)=(cospsi*sinphi+costheta*cosphi*sinpsi);
	   temp(1,1)=(-sinpsi*sinphi+costheta*cosphi*cospsi);
	   temp(1,2)=(-sintheta*cosphi);
       temp(2,0)=sintheta*sinpsi;
       temp(2,1)=sintheta*cospsi;
       temp(2,2)=costheta;
     */
       return temp;
}

template<typename Scalar,typename Sequence1,typename Sequence2,typename Sequence3>
Matrix  EulerAngles<Scalar,Sequence1,Sequence2,Sequence3>::GetVTransLocal(void)
{
	   Matrix temp(3,3);
	/*FOR EULER ANGLES ZXZ
	   Scalar* parameters=param::parameters;
	   Scalar phi=parameters[0],theta=parameters[1];
	   Scalar sinphi=sin(phi),cosphi=cos(phi),sintheta=sin(theta),costheta=cos(theta);
	   temp(0,0)=(sintheta*sinphi);
       temp(0,1)=(cosphi);
	   temp(0,2)=(0);
	   temp(1,0)=(sintheta*cosphi);
	   temp(1,1)=(-sinphi);
	   temp(1,2)=(0);
       temp(2,0)=costheta;
       temp(2,1)=0;
       temp(2,2)=1;
    */
       return temp;

}

template<typename Scalar,typename Sequence1,typename Sequence2,typename Sequence3>
Matrix EulerAngles<Scalar,Sequence1,Sequence2,Sequence3>::GetVTransGlobal(void)
{
	   return GetPosTrans()*GetVTransLocal();

}

template<typename Scalar,typename Sequence1,typename Sequence2,typename Sequence3>
Matrix EulerAngles<Scalar,Sequence1,Sequence2,Sequence3>::GetVTransDotLocal(void)
{
	   Matrix temp(3,3);
	 /*FOR EULER ANGLES ZXZ
	   Scalar parameters=param::parameters;
	   Scalar parameters_v=param::parameters_v;
	   Scalar theta=parameters[1],psi=parameters[2];
	   Scalar sintheta=sin(theta),costheta=cos(theta),sinpsi=sin(psi),cospsi=cos(psi);
	   Scalar thetadot=parameters_v[1],psidot=parameters_v[2];
	   temp(0,0)=(thetadot*costheta*sinpsi+psidot*sintheta*cospsi);
       temp(0,1)=(-psidot*sinpsi);
	   temp(0,2)=(0);
	   temp(1,0)=(thetadot*costheta*cospsi-psidot*sintheta*sinpsi);
	   temp(1,1)=(-psidot*cospsi);
	   temp(1,2)=(0);
       temp(2,0)=-thetadot*sintheta;
       temp(2,1)=0;
       temp(2,2)=0;
     */
       return temp;


}




template<typename Scalar,typename Sequence1,typename Sequence2,typename Sequence3>
Matrix EulerAngles<Scalar,Sequence1,Sequence2,Sequence3>::GetVTransDot(void)
{
	   Matrix temp(3,3);
	/* FOR EULER ANGLES ZXZ
	   Scalar* parameters=param::parameters;
	   Scalar* parameters_v=param::parameters_v;
	   Scalar phi=parameters[1],theta=parameters[1];
	   Scalar sinphi=sin(phi),cosphi=cos(phi),sintheta=sin(theta),costheta=cos(theta);
	   Scalar phidot=parameters_v[1],thetadot=parameters_v[1];
	   temp(0,0)=(0);
       temp(0,1)=(-phidot*sinphi);
	   temp(0,2)=(thetadot*costheta*sinphi+phidot*sintheta*cosphi);
	   temp(1,0)=(0);
	   temp(1,1)=(phidot*cosphi);
	   temp(1,2)=(-thetadot*costheta*cosphi+phidot*sintheta*sinphi);
       temp(2,0)=0;
       temp(2,1)=0;
       temp(2,2)=-thetadot*sintheta;
    */
       return temp;

}




#endif /* EULERANGLES_H_ */
