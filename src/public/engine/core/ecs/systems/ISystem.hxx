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

#ifndef C0DE4UN_ENGINE_ECS_I_SYSTEM_HXX
#define C0DE4UN_ENGINE_ECS_I_SYSTEM_HXX

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

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
            // c0de4un::engine::ecs::ISystem
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            /**
             * @brief
             * ISystem - System contract
             *
             * @version 1.0
            **/
            class ISystem
            {

            public:

                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                // DESTRUCTOR
                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

                virtual ~ISystem() noexcept = default;

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
                virtual bool isStarted() const noexcept = 0;

                /**
                 * @brief
                 * Returns 'true' if System is Paused.
                 *
                 * @thread_safety - thread-locks or atomics are used.
                 * @throws - no exceptions.
                **/
                virtual bool isPaused() const noexcept = 0;

                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                // METHODS
                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

                /**
                 * @brief
                 * Start/Resume System
                 *
                 * @thread_safety - thread-locks used
                 * @throws - can throw exception
                 * @return - 'true' of OK
                **/
                virtual bool Start() = 0;

                /**
                 * @brief
                 * Pause System
                 *
                 * @thread_safety - thread-locks used
                 * @throws - can throw exception
                **/
                virtual void Pause() = 0;

                /**
                 * @brief
                 * Stop/Terminate System
                 *
                 * @thread_safety - thread-locks used
                 * @throws - can throw exception
                **/
                virtual void Stop() = 0;

                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            }; /// c0de4un::engine::ecs::ISystem

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        } /// c0de4un::engine::ecs

    } /// c0de4un::engine

} /// c0de4un

using ecs_ISystem = c0de4un::engine::ecs::ISystem;
#define C0DE4UN_ENGINE_ECS_I_SYSTEM_DECL

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

#endif // !C0DE4UN_ENGINE_ECS_I_SYSTEM_HXX
