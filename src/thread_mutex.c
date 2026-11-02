#include "thread_mutex.h"


void   thread_mutex_init( struct thread_mutex *m)
{
   mulle_thread_mutex_init( &m->native_mutex_);
}


int   thread_mutex_finish_initialization( struct thread_mutex *m)
{
   (void) m;
   return( 0);
}


void   thread_mutex_cleanup( struct thread_mutex *m)
{
   mulle_thread_mutex_done( &m->native_mutex_);
}


void   thread_mutex_enter( struct thread_mutex *m)
{
   mulle_thread_mutex_lock( &m->native_mutex_);
}


void   thread_mutex_leave( struct thread_mutex *m)
{
   mulle_thread_mutex_unlock( &m->native_mutex_);
}
