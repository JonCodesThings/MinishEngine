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
    class UIElement : public sf::Drawable, public sf::Transformable
    {
        public:
            virtual ~UIElement();
            void addChild(UIElement& element);
            void addParent(UIElement& element);
            void render(sf::RenderWindow* hwnd, sf::RenderStates states);
            void setSize(sf::Vector2u& size);
            void removeChild(UIElement& element);
            void removeParent();
        private:
            virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

            sf::Vector2u m_size;
            sf::VertexArray m_vertices;

            UIElement* m_parent = nullptr;
            std::forward_list<UIElement*> m_children;
    };
}

#endif