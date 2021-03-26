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

#ifndef C0DE4UN_ENGINE_ECS_SYSTEM_HPP
#define C0DE4UN_ENGINE_ECS_SYSTEM_HPP

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// INCLUDES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// Include mutex
#ifndef C0DE4UN_ENGINE_CFG_MUTEX_HPP
#include "../../../cfg/mutex.hpp"
#endif // !C0DE4UN_ENGINE_CFG_MUTEX_HPP

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// TYPES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

namespace c0de4un
{

    namespace engine
    {

        namespace ecs
        {

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // c0de4un::engine::ecs::System
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            /**
             * @brief
             * System - base System class
             *
             * @version 1.0
            **/
            class System
            {

            private:

                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                // TYPES
                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

                using system_state_t = unsigned char;

                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                // CONSTANTS
                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

                static constexpr const system_state_t SYSTEM_STATE_NOT_STARTED = 0;
                static constexpr const system_state_t SYSTEM_STATE_STARTING    = 1;
                static constexpr const system_state_t SYSTEM_STATE_STARTED     = 2;
                static constexpr const system_state_t SYSTEM_STATE_PAUSING     = 3;
                static constexpr const system_state_t SYSTEM_STATE_PAUSED      = 4;
                static constexpr const system_state_t SYSTEM_STATE_RESUMING    = 5;
                static constexpr const system_state_t SYSTEM_STATE_STOPPING    = 6;
                static constexpr const system_state_t SYSTEM_STATE_STOPPED     = 7;

                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                // FIELDS
                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

                mutable engine_mutex mStateMutex;
                mutable system_state_t mCurrentState;

                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            protected:

                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                // CONSTRUCTOR
                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

                explicit System();

                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                // DELETED
                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

                System( const System& ) = delete;
                System& operator=( const System& ) = delete;
                System( System&& ) = delete;
                System& operator=(System&&) = delete;

                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                // METHODS
                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

                /**
                 * @brief
                 * Called to Start.
                 *
                 * @thread_safety - thread-lock used
                 * @throws - can throw exception
                 * @return - 'true' of OK
                **/
                virtual bool onStart() = 0;

                /**
                 * @brief
                 * Called to Resume.
                 *
                 * @thread_safety - thread-lock used
                 * @throws - can throw exception
                 * @return - 'true' if OK
                **/
                virtual bool onResume() = 0;

                /**
                 * @brief
                 * Called to Pause.
                 *
                 * @thread_safety - thread-lock used
                 * @throws - no exceptions.
                **/
                virtual void onPause() noexcept = 0;

                /**
                 * @brief
                 * Called to Stop.
                 *
                 * @thread_safety - thread-lock used
                 * @throws - no exceptions.
                **/
                virtual void onStop() noexcept = 0;

                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            public:

                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                // DESTRUCTOR
                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

                virtual ~System() noexcept;

                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                // GETTERS & SETTERS
                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

                /**
                 * @brief
                 * Returns 'true' if System is Started (initialized).
                 *
                 * @thread_safety - thread-locks or atomics are used.
                 * @throws - no exceptions.
                **/
                virtual bool isStarted() const noexcept final;

                /**
                 * @brief
                 * Returns 'true' if System is Paused.
                 *
                 * @thread_safety - thread-locks or atomics are used.
                 * @throws - no exceptions.
                **/
                virtual bool isPaused() const noexcept final;

                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                // METHODS
                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

                /**
                 * @brief
                 * Start/Resume System
                 *
                 * @thread_safety - thread-locks used
                 * @throws - can throw exception
                **/
                virtual bool Start() final;

                /**
                 * @brief
                 * Pause System
                 *
                 * @thread_safety - thread-locks used
                 * @throws - can throw exception
                **/
                virtual void Pause() final;

                /**
                 * @brief
                 * Stop/Terminate System
                 *
                 * @thread_safety - thread-locks used
                 * @throws - can throw exception
                **/
                virtual void Stop() final;

                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            }; /// c0de4un::engine::ecs::ISystem

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        } /// c0de4un::engine::ecs

    } /// c0de4un::engine

} /// c0de4un

using ecs_System = c0de4un::engine::ecs::System;
#define C0DE4UN_ENGINE_ECS_SYSTEM_DECL

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

#endif // !C0DE4UN_ENGINE_ECS_SYSTEM_HPP
