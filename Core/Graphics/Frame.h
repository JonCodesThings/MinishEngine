#ifndef MINISH_FRAME_H
#define MINISH_FRAME_H

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics/View.hpp>

namespace minish
{
    class Frame : public sf::Drawable, public sf::Transformable
    {
        public:
            Frame();
            ~Frame();
            void deinit();
            void blit(const sf::Drawable& drawable, const sf::RenderStates states=sf::RenderStates::Default);
            const sf::RenderTarget& getRenderTarget();
            const sf::RenderWindow& getRenderWindow();
            const sf::View& getView() const;
            bool init(const sf::Vector2u& size, sf::RenderWindow& hwnd);
            void post_render();
            void pre_render();
            void setView(const sf::View& view);
        private:
            virtual void draw(sf::RenderTarget& target, sf::RenderStates states=sf::RenderStates::Default) const;

            sf::RenderTexture m_frame;
            sf::RenderWindow* m_hwnd;
            sf::VertexArray m_vertices;
    };
}

#endif