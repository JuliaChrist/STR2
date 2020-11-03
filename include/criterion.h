#ifndef _CRITERION_
#define _CRITERION_

#include <periodic_thread.h>
#include <scheduler.h>



class EDF:Scheduler {
	//método de critério dinâmico

	friend class Periodic_Thread;
	friend class Scheduler;
	
	public:


		//reescrever insert e pipipipopopo
		//acho que nem precisa da ordena_scheduler

		void ordena_scheduler(/*thread*/){

			//percorrendo o scheduler
			//acessar thread->tempo_restante
			//algoritimo de ordenação???? OU toda vez que inserir uma thread no escalonador,
			//colocá-la na sua respectiva posição



			//acessa o TEMPO RESTANTE PARA A FINALIZAÇÃO DA THREAD da thread e ordena o escalonador de acordo com o menor tempo
			//escalonador: prioridade mais alta na cabeça da lista


		}

	private:

};


class RM:Scheduler {
	//método de critério estático
	friend class Periodic_Thread;
	friend class Scheduler;

	public:

		void ordena_scheduler(/*thread*/){

			//acessa o TEMPO DE CICLO da thread e ordena o escalonador de acordo com o menor tempo
			//escalonador: prioridade mais alta na cabeça da lista


		}

	private:


	
};


#endif