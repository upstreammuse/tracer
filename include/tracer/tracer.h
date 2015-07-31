#ifndef TRACER_TRACER_H
#define TRACER_TRACER_H

#ifdef TRACER

#ifdef __cplusplus
extern "C" void tracer_enter(const char* name);
extern "C" void tracer_exit(const char* name);
class tracer
{
   public:
      tracer(const char* name) : name_(name) { tracer_enter(name_); }
      virtual ~tracer() { tracer_exit(name_); }

   protected:
      const char* name_;
};
#else
void tracer_enter(const char* name);
void tracer_exit(const char* name);
#endif

#ifdef __cplusplus
#define TRACE(x) tracer _tracer(x)
#else
#define TRACEIN(x) tracer_enter(x)
#define TRACEOUT(x) tracer_exit(x)
#endif

#else

#ifdef __cplusplus
#define TRACE(x)
#else
#define TRACEIN(x)
#define TRACEOUT(x)
#endif

#endif

#endif
