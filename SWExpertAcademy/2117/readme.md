# 2117. 홈 방법 서비스

* Variables
** T : # of testcases   
** N : size of the city   
** M : cost per house    
** K_MAX : maximum size of the service region   

* Functions
** int *abs*(int s) :   
  returns absolute value of *s* 

** bool *isRegion*(int x, int y, int ox, int oy, int K) :    
  checks whether the **(x, y)** is under the service region with **K**-size and **(ox, oy)** center point    
  if the **(x, y)** is under the service region it returns true   
  else return false
** int *sim*(int ox, int oy, int K):   
  return the number of houses under the service region with **K**-size of service region and **(ox, oy)** center point, only if the service doesn't lose its profit. 

** int main() :    
  For all possible size of service region **k** and **(j, i)** center point, find the maximum number of houses under the service region.

