#include "beremiz.h"
#ifndef __POUS_H
#define __POUS_H

#include "accessor.h"
#include "iec_std_lib.h"

__DECLARE_ENUMERATED_TYPE(LOGLEVEL,
  LOGLEVEL__CRITICAL,
  LOGLEVEL__WARNING,
  LOGLEVEL__INFO,
  LOGLEVEL__DEBUG
)
// FUNCTION_BLOCK LOGGER
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,TRIG)
  __DECLARE_VAR(STRING,MSG)
  __DECLARE_VAR(LOGLEVEL,LEVEL)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,TRIG0)

} LOGGER;

void LOGGER_init__(LOGGER *data__, BOOL retain);
// Code part
void LOGGER_body__(LOGGER *data__);
// PROGRAM LAB2
// Data part
typedef struct {
  // PROGRAM Interface - IN, OUT, IN_OUT variables

  // PROGRAM private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,BUZZER)
  __DECLARE_VAR(BOOL,SENSOR)
  __DECLARE_VAR(BOOL,BOTON1)
  __DECLARE_VAR(BOOL,BOTON2)
  TON TON0;
  SR SR0;
  TP TP1;
  TOF TOF0;
  RS RS0;
  __DECLARE_VAR(BOOL,_TMP_NOT7_OUT)
  __DECLARE_VAR(BOOL,_TMP_NOT19_OUT)
  __DECLARE_VAR(BOOL,_TMP_AND20_OUT)

} LAB2;

void LAB2_init__(LAB2 *data__, BOOL retain);
// Code part
void LAB2_body__(LAB2 *data__);
#endif //__POUS_H
