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

#ifndef C0DE4UN_ENGINE_CORE_DEFAULT_LOGGER_HPP
#define C0DE4UN_ENGINE_CORE_DEFAULT_LOGGER_HPP

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// INCLUDES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// Include c0de4un::engine::core::ILogger
#ifndef C0DE4UN_ENGINE_CORE_I_LOGGER_HXX
#include "ILogger.hxx"
#endif // !C0DE4UN_ENGINE_CORE_I_LOGGER_HXX

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// TYPES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

namespace c0de4un
{

    namespace engine
    {

        namespace core
        {

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // c0de4un::engine::core::DefaultLogger
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            /**
             * @brief
             * DefaultLogger - prints console output
             *
             * @version 1.0
            **/
            class DefaultLogger final : public enigne_ILogger
            {

            private:

                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                // DELETED
                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

                DefaultLogger( const DefaultLogger& ) = delete;
                DefaultLogger& operator=( const DefaultLogger& ) = delete;
                DefaultLogger( DefaultLogger&& ) = delete;
                DefaultLogger& operator=(DefaultLogger&&) = delete;

                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            public:

                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                // CONSTRUCTOR & DESTRUCTOR
                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

                explicit DefaultLogger() noexcept;
                virtual ~DefaultLogger() noexcept;

                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                // OVERRIDE: ILogger
                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

                /**
                 * Print INFO-level message
                 *
                 * @param pMessage
                **/
                virtual void printInfo( const char* const pMessage ) noexcept final;

                /**
                 * Print DEBUG-level message
                 *
                 * @param pMessage
                **/
                virtual void printDebug( const char* const pMessage ) noexcept final;

                /**
                 * Print WARNING-level message
                 *
                 * @param pMessage
                **/
                virtual void printWarning( const char* const pMessage ) noexcept final;

                /**
                 * Print ERROR-level message
                 *
                 * @param pMessage
                **/
                virtual void printError( const char* const pMessage ) noexcept final;

                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            }; /// c0de4un::engine::core::DefaultLogger

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        } /// c0de4un::engine::core

    } /// c0de4un::engine

} /// c0de4un

using engine_DefaultLogger = c0de4un::engine::core::DefaultLogger;

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

#endif // !C0DE4UN_ENGINE_CORE_DEFAULT_LOGGER_HPP
