#include <stdio.h>
#include "tracer/tracer.h"

int tracer_indent_g = -1;

void tracer_enter(const char* name)
{
   int i;

   tracer_indent_g++;
   for (i = 0; i < tracer_indent_g; i++)
   {
      fputs("   ", stdout);
   }
   printf("Entering %s\n", name);
}

void tracer_exit(const char* name)
{
   int i;

   for (i = 0; i < tracer_indent_g; i++)
   {
      fputs("   ", stdout);
   }
   printf("Leaving %s\n", name);
   tracer_indent_g--;
}
