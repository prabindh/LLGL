/*
 * Barrier.h
 * 
 * This file is part of the "LLGL" project (Copyright (c) 2015 by Lukas Hermanns)
 * See "LICENSE.txt" for license information.
 */

#ifndef __LLGL_BARRIER_H__
#define __LLGL_BARRIER_H__


#include <thread>
#include <mutex>
#include <condition_variable>


namespace LLGL
{


//! Barrier class to synchronize a point in a multi-threaded environment.
class Barrier
{

    public:
        
        Barrier(const Barrier&) = delete;
        Barrier& operator = (const Barrier&) = delete;

        //! Initializes the barrier to be used with the specified amount of threads.
        Barrier(std::size_t threadCount);

        /**
        \brief Blocks the current thread until all other threads reached this point.
        \remarks After all threads reached this point, this function can be used again by the threads for another barrier point.
        */
        void Wait();

    private:

        std::size_t             threadCount_    = 0;
        std::size_t             counter_        = 0;
        std::mutex              mutex_;
        std::condition_variable var_;

};


} // /namespace LLGL


#endif



// ================================================================================
