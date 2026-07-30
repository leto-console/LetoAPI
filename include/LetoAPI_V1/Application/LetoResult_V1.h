/**
 * @file LetoResult.h
 * @date May 27, 2026
 * @author Rakhimov T.
 */

#ifndef INC_LETO_API_V1_APPLICATION_LETO_RESULT_H_
#define INC_LETO_API_V1_APPLICATION_LETO_RESULT_H_

#include <stdint.h>

typedef int32_t LetoResult_V1; 

#define LETO_V1_SUCCESS 		 0;	///< Operation completed successfully
#define LETO_V1_ERROR 			-1;	///< Generic error
#define LETO_V1_UNSUPPORT 		-2;	///< Not supported
#define LETO_V1_ARGS_ERROR		-3;	///< Invalid arguments
#define LETO_V1_ALREADY_DONE 	-4;	///< Already executed previously
#define LETO_V1_OUT_OF_MEMORY	-5;	///< Out of dynamic memory

#endif
