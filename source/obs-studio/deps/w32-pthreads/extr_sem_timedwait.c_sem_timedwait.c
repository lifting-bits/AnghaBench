#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct timespec {int dummy; } ;
struct TYPE_4__ {int* resultPtr; TYPE_2__* sem; } ;
typedef  TYPE_1__ sem_timedwait_cleanup_args_t ;
typedef  TYPE_2__* sem_t ;
struct TYPE_5__ {int value; scalar_t__ leftToUnblock; int /*<<< orphan*/  lock; int /*<<< orphan*/  sem; } ;
typedef  int /*<<< orphan*/  DWORD ;

/* Variables and functions */
 void* EINVAL ; 
 int /*<<< orphan*/  INFINITE ; 
 int /*<<< orphan*/  SetEvent (int /*<<< orphan*/ ) ; 
 int errno ; 
 int pthreadCancelableTimedWait (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pthread_cleanup_pop (int) ; 
 int /*<<< orphan*/  pthread_cleanup_push (int /*<<< orphan*/ ,void*) ; 
 int pthread_mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pthread_mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pthread_testcancel () ; 
 int /*<<< orphan*/  ptw32_relmillisecs (struct timespec const*) ; 
 int /*<<< orphan*/  ptw32_sem_timedwait_cleanup ; 

int
sem_timedwait (sem_t * sem, const struct timespec *abstime)
     /*
      * ------------------------------------------------------
      * DOCPUBLIC
      *      This function waits on a semaphore possibly until
      *      'abstime' time.
      *
      * PARAMETERS
      *      sem
      *              pointer to an instance of sem_t
      *
      *      abstime
      *              pointer to an instance of struct timespec
      *
      * DESCRIPTION
      *      This function waits on a semaphore. If the
      *      semaphore value is greater than zero, it decreases
      *      its value by one. If the semaphore value is zero, then
      *      the calling thread (or process) is blocked until it can
      *      successfully decrease the value or until interrupted by
      *      a signal.
      *
      *      If 'abstime' is a NULL pointer then this function will
      *      block until it can successfully decrease the value or
      *      until interrupted by a signal.
      *
      * RESULTS
      *              0               successfully decreased semaphore,
      *              -1              failed, error in errno
      * ERRNO
      *              EINVAL          'sem' is not a valid semaphore,
      *              ENOSYS          semaphores are not supported,
      *              EINTR           the function was interrupted by a signal,
      *              EDEADLK         a deadlock condition was detected.
      *              ETIMEDOUT       abstime elapsed before success.
      *
      * ------------------------------------------------------
      */
{
  int result = 0;
  sem_t s = *sem;

  pthread_testcancel();

  if (sem == NULL)
    {
      result = EINVAL;
    }
  else
    {
      DWORD milliseconds;

      if (abstime == NULL)
	{
	  milliseconds = INFINITE;
	}
      else
	{
	  /* 
	   * Calculate timeout as milliseconds from current system time. 
	   */
	  milliseconds = ptw32_relmillisecs (abstime);
	}

      if ((result = pthread_mutex_lock (&s->lock)) == 0)
	{
	  int v;

	  /* See sem_destroy.c
	   */
	  if (*sem == NULL)
	    {
	      (void) pthread_mutex_unlock (&s->lock);
	      errno = EINVAL;
	      return -1;
	    }

	  v = --s->value;
	  (void) pthread_mutex_unlock (&s->lock);

	  if (v < 0)
	    {
#if defined(NEED_SEM)
	      int timedout;
#endif
	      sem_timedwait_cleanup_args_t cleanup_args;

	      cleanup_args.sem = s;
	      cleanup_args.resultPtr = &result;

#if defined(_MSC_VER) && _MSC_VER < 1400
#pragma inline_depth(0)
#endif
	      /* Must wait */
              pthread_cleanup_push(ptw32_sem_timedwait_cleanup, (void *) &cleanup_args);
#if defined(NEED_SEM)
	      timedout =
#endif
	      result = pthreadCancelableTimedWait (s->sem, milliseconds);
	      pthread_cleanup_pop(result);
#if defined(_MSC_VER) && _MSC_VER < 1400
#pragma inline_depth()
#endif

#if defined(NEED_SEM)

	      if (!timedout && pthread_mutex_lock (&s->lock) == 0)
	        {
        	  if (*sem == NULL)
        	    {
        	      (void) pthread_mutex_unlock (&s->lock);
        	      errno = EINVAL;
        	      return -1;
        	    }

	          if (s->leftToUnblock > 0)
	            {
		      --s->leftToUnblock;
		      SetEvent(s->sem);
		    }
	          (void) pthread_mutex_unlock (&s->lock);
	        }

#endif /* NEED_SEM */

	    }
	}

    }

  if (result != 0)
    {

      errno = result;
      return -1;

    }

  return 0;

}