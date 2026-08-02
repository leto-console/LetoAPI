/**
 * @file LetoAppStatus.h
 * @date May 27, 2026
 * @author Rakhimov T.
 */

#ifndef INC_LETO_API_V1_APPLICATION_LETO_APP_STATUS_H_
#define INC_LETO_API_V1_APPLICATION_LETO_APP_STATUS_H_

#include <stdint.h>

typedef int32_t LetoAppStatus_V1; 

#define LETO_V1_WORK_STATUS 		 0  ///< Normal application operation
#define LETO_V1_CLOSE_STATUS		-1  ///< Application exit request
#define LETO_V1_ERROR_STATUS 	    -2  ///< Error occurred during application runtime
#define LETO_V1_NOT_WORK_STATUS     -3  ///< Application not running

#endif
