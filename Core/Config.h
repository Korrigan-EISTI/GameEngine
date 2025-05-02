#pragma once

#define USE_DOUBLE_PRECISON 0

#if USE_DOUBLE_PRECISON
	typedef double Real;
#else
	typedef float Real;
#endif // USE_DOUBLE_PRECISON

