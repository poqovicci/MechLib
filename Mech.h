/*
 * mech_prototypes.h
 *
 *  Created on: July 26, 2011
 *      Author: burak
 */

#ifndef MECH_TYPES_H_
#define MECH_TYPES_H_

#include "ThirdParty/Eigen/Eigen"

namespace Mech{



typedef Eigen::MatrixXd Matrix;
typedef Eigen::VectorXd Vector;
typedef Eigen::VectorXd LocalVector;
typedef Eigen::Vector3d Vector3;
typedef Eigen::Vector2d Vector2;


#include "Force/Force.h"
#include "Body/Body.h"
#include "Body/RigidBody.h"
#include "Body/Multibody.h"
#include "Orientation/OrientParameters.h"
#include "Orientation/EulerAngles.h"
#include "Orientation/EulerParameters.h"
}

#endif /* MECH_PROTOTYPES_H_ */
