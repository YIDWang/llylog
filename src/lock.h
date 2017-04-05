#ifndef _LOCK_H_
#define _LOCK_H_
#include <unistd.h>  
#include <pthread.h> 
class MyLock{
    private:
        pthread_mutex_t *mutex;
    public:
        MyLock(pthread_mutex_t *mutex):mutex(mutex){
            pthread_mutex_init(mutex, NULL);  
            pthread_mutex_lock(mutex); 
        } 
        ~MyLock(){
            pthread_mutex_unlock(mutex);
            pthread_mutex_destroy(mutex);
        }
};
#endif
