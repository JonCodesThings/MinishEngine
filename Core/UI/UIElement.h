#ifndef MINISH_UIELEMENT_H
#define MINISH_UIELEMENT_H

#include <forward_list>

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/VertexArray.hpp>

namespace sf
{
    class RenderWindow;
}

namespace minish
{
    /*!
    * \brief Abstract class used for UI.
    * \author Jonathan Duncanson
    */
    class UIElement : public sf::Drawable, public sf::Transformable
    {
        public:
            /*!
            \brief Default destructor.
            */
            ~UIElement();

            /*!
            \brief Add a child element.
            */
            void addChild(UIElement& element);

            /*!
            \brief Set the element's parent element.
            */
            void addParent(UIElement& element);

            /*!
            \brief Renders an element and all of its children.
            */
            virtual void render(sf::RenderWindow* hwnd, sf::RenderStates states=sf::RenderStates::Default);

            /*!
            \brief Sets the size of the element.
            */
            void setSize(sf::Vector2u& size);

            /*!
            \brief Removes a child from the element.
            */
            void removeChild(UIElement& element);

            /*!
            \brief Removes the parent from the element.
            */
            void removeParent();
        private:
            /*!
        	\brief SFML draw function.
        	*/
            virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

            /*!
        	\brief Stores the size of the element.
        	*/
            sf::Vector2u m_size;

            /*!
        	\brief Stores the vertices of the element.
        	*/
            sf::VertexArray m_vertices;

            /*!
        	\brief Stores a pointer to the parent of the element.
        	*/
            UIElement* m_parent = nullptr;

            /*!
        	\brief Stores a singly linked list of the element's children.
        	*/
            std::forward_list<UIElement*> m_children;
    };
}

#endif