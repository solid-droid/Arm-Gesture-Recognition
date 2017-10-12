
boolean codef()
{
  if(element<3)
  {
    act=HIGH;
    temp_code[element++]=type;
    return(LOW);
  }
  else 
  {
    for(int i=0;i<3;++i)
    {
      act=LOW;
      code[i]=temp_code[i];
      temp_code[i]=0;
    } 
    element=0;
    return(HIGH);
  }
}
void clear_code()
{
  act=LOW;
  element=0;
    for(int i=0;i<3;++i)
    {
      code[i]=0;
      temp_code[i]=0;
    } 
}
int check()
{
  
  x=code[0];
  y=code[1];
  z=code[2];
  return(100*x+10*y+z);
}

