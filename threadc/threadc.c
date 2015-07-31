#include <pthread.h>
#include <stdio.h>
#include <time.h>
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

void* test_thread(void* param)
{
   TRACEIN("void* test_thread(void*)");

   printf("%d! = %d\n", *(int*)param, fact(*(int*)param));

   TRACEOUT("void* test_thread(void*)");
   return NULL;
}

int main()
{
   pthread_t a;
   pthread_t b;
   int x = 3;
   int y = 7;
   TRACEIN("int main()");

   pthread_create(&a, NULL, test_thread, &x);
   pthread_create(&b, NULL, test_thread, &y);
   pthread_join(a, NULL);
   pthread_join(b, NULL);

   TRACEOUT("int main()");
   return 0;
}
