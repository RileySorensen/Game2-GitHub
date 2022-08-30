#include "Matrix2x2.h"
namespace Bogo
{
	//0 1
	//1 0 
	const Matrix2x2 Matrix2x2::Identity{ {1,0}, {0,1} };
	const Matrix2x2 Matrix2x2::Zero{ {0,0}, {0,0} };
}