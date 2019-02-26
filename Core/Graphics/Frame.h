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
    class Frame
    {
        public:
			Frame(sf::RenderTarget& target);
            ~Frame();
            void blit(const sf::Drawable& drawable, const sf::RenderStates states=sf::RenderStates::Default);
            sf::RenderTarget& getRenderTarget();
            const sf::View& getView() const;
            void post_render();
            void pre_render();
            void setView(const sf::View& view);
        private:

            sf::RenderTarget& m_target;
    };
}

#endif