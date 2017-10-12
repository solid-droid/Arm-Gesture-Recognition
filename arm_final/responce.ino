void responce(int a)
{
  switch(a)
  {
    case 486:close_fing_3();
      break;
    case 468:open_fing();
      break;      
    case 426:v_sign();
      break;
    case 428:hold();
      break;
    case 462:
      break;
    case 482:
      break;
    case 846:
      break;
    case 648:
      break;
    case 246:
      break;
    case 248:
      break;
    case 642:
      break;
    case 842:
      break;
    case 864:
      break;
    case 684:
      break;
    case 264:
      break;
    case 284:
      break;
    case 624:
      break;
    case 824:
      break;
  }
}
void low()
{
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, LOW);
    digitalWrite(motorPin5, LOW);
    digitalWrite(motorPin6, LOW);
    digitalWrite(motorPin7, LOW);
    digitalWrite(motorPin8, LOW);
    delay(1);
}
void close_fing_3()
{
    low();
    digitalWrite(motorPin2, HIGH);
    digitalWrite(motorPin3, HIGH);
    digitalWrite(motorPin5, HIGH);
    delay(200); 
    low();
    delay(2000);
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin4, HIGH);
    digitalWrite(motorPin6, HIGH);
    delay(200); 
    low();
}
void open_fing()
{
  
}
void v_sign()
{
    low();
    digitalWrite(motorPin3, HIGH);
    delay(300); 
    low();
    delay(2000);
    digitalWrite(motorPin4, HIGH);
    delay(100); 
    low();
}
void hold()
{
  
}

