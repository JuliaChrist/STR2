#ifndef __PERIODIC_THREAD_H__
#define __PERIODIC_THREAD_H__

#include <thread.h>
#include <alarm.h>
#include <synchronizer.h>
#include <chronometer.h>
#include <scheduler.h>
#include <semaphore.h>

__BEGIN_SYS

class Periodic_Thread: public Thread{

	friend class Semaphore;
	friend class Thread;
	friend class Alarm;

//&func, period, deadline, comp_time, iterations
public:

	template<typename ... Tn>
	Periodic_Thread(int (* entry)(Tn ...), const int period, const int iterations,Tn ... an)
			: Thread(Configuration(SUSPENDED, period),entry,an ...), _semaphore(0), _handler(&_semaphore,this), 
			  _alarm(period, &_handler, iterations){}


	static void wait_next(){
		//sleep
		reinterpret_cast<Periodic_Thread*>(Thread::running())->_semaphore.p();
		//wakeup no handler (timer)
	}


private:
	Semaphore _semaphore;
	Semaphore_Handler _handler;
	Alarm _alarm;
	// int * funcao = &func;
	// Microsecond _runtime;
	// Microsecond _deadline;
	// Microsecond _period;

	// unsigned int _iterations;

	// Microsecond tempo_atual;
	// Microsecond tempo_prox;

};

__END_SYS

#endif