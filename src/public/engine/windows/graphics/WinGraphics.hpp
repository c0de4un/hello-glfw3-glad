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

#ifndef C0DE4UN_ENGINE_WIN_GRAPHICS_HPP
#define C0DE4UN_ENGINE_WIN_GRAPHICS_HPP

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// INCLUDES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// Include c0de4un::engine::core::GraphicsManager
#ifndef C0DE4UN_ENGINE_CORE_GRAPHICS_MANAGER_HPP
#include "../../core/graphics/GraphicsManager.hpp"
#endif // !C0DE4UN_ENGINE_CORE_GRAPHICS_MANAGER_HPP

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// TYPES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

namespace c0de4un
{

    namespace engine
    {

        namespace win
        {

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // c0de4un::engine::core::WinGraphics
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            /**
             * @brief
             * WinGraphics - Windows Graphics Manager
             *
             * @version 1.0
            **/
            class WinGraphics final : public engine_Graphics
            {

            protected:

                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                // DELETED
                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

                WinGraphics( const WinGraphics& ) = delete;
                WinGraphics& operator=( const WinGraphics& ) = delete;
                WinGraphics( WinGraphics&& ) = delete;
                WinGraphics& operator=(WinGraphics&&) = delete;

                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                // OVERRIDE: System
                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

                /**
                 * @brief
                 * Called to Start.
                 *
                 * @thread_safety - thread-lock used
                 * @throws - can throw exception
                 * @return - 'true' of OK
                **/
                virtual bool onStart() final;

                /**
                 * @brief
                 * Called to Resume.
                 *
                 * @thread_safety - thread-lock used
                 * @throws - can throw exception
                 * @return - 'true' if OK
                **/
                virtual bool onResume() final;

                /**
                 * @brief
                 * Called to Pause.
                 *
                 * @thread_safety - thread-lock used
                 * @throws - no exceptions.
                **/
                virtual void onPause() noexcept final;

                /**
                 * @brief
                 * Called to Stop.
                 *
                 * @thread_safety - thread-lock used
                 * @throws - no exceptions.
                **/
                virtual void onStop() noexcept final;

                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            public:

                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                // CONSTRUCTOR & DESTRUCTOR
                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

                explicit WinGraphics();

                virtual ~WinGraphics() noexcept;

                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                // GETTERS & SETTERS
                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                // METHODS
                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            }; /// c0de4un::engine::core::WinGraphics

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        } /// c0de4un::engine::core

    } /// c0de4un::engine

} /// c0de4un

using engine_WinGraphics = c0de4un::engine::win::WinGraphics;
#define C0DE4UN_ENGINE_WIN_GRAPHICS_DECL

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

#endif // !C0DE4UN_ENGINE_WIN_GRAPHICS_HPP
