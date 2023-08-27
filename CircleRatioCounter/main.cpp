#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>

int main()
{
    // CONSTANTS
    static const float THICKNESS = 2.0f;
    static const float SCREEN_SIZE = 400.0f;

    // window
    sf::RenderWindow window(sf::VideoMode(SCREEN_SIZE + 2 * THICKNESS, SCREEN_SIZE + 2 * THICKNESS), "Approximating Pi");

    // square
    sf::RectangleShape square(sf::Vector2f(SCREEN_SIZE, SCREEN_SIZE));
    // set origin
    square.setOrigin(sf::Vector2f(-THICKNESS, -THICKNESS));
    // set fill
    square.setFillColor(sf::Color::Transparent);
    // set outline
    square.setOutlineThickness(THICKNESS);
    square.setOutlineColor(sf::Color(255, 255, 255));

    // circle
    sf::CircleShape circle(SCREEN_SIZE / 2.0f);
    // set origin
    circle.setOrigin(sf::Vector2f(-THICKNESS, -THICKNESS));
    // set fill
    circle.setFillColor(sf::Color::Transparent);
    // set outline
    circle.setOutlineThickness(THICKNESS);
    circle.setOutlineColor(sf::Color(255, 255, 255));

    // use texture to save all shapes to a sprite
    sf::RenderTexture bgTex;
    bgTex.create(SCREEN_SIZE + 2 * THICKNESS, SCREEN_SIZE + 2 * THICKNESS);
    bgTex.draw(square);
    bgTex.draw(circle);
    bgTex.display();

    // dot to draw
    sf::CircleShape dot(1.0f);

    // the total number of dots
    int totalDots = 0;
    // the number of dots in the circle
    int circleDots = 0;

    // loop
    while (window.isOpen())
    {
        // event handling
        sf::Event event;
        while (window.pollEvent(event))
        {
            // closing
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // encapsulate in loop to many points before drawing to screen
        for (int i = 0; i < 1000; i++) {
            // generate random point
            // note that rand() is considered problematic, but for this toy case its fine
            // offset so its between -r, r
            float x = static_cast <float> (rand()) / static_cast <float> (RAND_MAX / SCREEN_SIZE) - SCREEN_SIZE/2;
            float y = static_cast <float> (rand()) / static_cast <float> (RAND_MAX / SCREEN_SIZE) - SCREEN_SIZE/2;

            // set origin
            dot.setOrigin(sf::Vector2f(-SCREEN_SIZE/2 - THICKNESS - x, -SCREEN_SIZE/2 - THICKNESS - y));

            // get squared distance from point to center
            float d = x * x + y * y;
            // compare to squared radius of circle
            if (d <= SCREEN_SIZE * SCREEN_SIZE / 4) {
                // set fill
                dot.setFillColor(sf::Color(0, 255, 0, 100));

                // update count
                circleDots++;
                totalDots++;
            } else {
                // set fill
                dot.setFillColor(sf::Color(0, 0, 255, 100));

                // update count
                totalDots++;
            }

            // update texture to include new dot
            bgTex.draw(dot);
            bgTex.display();
        }

        // update sprite
        sf::Sprite sprites(bgTex.getTexture());

        // draw
        window.clear();
        window.draw(sprites);
        window.display();

        // update pi and print
        float pi = 4.0f * float(circleDots) / float(totalDots);
        printf("%f\n", pi);
    }

    return 0;
}