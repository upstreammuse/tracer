#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include "tracer/tracer.h"

pthread_key_t tracer_indent_key_g;
pthread_once_t tracer_once_g = PTHREAD_ONCE_INIT;

void tracer_indent_destructor(void* v)
{
   free(v);
}

void tracer_init()
{
   pthread_key_create(&tracer_indent_key_g, tracer_indent_destructor);
}

void tracer_enter(const char* name)
{
   int i;
   int* indent;

   pthread_once(&tracer_once_g, tracer_init);
   indent = (int*)pthread_getspecific(tracer_indent_key_g);
   if (indent == NULL)
   {
      indent = (int*)malloc(sizeof (int));
      *indent = -1;
   }
   (*indent)++;
   for (i = 0; i < *indent; i++)
   {
      fputs("   ", stdout);
   }
   printf("(%lu) Entering %s\n", pthread_self(), name);
   pthread_setspecific(tracer_indent_key_g, indent);
}

void tracer_exit(const char* name)
{
   int i;
   int* indent;

   indent = (int*)pthread_getspecific(tracer_indent_key_g);
   for (i = 0; i < *indent; i++)
   {
      fputs("   ", stdout);
   }
   printf("(%lu) Leaving %s\n", pthread_self(), name);
   (*indent)--;
   pthread_setspecific(tracer_indent_key_g, indent);
}
