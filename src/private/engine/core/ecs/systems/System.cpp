/**
 * All rights reserved.
 * License: see LICENSE.txt
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 1. Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must display the names 'Denis Zyamaev' and
 * in the credits of the application, if such credits exist.
 * The authors of this work must be notified via email (code4un@yandex.ru) in
 * this case of redistribution.
 * 3. Neither the name of copyright holders nor the names of its contributors
 * may be used to endorse or promote products derived from this software
 * without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ``AS
 * IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL COPYRIGHT HOLDERS OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 **/

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// INCLUDES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// HEADER
#ifndef C0DE4UN_ENGINE_ECS_SYSTEM_HPP
#include "../../../../../public/engine/core/ecs/systems/System.hpp"
#endif // !C0DE4UN_ENGINE_ECS_SYSTEM_HPP

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// c0de4un::engine::ecs::System
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

namespace c0de4un
{

    namespace engine
    {

        namespace ecs
        {

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // CONSTRUCTOR & DESTRUCTOR
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            System::System()
                : mStateMutex(),
                mCurrentState( System::SYSTEM_STATE_NOT_STARTED )
            {
            }

            System::~System() noexcept
            {
                Stop();
            }

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // GETTERS & SETTERS
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            bool System::isStarted() const noexcept
            {
                engine_lock lock( mStateMutex );
                return mCurrentState > SYSTEM_STATE_NOT_STARTED && mCurrentState < SYSTEM_STATE_STOPPED;
            }

            bool System::isPaused() const noexcept
            {
                engine_lock lock( mStateMutex );
                return mCurrentState > SYSTEM_STATE_STARTED && mCurrentState != SYSTEM_STATE_RESUMING;
            }

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // METHODS
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            bool System::onStart()
            {
                return true;
            }

            bool System::onResume()
            {
                return true;
            }

            void System::onPause() noexcept
            {
            }

            void System::onStop() noexcept
            {
            }

            bool System::Start()
            {
                int result( 0 );

                engine_lock stateLock( mStateMutex );

                if ( mCurrentState == SYSTEM_STATE_NOT_STARTED || mCurrentState == SYSTEM_STATE_STOPPED )
                {
                    mCurrentState = SYSTEM_STATE_STARTING;
                    stateLock.unlock();

                    result = onStart();
                }
                else if ( mCurrentState == SYSTEM_STATE_PAUSED )
                {
                    mCurrentState = SYSTEM_STATE_RESUMING;
                    stateLock.unlock();

                    result = onResume();

                    stateLock.lock();
                    mCurrentState = result == 0 ? SYSTEM_STATE_STARTED : SYSTEM_STATE_NOT_STARTED;
                }

                return result;
            }

            void System::Pause()
            {
                engine_lock stateLock( mStateMutex );

                if ( mCurrentState > SYSTEM_STATE_STARTED && mCurrentState < SYSTEM_STATE_PAUSING )
                {
                    mCurrentState = SYSTEM_STATE_PAUSING;
                    stateLock.unlock();

                    onPause();

                    stateLock.lock();
                    mCurrentState = SYSTEM_STATE_PAUSED;
                }
            }

            void System::Stop()
            {
                engine_lock stateLock( mStateMutex );

                if ( mCurrentState > SYSTEM_STATE_NOT_STARTED
                    && mCurrentState < SYSTEM_STATE_STOPPING )
                    {
                        mCurrentState = SYSTEM_STATE_STOPPING;
                        stateLock.unlock();

                        onStop();

                        stateLock.lock();
                        mCurrentState = SYSTEM_STATE_STOPPED;
                    }
            }

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        }

    }

}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
