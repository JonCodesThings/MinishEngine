#ifndef MINISH_GRAPHICSCOMPONENT_H
#define MINISH_GRAPHICSCOMPONENT_H

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/System/Vector2.hpp>

#include "Core/Entity/Component.h"
#include "Core/Physics/AABB.h"

namespace minish
{
    /*!
    * \brief Class for graphical representations of entities.
    * \author Jonathan Duncanson
    */
    class GraphicsComponent : public Component, public sf::Drawable, public sf::Transformable
    {
        public:
            /*!
        	\brief Default constructor.
        	*/
            GraphicsComponent();

            /*!
        	\brief Constructor that initializes the component's texture, texture rect and size.
        	*/
            GraphicsComponent(sf::Texture& texture, sf::IntRect& texture_rect, sf::Vector2u& size);

            virtual ~GraphicsComponent() {};

            /*!
        	\brief Class method that pauses the animation and puts it back to the first frame.
        	*/
            virtual void render(sf::RenderTarget& target);

            /*!
        	\brief Sets the size of the graphics component on screen.
        	*/
            void setSize(sf::Vector2u& size);

            /*!
        	\brief Sets the texture of the graphics component.
        	*/
            void setTexture(sf::Texture& texture);

            /*!
        	\brief Sets the texture rect of the graphics component.
        	*/
            void setTextureRect(sf::IntRect& texture_rect);

            /*!
        	\brief Updates the graphics component.
        	*/
            virtual void update(const float dt);
        private:
            /*!
        	\brief SFML draw function.
        	*/
            virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

            /*!
        	\brief Flag to determine if VertexArray needs updating.
        	*/
            bool m_update_flag;

            /*!
        	\brief Pointer to the component's texture.
        	*/
            sf::Texture* m_texture;

            /*!
        	\brief The texture rect of the component.
        	*/
            sf::IntRect m_texture_rect;

            /*!
        	\brief The size of the component.
        	*/
            sf::Vector2u m_size;

            /*!
        	\brief The component's vertex array.
        	*/
            sf::VertexArray m_vertices;
    };
}

#endif