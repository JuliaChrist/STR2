#ifndef __scheduler_h
#define __scheduler_h

#include <utility/queue.h>
#include <cpu.h>
#include <machine.h>

/*
 * insert(obj: List_Link<T>)
 * remove(obj: List_Link<T>): T
 * resume(obj: List_Link<T>)
 * suspend(obj: List_Link<T>)
 * chosen(): T
 * choose(): T
 * choose_another(): T
 * 
 */

__BEGIN_SYS

template<typename T, typename P = typename T::Priority>
class Scheduler: public Scheduling_List<T, P>
{

protected:
    typedef Scheduling_List<T, P> Base;

public:

    Scheduler() {};
    
    void insert(T * obj){
        Base::insert(obj->link());
    }
    
    T * remove(T * obj){
        Base::remove(obj);
        return(obj);
    }
    
    T * remove(){
        return(Base::remove()->object());
    }

    void suspend(T * obj){
        Base::remove(obj->link());
    }

    void resume(T * obj){
        Base::insert(obj->link());
    }

};
__END_SYS

#endif
