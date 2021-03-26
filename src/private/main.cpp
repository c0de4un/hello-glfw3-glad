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

// Include STL
#include <iostream>
#include <string>
#include <cstdio>

// Include Windows SDK
#include <Windows.h>

// GLFW & GLAD
#include "../../libs/glad/include/gl.h"
#include <GLFW/glfw3.h>

// c0de4un::engine::core::Log
#ifndef C0DE4UN_ENGINE_CORE_LOG_HPP
#include "../public/engine/core/utils/metrics/Log.hpp"
#endif // !C0DE4UN_ENGINE_CORE_LOG_HPP

// Include c0de4un::engine::core::DefaultEngine
#ifndef C0DE4UN_ENGINE_CORE_DEFAULT_LOGGER_HPP
#include "../public/engine/core/utils/metrics/DefaultLogger.hpp"
#endif // !C0DE4UN_ENGINE_CORE_DEFAULT_LOGGER_HPP

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// TYPES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

#ifndef OK
    static constexpr const int OK = 0;
    #define OK OK
#endif

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// MAIN
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

bool start()
{
    engine_Log::Initialize( new engine_DefaultLogger() );

    // Guarded-Block
    try
    {
        // Initialize GLFW
        if ( !glfwInit() )
        {
#ifdef DEBUG // DEBUG
            engine_Log::error( "main::start: failed to initialize GLFW instance" );
#endif // DEBUG

            return false;
        }
    }
    catch(const std::exception& e)
    {
#ifdef DEBUG // DEBUG
        engine_Log::error( e.what() );
#endif // DEBUG

        return false;
    }

    return true;
}

void stop()
{
    // Guarded-Block
    try
    {
        // Terminate GLFW
        glfwTerminate();
    }
    catch(const std::exception& e)
    {
#ifdef DEBUG // DEBUG
        engine_Log::error( e.what() );
#endif // DEBUG
    }

    engine_Log::Terminate();
}

int main()
{
#ifdef DEBUG // DEBUG
    std::cout << "Starting . . ." << std::endl;
#endif // DEBUG

    // Set console code page to UTF-8 so console known how to interpret string data
    SetConsoleOutputCP( CP_UTF8 );

    // Enable buffering to prevent VS from chopping up UTF-8 byte sequences
    setvbuf( stdout, nullptr, _IOFBF, 1000 );

    if ( !start() )
    {
#ifdef DEBUG // DEBUG
        std::cout << "ERORR" << std::endl << "Press any key to exit" << std::endl;
        std::cin.get();
#endif // DEBUG
    }

    stop();

#ifdef DEBUG // DEBUG
    std::cout << "Completed . . ." << std::endl << "Press any key to exit" << std::endl;
    std::cin.get();
#endif // DEBUG

    return OK;
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
