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
#ifndef C0DE4UN_ENGINE_WIN_GRAPHICS_HPP
#include "../../../../public/engine/windows/graphics/WinGraphics.hpp"
#endif // !C0DE4UN_ENGINE_WIN_GRAPHICS_HPP

// DEBUG
#ifdef DEBUG

// Include c0de4un::engine::core::Log
#ifndef C0DE4UN_ENGINE_CORE_LOG_HPP
#include "../../../../public/engine/core/utils/metrics/Log.hpp"
#endif // !C0DE4UN_ENGINE_CORE_LOG_HPP

// Include STL string
#include <string>

#endif
// DEBUG

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// c0de4un::engine::core::WinGraphics
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

namespace c0de4un
{

    namespace engine
    {

        namespace win
        {

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // CONSTRUCTOR & DESTRUCTOR
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            WinGraphics::WinGraphics()
                : GraphicsManager(),
                mGLFWWindow(nullptr),
                mSurfaceWidth(0),
                mSurfaceHeight(0)
            {
            }

            WinGraphics::~WinGraphics() noexcept = default;

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // METHODS
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            void WinGraphics::mainLoop() noexcept
            {
#ifdef DEBUG // DEBUG
                engine_Log::info( "WinGraphics::mainLoop > > >" );
#endif // DEBUG

                while( !glfwWindowShouldClose(mGLFWWindow) )
                {
                    glClear(GL_COLOR_BUFFER_BIT);

                    glViewport( 0, 0, mSurfaceWidth, mSurfaceHeight );

                    glfwSwapBuffers(mGLFWWindow);

                    glfwPollEvents();
                }

#ifdef DEBUG // DEBUG
                engine_Log::info( "WinGraphics::mainLoop < < <" );
#endif // DEBUG
            }

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // OVERRIDE: System
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            bool WinGraphics::onStart()
            {
#ifdef DEBUG // DEBUG
                engine_Log::info( "WinGraphics::onStart > > >" );
#endif // DEBUG

                // Guarded-Block
                try
                {
                    // Initialize GLFW
                    if ( !glfwInit() )
                    {
#ifdef DEBUG // DEBUG
                        engine_Log::error( "WinGraphics::onStart: failed to initialize GLFW instance" );
#endif // DEBUG

                        return false;
                    }

                    // Create Window
                    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
                    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
                    mGLFWWindow = glfwCreateWindow(640, 480, "Hello OpenGL", nullptr, nullptr);
                    if ( !mGLFWWindow )
                    {
#ifdef DEBUG // DEBUG
                        engine_Log::error( "WinGraphics::onStart: failed to create GLFW-Window " );
#endif // DEBUG

                        glfwTerminate();

                        return false;
                    }

                    // Bind Render Context to Window
                    glfwMakeContextCurrent(mGLFWWindow);

                    // Get OpenGL Surface Width & Height
                    glfwGetFramebufferSize(mGLFWWindow, &mSurfaceWidth, &mSurfaceHeight);

                    // Init GLAD
                    gladLoadGL();

                    // Main Loop
                    mainLoop();
                }
                catch ( const std::exception& pException )
                {
#ifdef DEBUG // DEBUG
                    std::string errMsg( "WinGraphics::onStart: ERROR: " );
                    errMsg += pException.what();
                    engine_Log::error( errMsg.c_str() );
#endif // DEBUG
                    return false;
                }

#ifdef DEBUG // DEBUG
                engine_Log::info( "WinGraphics::onStart < < <" );
#endif // DEBUG

                return true;
            }

            bool WinGraphics::onResume()
            { return true; }

            void WinGraphics::onPause() noexcept {}

            void WinGraphics::onStop() noexcept
            {
#ifdef DEBUG // DEBUG
                engine_Log::info( "WinGraphics::onStop > > >" );
#endif // DEBUG

                // Guarded-Block
                try
                {
                    if ( mGLFWWindow )
                        glfwDestroyWindow(mGLFWWindow);

                    glfwTerminate();
                    mGLFWWindow = nullptr;
                }
                catch ( const std::exception& pException )
                {
#ifdef DEBUG // DEBUG
                    std::string errMsg( "WinGraphics::onStop: ERROR: " );
                    errMsg += pException.what();
                    engine_Log::error( errMsg.c_str() );
#endif // DEBUG
                }

#ifdef DEBUG // DEBUG
                engine_Log::info( "WinGraphics::onStop < < <" );
#endif // DEBUG
            }

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        }

    }

}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
