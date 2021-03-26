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

#ifndef C0DE4UN_ENGINE_CORE_LOG_HPP
#define C0DE4UN_ENGINE_CORE_LOG_HPP

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// INCLUDES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// FORWARD-DECLARATIONS
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// c0de4un::engine::core::ILogger
#ifndef C0DE4UN_ENGINE_CORE_I_LOGGER_DECL
#define C0DE4UN_ENGINE_CORE_I_LOGGER_DECL
namespace c0de4un { namespace engine { namespace core { class ILogger; } } }
using enigne_ILogger = c0de4un::engine::core::ILogger;
#endif // !C0DE4UN_ENGINE_CORE_I_LOGGER_DECL

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// TYPES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

namespace c0de4un
{

    namespace engine
    {

        namespace core
        {

            /**
             * @brief
             * Log - decorator-class for logging api
             *
             * @version 1.0
            **/
            class Log
            {

            private:

                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                // FIELDS
                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

                static enigne_ILogger* mInstance;

                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                // CONSTRUCTOR
                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

                explicit Log() noexcept;

                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                // DELETED
                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

                Log( const Log& ) = delete;
                Log& operator=( const Log& ) = delete;
                Log( Log&& ) = delete;
                Log& operator=(Log&&) = delete;

                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            public:

                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                // DESTRUCTOR
                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

                ~Log() noexcept;

                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                // METHODS
                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

                /**
                 * @brief
                 * Initialize Log instance
                 *
                 * @param pInstance - ILogger implementation to use
                 *
                 * @throws - no exceptions
                **/
                static void Initialize( enigne_ILogger* const pInstance );

                /**
                 * @brief
                 * Terminate log isntance
                 *
                 * @throws - no exceptions
                **/
                static void Terminate() noexcept;

                /**
                 * @brief
                 * Prints INFO-level message
                 *
                 * @param pMessage - message in c-string
                **/
                static void info( const char* const pMessage ) noexcept;

                /**
                 * @brief
                 * Prints DEBUG-level message
                 *
                 * @param pMessage - message in c-string
                **/
                static void debug( const char* const pMessage ) noexcept;

                /**
                 * @brief
                 * Prints WARNING-level message
                 *
                 * @param pMessage - message in c-string
                **/
                static void warning( const char* const pMessage ) noexcept;

                /**
                 * @brief
                 * Prints ERROR-level message
                 *
                 * @param pMessage - message in c-string
                **/
                static void error( const char* const pMessage ) noexcept;

                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            }; /// Log

        }

    }

}

using engine_Log = c0de4un::engine::core::Log;

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

#endif // !C0DE4UN_ENGINE_CORE_LOG_HPP
