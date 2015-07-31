#include <stdio.h>
#include <tracer/tracer.h>

int fact(int x)
{
   int retval;
   TRACEIN("int fact(int)");

   if (x == 1)
   {
      retval = 1;
   }
   else
   {
      retval = x * fact(x - 1);
   }

   TRACEOUT("int fact(int)");
   return retval;
}

int main()
{
   TRACEIN("main()");

   printf("%d! = %d\n", 3, fact(3));
   printf("%d! = %d\n", 7, fact(7));

   TRACEOUT("main()");
   return 0;
}
