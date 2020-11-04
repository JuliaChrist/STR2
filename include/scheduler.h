#ifndef __scheduler_h
#define __scheduler_h

#include <utility/queue.h>
#include <cpu.h>
#include <machine.h>
#include <utility/list.h>
//#include <thread.h>
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

__BEGIN_UTIL


template<typename T, typename P = typename T::Priority>
class Scheduler: public Scheduling_List<T, P>
{

protected:
    typedef Scheduling_List<T, P> Base;

public:
    Scheduler() {};
    //--------------------//
    void insert(T * obj){
        Base::insert(obj->link());
    }
    //--------------------//
    T * remove(T * obj){
        Base::remove(obj->link());
        return(obj);
    }
    //--------------------//
    void resume(T * obj){
        Base::insert(obj->link());
    }
    //--------------------//
    void suspend(T * obj){
        Base::remove(obj->link());
    }
    //--------------------//
    T * volatile chosen() {
        return const_cast<T * volatile>((Base::chosen()) ? Base::chosen()->object() : 0);
    }
    //--------------------//
    T * choose() {
        T * obj = Base::chosen() ? Base::choose()->object() : 0;
        return obj;
    }
    //--------------------//
    T * choose(T * obj) {
        if(!Base::choose(obj->link()))
            obj = 0;
        return obj;
    }
    //--------------------//
    T * choose_another() {
        T * obj = Base::choose_another()->object();
        return obj;
    }
    //--------------------//
    T * remove(){
    auto *aaa = Base::choose();
    if(aaa != 0){
        Base::remove(aaa);
        return aaa->object();
    }
    else{
        return(0);
    }
    }


};
__END_UTIL

#endif
