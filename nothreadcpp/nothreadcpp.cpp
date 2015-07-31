#include <iostream>
#include <tracer/tracer.h>

int fact(int x)
{
   TRACE("int fact(int)");

   if (x == 1)
   {
      return 1;
   }
   else
   {
      return x * fact(x - 1);
   }
}

int main()
{
   TRACE("main()");

   std::cout << "3! = " << fact(3) << std::endl;
   std::cout << "7! = " << fact(7) << std::endl;

   return 0;
}
