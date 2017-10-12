int process()
{ 
  if(acc_x>2500&&acc_z<-1200)
   return(6);
  else if(acc_x<-2000&&acc_z<-1200)
   return(4);
  else if(acc_y>2000&&acc_z<-1200)
   return(2);
  else if(acc_y<-2000&&acc_z<-1200)
   return(8);
  else
   return(0);
}

