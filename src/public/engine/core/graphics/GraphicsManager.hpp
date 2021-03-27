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

#ifndef C0DE4UN_ENGINE_CORE_GRAPHICS_MANAGER_HPP
#define C0DE4UN_ENGINE_CORE_GRAPHICS_MANAGER_HPP

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// INCLUDES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// Include memory
#ifndef C0DE4UN_ENGINE_CFG_MEMORY_HPP
#include "../../cfg/memory.hpp"
#endif // !C0DE4UN_ENGINE_CFG_MEMORY_HPP

// Include mutex
#ifndef C0DE4UN_ENGINE_CFG_MUTEX_HPP
#include "../../cfg/mutex.hpp"
#endif // !C0DE4UN_ENGINE_CFG_MUTEX_HPP

// Include c0de4un::engine::ecs::ISystem
#ifndef C0DE4UN_ENGINE_ECS_SYSTEM_HPP
#include "../../../../public/engine/core/ecs/systems/System.hpp"
#endif // !C0DE4UN_ENGINE_ECS_SYSTEM_HPP

// Include c0de4un::engine::core::IGraphicsManager
#ifndef C0DE4UN_ENGINE_CORE_I_GRAPHICS_MANAGER_HXX
#include "../../../../public/engine/core/graphics/IGraphicsManager.hxx"
#endif // !C0DE4UN_ENGINE_CORE_I_GRAPHICS_MANAGER_HXX

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
            // c0de4un::engine::core::GraphicsManager
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            /**
             * @brief
             * GraphicsManager - graphics API
             *
             * @version 1.0
            **/
            class GraphicsManager : public ecs_System, public engine_IGraphics
            {

            private:

                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                // FIELDS
                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

                static GraphicsManager* mInstance;

                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            protected:

                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                // CONSTRUCTOR
                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

                explicit GraphicsManager() noexcept;

                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                // DELETED
                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

                GraphicsManager( const GraphicsManager& ) = delete;
                GraphicsManager& operator=( const GraphicsManager& ) = delete;
                GraphicsManager( GraphicsManager&& ) = delete;
                GraphicsManager& operator=(GraphicsManager&&) = delete;

                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            public:

                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                // DESTRUCTOR
                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

                virtual ~GraphicsManager() noexcept;

                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                // GETTERS & SETTERS
                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

                /**
                 * @brief
                 * Returns GraphicsManager instance
                 * 
                 * @thread_safety - not required
                 * @throws - no exceptions
                **/
                static GraphicsManager* getInstance() noexcept;

                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                // METHODS
                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

                /**
                 * @brief
                 * Sets IGraphics instance to use
                 *
                 * @param pInstance
                 * @throws - no exceptions
                **/
                static void Initialize( GraphicsManager* const pInstance ) noexcept;

                /**
                 * @brief
                 * Terminates IGraphics instance
                 *
                 * @throws - no exceptions
                **/
                static void Terminate() noexcept;

                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            }; /// c0de4un::engine::core::GraphicsManager

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        } /// c0de4un::engine::core

    } /// c0de4un::engine

} /// c0de4un

using engine_Graphics = c0de4un::engine::core::GraphicsManager;
#define C0DE4UN_ENGINE_CORE_GRAPHICS_MANAGER_DECL

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

#endif // !C0DE4UN_ENGINE_CORE_GRAPHICS_MANAGER_HPP
