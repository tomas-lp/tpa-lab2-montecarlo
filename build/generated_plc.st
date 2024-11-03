PROGRAM lab2
  VAR
    Buzzer AT %QX0.0 : BOOL := 0;
    Sensor AT %IX0.0 : BOOL;
    Boton1 AT %IX0.1 : BOOL;
    Boton2 AT %IX0.2 : BOOL;
  END_VAR
  VAR
    TON0 : TON;
    SR0 : SR;
    TP1 : TP;
    TOF0 : TOF;
    RS0 : RS;
    _TMP_NOT7_OUT : BOOL;
    _TMP_NOT19_OUT : BOOL;
    _TMP_AND20_OUT : BOOL;
  END_VAR

  _TMP_NOT7_OUT := NOT(Sensor);
  SR0(S1 := _TMP_NOT7_OUT, R := Boton1 OR TON0.Q);
  TON0(IN := SR0.Q1, PT := T#5000ms);
  RS0(S := TON0.Q, R1 := Boton2);
  TOF0(IN := TP1.Q, PT := T#1000ms);
  _TMP_NOT19_OUT := NOT(TOF0.Q);
  _TMP_AND20_OUT := AND(RS0.Q1, _TMP_NOT19_OUT);
  TP1(IN := _TMP_AND20_OUT, PT := T#1000ms);
  Buzzer := TP1.Q;
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : lab2;
  END_RESOURCE
END_CONFIGURATION
