#include "Matrix3x3.h"
namespace Bogo
{
	//1 0 0
	//0 1 0
	//0 0 1

	const Matrix3x3 Matrix3x3::Identity
	{ 
		Vector3{1,0,0}, 
		Vector3{0,1,0}, 
		Vector3{0,0,1}
	};

	const Matrix3x3 Matrix3x3::Zero
	{
		Vector3{0,0,0},
		Vector3{0,0,0},
		Vector3{0,0,0}
	};
}