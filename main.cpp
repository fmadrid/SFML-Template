#include <SFML/Graphics.hpp>

int main()
{
    // Generates (does not display) a new interactible window with the title "SFML works!", width = 200, and height = 200
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");

    
    sf::CircleShape circleShape(100.0f); // Declares a "CircleShape" object
    circleShape.setFillColor(sf::Color::Green); // Sets the color of the CircleShape object

    // Set animation logic
    const float MINIMUM_RADIUS = 25.0f;
    const float MAXIMUM_RADIUS = 50.0f;
    const float RADIUS_RATE    = 0.005f;

    float radius     = MINIMUM_RADIUS;
    bool isExpanding = true;
    
    // Infinite loop which runs as long as the program is active
    while (window.isOpen()) {

        // Check for user-input
        sf::Event event;
        while (window.pollEvent(event))
        {
            // If the user initiates a "close action" (i.e., clicks the X or Alt+F4)
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Updates the radius of the circle
        radius += RADIUS_RATE * (isExpanding ? 1 : -1);
        circleShape.setRadius(radius);

        // Reverses the expansion if the circle gets too small or too big
        if (radius < MINIMUM_RADIUS || radius >= MAXIMUM_RADIUS)
            isExpanding = !isExpanding;
    
        // Update the screen
        window.clear();             // Erase the contents of the screen
        window.draw(circleShape);   // Draw the circleShape object
        window.display();           // Display the screen
    }

    return 0;
}