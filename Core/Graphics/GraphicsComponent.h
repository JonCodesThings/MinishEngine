#ifndef MINISH_GRAPHICSCOMPONENT_H
#define MINISH_GRAPHICSCOMPONENT_H

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transform.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/System/Vector2.hpp>

#include "Core/Entity/Component.h"
#include "Core/Graphics/Frame.h"
#include "Core/Physics/AABB.h"

namespace minish
{
    /*!
    * \brief Class for graphical representations of entities.
    * \author Jonathan Duncanson
    */
    class GraphicsComponent : public Component, public sf::Drawable
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

            const sf::Color& getColor() const;

            const sf::Vector2u& getSize() const;

            const sf::Texture* getTexture() const;

            const sf::IntRect& getTextureRect() const;

            /*!
        	\brief Class method that pauses the animation and puts it back to the first frame.
        	*/
            virtual void render(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates::Default);

            /*!
        	\brief Class method that sets the color of the component.
        	*/
            void setColor(const sf::Color& color);

            /*!
        	\brief Sets the size of the graphics component on screen.
        	*/
            void setSize(const sf::Vector2u& size);

            /*!
        	\brief Sets the texture of the graphics component.
        	*/
            void setTexture(const sf::Texture& texture);

            /*!
        	\brief Sets the texture rect of the graphics component.
        	*/
            void setTextureRect(const sf::IntRect& texture_rect);
        private:
            /*!
            \brief Override of base Component setEntity member function. Registers the component's data with the entity.
            */
            virtual void setEntity(Entity& entity);

            /*!
        	\brief SFML draw function.
        	*/
            virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

            /*!
        	\brief Flag to determine if VertexArray needs updating.
        	*/
            bool m_vertex_update_flag;

            /*!
        	\brief Pointer to the component's texture.
        	*/
            const sf::Texture* m_texture;

            /*!
            \brief The color of the component.
            */
            sf::Color m_color;

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