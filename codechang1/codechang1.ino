 if (analogRead(A0) > F[0] && analogRead(A5) > F[5]) {
    _kmotor.tien(0,255);
    _kmotor.tien(1,255-dolech);
  }
  if (analogRead(A0) > F[0] && analogRead(A5) < F[5]) {
    _kmotor.tien(0,255);
    _kmotor.tien(1,255-dolech);
  }
  if (analogRead(A0) < F[0] && analogRead(A5) > F[5]) {
    _kmotor.tien(0,255);
    _kmotor.tien(1,255-dolech);
  }
  if (analogRead(A5) > F[5] && analogRead(A7) > F[7]) {
    _kmotor.tien(0,255);
    _kmotor.tien(1,255-dolech);
  }
  if (analogRead(A0) > F[0] && analogRead(A1) > F[1]) {
    _kmotor.tien(0,255);
    _kmotor.tien(1,255-dolech);
  }
 if (analogRead(A6) > F[6] && analogRead(A7) > F[7]) {
    _kmotor.tien(0,255);
    _kmotor.tien(1,255-dolech);
  }
   if (analogRead(A1) > F[1] && analogRead(A2) > F[2]) {
    _kmotor.tien(0,255);
    _kmotor.tien(1,255-dolech);
  }
   if (analogRead(A4) > F[4] && analogRead(A6) > F[6]) {
    _kmotor.tien(0,255);
    _kmotor.tien(1,150-dolech);
  }
  if (analogRead(A2) > F[2] && analogRead(A3) > F[3]) {
    _kmotor.tien(0,150);
    _kmotor.tien(1,255-dolech);
  }
  //8 truong hop sau
  if (analogRead(A3) > F[3] && analogRead(A2) < F[2]) {
    _kmotor.tien(0,50);
    _kmotor.tien(1,255-dolech);
  }
   if (analogRead(A4) > F[4] && analogRead(A6) < F[6]) {
    _kmotor.tien(0,50);
    _kmotor.tien(1,255-dolech);
  }
 if (analogRead(A2) > F[2] && analogRead(A3) < F[3] && analogRead(A1) < F[1]) {
    _kmotor.tien(0,255);
    _kmotor.tien(1,255-dolech);
  }
   if (analogRead(A6) > F[6] && analogRead(A7) < F[7] && analogRead(A4) < F[4]) {
    _kmotor.tien(0,255);
    _kmotor.tien(1,255-dolech);
  }
   if (analogRead(A7) > F[7] && analogRead(A6) < F[6] && analogRead(A5) < F[5]) {
    _kmotor.tien(0,255);
    _kmotor.tien(1, 255-dolech);
  }
  if (analogRead(A1) > F[1] && analogRead(A2) < F[2] && analogRead(A0) < F[0]) {
    _kmotor.tien(0,255);
    _kmotor.tien(1, 255-dolech);
  }
  if (analogRead(A0) > F[0] && analogRead(A5) < F[5] && analogRead(A1) < F[1]) {
    _kmotor.tien(0,255);
    _kmotor.tien(1, 255-dolech);
  }
  if (analogRead(A5) > F[5] && analogRead(A0) < F[0] && analogRead(A7) < F[7]) {
    _kmotor.tien(0,255);
    _kmotor.tien(1, 255-dolech);
  }
}
