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

void* test_thread(void* param)
{
   TRACE("void* test_thread(void*)");

   std::cout << *(int*)param << "! = " << fact(*(int*)param) << std::endl;

   return NULL;
}

int main()
{
   TRACE("int main()");

   pthread_t a;
   int x(3);
   pthread_create(&a, NULL, test_thread, &x);
   pthread_t b;
   int y(7);
   pthread_create(&b, NULL, test_thread, &y);
   pthread_join(a, NULL);
   pthread_join(b, NULL);

   return 0;
}
