void LOGGER_init__(LOGGER *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MSG,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->LEVEL,LOGLEVEL__INFO,retain)
  __INIT_VAR(data__->TRIG0,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void LOGGER_body__(LOGGER *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((__GET_VAR(data__->TRIG,) && !(__GET_VAR(data__->TRIG0,)))) {
    #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
    #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)

   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  
    #undef GetFbVar
    #undef SetFbVar
;
  };
  __SET_VAR(data__->,TRIG0,,__GET_VAR(data__->TRIG,));

  goto __end;

__end:
  return;
} // LOGGER_body__() 





void LAB2_init__(LAB2 *data__, BOOL retain) {
  __INIT_VAR(data__->BUZZER,0,retain)
  __INIT_VAR(data__->SENSOR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BOTON1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BOTON2,__BOOL_LITERAL(FALSE),retain)
  TON_init__(&data__->TON0,retain);
  SR_init__(&data__->SR0,retain);
  TP_init__(&data__->TP1,retain);
  TOF_init__(&data__->TOF0,retain);
  RS_init__(&data__->RS0,retain);
  __INIT_VAR(data__->_TMP_NOT7_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_NOT19_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_AND20_OUT,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void LAB2_body__(LAB2 *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->,_TMP_NOT7_OUT,,!(__GET_VAR(data__->SENSOR,)));
  __SET_VAR(data__->SR0.,S1,,__GET_VAR(data__->_TMP_NOT7_OUT,));
  __SET_VAR(data__->SR0.,R,,(__GET_VAR(data__->BOTON1,) || __GET_VAR(data__->TON0.Q,)));
  SR_body__(&data__->SR0);
  __SET_VAR(data__->TON0.,IN,,__GET_VAR(data__->SR0.Q1,));
  __SET_VAR(data__->TON0.,PT,,__time_to_timespec(1, 5000, 0, 0, 0, 0));
  TON_body__(&data__->TON0);
  __SET_VAR(data__->RS0.,S,,__GET_VAR(data__->TON0.Q,));
  __SET_VAR(data__->RS0.,R1,,__GET_VAR(data__->BOTON2,));
  RS_body__(&data__->RS0);
  __SET_VAR(data__->TOF0.,IN,,__GET_VAR(data__->TP1.Q,));
  __SET_VAR(data__->TOF0.,PT,,__time_to_timespec(1, 1000, 0, 0, 0, 0));
  TOF_body__(&data__->TOF0);
  __SET_VAR(data__->,_TMP_NOT19_OUT,,!(__GET_VAR(data__->TOF0.Q,)));
  __SET_VAR(data__->,_TMP_AND20_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->RS0.Q1,),
    (BOOL)__GET_VAR(data__->_TMP_NOT19_OUT,)));
  __SET_VAR(data__->TP1.,IN,,__GET_VAR(data__->_TMP_AND20_OUT,));
  __SET_VAR(data__->TP1.,PT,,__time_to_timespec(1, 1000, 0, 0, 0, 0));
  TP_body__(&data__->TP1);
  __SET_VAR(data__->,BUZZER,,__GET_VAR(data__->TP1.Q,));

  goto __end;

__end:
  return;
} // LAB2_body__() 





