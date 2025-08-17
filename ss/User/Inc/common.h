/*
 * common.h
 *
 *  Created on: Aug 17, 2025
 *      Author: vermi
 */

#ifndef INC_COMMON_H_
#define INC_COMMON_H_

#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <stm32f4xx.h>
#include <main.h>

#define CLASS(NAME) \
    typedef struct _##NAME NAME; \
    struct _##NAME

#define PRIVATE(NAME) \
    typedef struct _##NAME##Private NAME##Private; \
    struct _##NAME##Private


#endif /* INC_COMMON_H_ */
