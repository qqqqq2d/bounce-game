#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>
#include <string>
#include <cmath>

bool executed_1 = false;
bool intersected1 = false;
bool o2_start_moving = false;
bool player_wall1_move = true;
int timer_2 = 1;
bool timer_start;
bool timer_start2;
bool new_obstacle2 = false;
bool duplicate_done = false;
bool no_o_collision = false;
bool game_start = false;
bool i = true;

int selected_menu_item = 1;

sf::Texture player_texture;
sf::Texture background_texture;
sf::Texture menu_texture;
sf::Texture menu_button1_texture;
sf::Texture menu_button2_texture;
sf::Texture menu_button1_texture_other;
sf::Texture menu_button2_texture_other;
sf::Font arial_font;
sf::Font bitmap_font;

void load_textures() {
    if (!player_texture.loadFromFile("../images/player_white.png"))
        std::cout << "error loading player image\n";
    if (!background_texture.loadFromFile("../images/game_background.png"))
        std::cout << "error loading background image\n";
    if (!arial_font.loadFromFile("../fonts/arial.ttf"))
        std::cout << "error loading font\n";
    if (!bitmap_font.loadFromFile("../fonts/Pixeled.ttf"))
        std::cout << "error loading bitmap font\n";
    if (!menu_texture.loadFromFile("../images/game_menu2.png"))
        std::cout << "error loading game menu image\n";
    if (!menu_button1_texture.loadFromFile("../images/menu_button_play.png"))
        std::cout << "error loading menu image\n";
    if (!menu_button2_texture.loadFromFile("../images/menu_button_quit.png"))
        std::cout << "error loading menu image\n";
    if (!menu_button1_texture_other.loadFromFile("../images/menu_button_play_deselected.png"))
        std::cout << "error loading menu image\n";
    if (!menu_button2_texture_other.loadFromFile("../images/menu_button_quit_deselected.png"))
        std::cout << "error loading menu image\n";

}

int main() {

    load_textures();

    std::random_device seed;
    std::mt19937 gen{seed()};
    std::uniform_int_distribution<> dist{100, 540};
    std::uniform_int_distribution<> dist1{100, 340};
    std::uniform_int_distribution<> dist2{0, 1};

    float x = 320;
    float y = 240;
    int x2, y2;

    while (true) {    
    x2 = dist(gen);
    y2 = dist1(gen);
        if (x2 <= 100 || x2 >= 540)
            break;
    }
    
    int randomside = dist2(gen);

    int b = 0;
    int prev_b = 0;

    int playerspeed = 3;
    float obstacle_x = 5;
    float obstacle_y = 5;
    float obstacle2_x = obstacle_x;
    float obstacle2_y = obstacle_y;

    // create window 
    //sf::RenderWindow window(sf::VideoMode(640, 480),"My window", sf::Style::Close);
    sf::RenderWindow window(sf::VideoMode(640, 480),"My window", sf::Style::Titlebar | sf::Style::Close);
    window.setPosition(sf::Vector2i(50, 50));
    window.setFramerateLimit(60);

    // player rectangle
    sf::Sprite player;
    player.setTexture(player_texture);
    player.setOrigin(10, 10);
    player.setPosition(320, 240);
    //player.setFillColor(sf::Color(255, 255, 255));

    // obstacle rectangle
    sf::RectangleShape obstacle(sf::Vector2f(40.0f, 40.0f));
    obstacle.setOrigin(20, 20);
    obstacle.setPosition(x2, y2);
    obstacle.setFillColor(sf::Color(255, 0, 0));

    // obstacle rectangle 2
    sf::RectangleShape obstacle2(sf::Vector2f(40.0f, 40.0f));
    obstacle2.setOrigin(20, 20);
    obstacle2.setFillColor(sf::Color(255, 0, 0));

    // game walls
    
    // wall 1
    sf::RectangleShape wall1(sf::Vector2f(640.0f, 400.0f));
    wall1.setOrigin(0, 0);
    wall1.setPosition(0, 520); // + 40
    wall1.setFillColor(sf::Color(255, 0, 0));

    // wall 2
    sf::RectangleShape wall2(sf::Vector2f(640.0f, 200.0f));
    wall2.setOrigin(0,0);
    wall2.setPosition(0, -240);
    wall2.setFillColor(sf::Color(255, 0, 0));

    // again text

    sf::Text again_text;
    again_text.setFont(arial_font);
    again_text.setString("Press N");
    again_text.setCharacterSize(24);
    again_text.setFillColor(sf::Color::White);
    again_text.setOrigin(0,0);
    again_text.setPosition(280, 0);

    // bounce counter


    std::string counter_text = "COUNTER: ";
    //std::string str = std::to_string(b);
    sf::Text bcounter_text;
    bcounter_text.setFont(bitmap_font);
    //
    bcounter_text.setPosition(0, 10);
    bcounter_text.setCharacterSize(16);
    bcounter_text.setFillColor(sf::Color::White);

    // menu

    sf::Sprite menu;
    menu.setTexture(menu_texture);
    menu.setScale(sf::Vector2f(8, 8));

    // button 1

    sf::Sprite menu_button1;
    // if (selected_menu_item == 1)
    //     menu_button1.setTexture(menu_button1_texture);
    // else
    //     menu_button1.setTexture(menu_button1_texture_other);
    menu_button1.setPosition(0, 220);
    menu_button1.setScale(sf::Vector2f(8, 8));

    // button 2
    sf::Sprite menu_button2;
    // if (selected_menu_item == 2)
    //     menu_button2.setTexture(menu_button2_texture);
    // else
    //     menu_button2.setTexture(menu_button2_texture_other);
    menu_button2.setPosition(0, 320);
    menu_button2.setScale(sf::Vector2f(8, 8));

    // button 1 text

    // sf::Text button1_text;
    // button1_text.setFont(font);
    // button1_text.setString("PLAY");
    // button1_text.setCharacterSize(40);
    // button1_text.setPosition(260, 95);
    // button1_text.setFillColor(sf::Color::White);

    // game background sprite
    
    sf::Sprite game_background;
    game_background.setTexture(background_texture);
    while (window.isOpen()) {
        
        //window.setFramerateLimit(60);
        window.setVerticalSyncEnabled(true);
        
        sf::Event event;
        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed)
                window.close(); 

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
                window.close();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return) && selected_menu_item == 1)
                game_start = true;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return) && selected_menu_item == 2)
                window.close();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                selected_menu_item = 2;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                selected_menu_item = 1;

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::N) && intersected1 == true) {
                x = 320;
                y = 240;
                executed_1 = false;
                intersected1 = false;
                o2_start_moving = false;
                obstacle.setPosition(x2, y2);
                player.setPosition(x, y); 
                b = 0;
                obstacle_x = 5, obstacle_y = 5;
                //wall1.setPosition(0, 500);
                new_obstacle2 = false;
                duplicate_done = false;
                randomside = dist2(gen); 
                while (true) {    
                x2 = dist(gen);
                y2 = dist1(gen);
                    if (x2 <= 100 || x2 >= 540)
                        break;
                }
                timer_2 = 1;
                obstacle2.setPosition(-40, -40);
                timer_start2 = false;      

                //std::cout << "x:" << x << "y:" << y << "x2: " << x2 << "y2: " << y2 << std::endl;
            }

        }

        // update bounce counter string

        std::string str = std::to_string(b);
        bcounter_text.setString(counter_text + str);

        // update menu button textures
        if (selected_menu_item == 1)
            menu_button1.setTexture(menu_button1_texture);
        else
            menu_button1.setTexture(menu_button1_texture_other);

        if (selected_menu_item == 2)
            menu_button2.setTexture(menu_button2_texture);
        else
            menu_button2.setTexture(menu_button2_texture_other);


        // print out player position

        sf::Vector2f player_position(player.getPosition());
        //std::cout << player_position.x << ", " << player_position.y << std::endl;


        if (game_start == true) {

            if (intersected1 == false) {

                // player movement

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && (player_position.y >= 0 + player.getOrigin().y + playerspeed) && player_position.y >= wall2.getGlobalBounds().top+200+13) //31
                    player.move(0, -playerspeed);
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && (player_position.y <= 460 + player.getOrigin().y - playerspeed) && player_position.y <= wall1.getGlobalBounds().top-13)
                    player.move(0, playerspeed);
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) &&(player_position.x >= 0 + player.getOrigin().x + playerspeed))
                    player.move(-playerspeed, 0);
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && (player_position.x <= 620 + player.getOrigin().x - playerspeed))
                    player.move(playerspeed, 0);

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && (player_position.y >= 0 + player.getOrigin().y + playerspeed) && player_position.y >= wall2.getGlobalBounds().top+31)
                    player.move(0, -playerspeed);
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && (player_position.y <= 460 + player.getOrigin().y - playerspeed) && player_position.y <= wall1.getGlobalBounds().top-15)
                    player.move(0, playerspeed);
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) &&(player_position.x >= 0 + player.getOrigin().x + playerspeed))
                    player.move(-playerspeed, 0);
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && (player_position.x <= 620 + player.getOrigin().x - playerspeed))
                    player.move(playerspeed, 0);

                // sleep 1

                // obstacle moving

                if (o2_start_moving == false) {

                    if (randomside == 1)
                        obstacle.move(obstacle_x, obstacle_y);
                    else
                        obstacle.move(-obstacle_x, -obstacle_y);
                }

                // obstacle2 moving

                if (new_obstacle2 == true) {
                    if (randomside == 0)
                        obstacle2.move(obstacle2_x, obstacle2_y);
                    else
                        obstacle2.move(-obstacle2_x, -obstacle2_y);
                }

                // obstacle bouncing

                if (obstacle.getPosition().y > 460) {
                    obstacle_y = -obstacle_y;
                    b++;
                    timer_start = true;
                }
                if (obstacle.getPosition().x > 620) {
                    obstacle_x = -obstacle_x;
                    b++;
                }
                if (obstacle.getPosition().y < 0 + obstacle.getOrigin().y) {
                    obstacle_y = -obstacle_y;
                    b++;
                    timer_start = true;
                }
                if (obstacle.getPosition().x < 0 + obstacle.getOrigin().x) {
                    obstacle_x = -obstacle_x;
                    b++;
                }

                // obstacle2 bouncing

                if (new_obstacle2 == true) {

                    if (obstacle2.getPosition().y > 460) {
                        obstacle2_y = -obstacle2_y;
                        b++;
                        timer_start = true;
                    }
                    if (obstacle2.getPosition().x > 620) {
                        obstacle2_x = -obstacle2_x;
                        b++;
                    }
                    if (obstacle2.getPosition().y < 0 + obstacle2.getOrigin().y) {
                        obstacle2_y = -obstacle2_y;
                        b++;
                        timer_start = true;
                    }
                    if (obstacle2.getPosition().x < 0 + obstacle2.getOrigin().x) {
                        obstacle2_x = -obstacle2_x;
                        b++;
                    }

                }
            }

            // debug

            //std::cout << "bounce count: " << b << std::endl;
            //std::cout << "obstacle speed: " << obstacle_x << ", " << obstacle_y << std::endl;
            //std::cout << "obstacle2 speed: " << obstacle2_x << ", " << obstacle2_y << std::endl;
            //std::cout << "obstacle position: " << obstacle.getPosition().x << ", " << obstacle.getPosition().y << std::endl;
            //std::cout << "obstacle2 position: " << obstacle2.getPosition().x << ", " << obstacle2.getPosition().y << std::endl;
            //std::cout << "wall1 height: " << wall1.getGlobalBounds().top << std::endl;
            //std::cout << "player position y:" << player_position.y << std::endl;
            //std::cout << "wall2 y position: " << wall2.getPosition().y << std::endl;
            //std::cout << "wall1 y position: " << wall1.getPosition().y << std::endl;
            //std::cout << "player y position: " << player.getPosition().y << std::endl;
            //std::cout << "wall 2: " << wall2.getGlobalBounds().top << std::endl;
            //std::cout << "b counter: " << b << std::endl;

            // increase obstacle speed

            if (prev_b!=b && b%10==0 && b!=0) {
                std::cout << "speed increased" << std::endl;

                // obstacle

                if (obstacle_x > 0 && obstacle_y > 0) {
                    obstacle_x = obstacle_x+0.25;
                    obstacle_y = obstacle_y+0.25;
                    //obstacle_x++;
                    //obstacle_y++;
                }

                else if (obstacle_x > 0 && obstacle_y < 0) {
                    obstacle_x = obstacle_x+0.25;
                    obstacle_y = obstacle_y-0.25;
                    //obstacle_x++;
                    //obstacle_y--;
                }

                else if (obstacle_x < 0 && obstacle_y > 0) {
                    obstacle_x = obstacle_x-0.25;
                    obstacle_y = obstacle_y+0.25;
                    //obstacle_x--;
                    //obstacle_y++;
                }

                else if (obstacle_x < 0 && obstacle_y < 0) {
                    obstacle_x = obstacle_x-0.25;
                    obstacle_y = obstacle_y-0.25;
                    //obstacle_x--;
                    //obstacle_y--;
                }

                // obstacle2

                if (obstacle2_x > 0 && obstacle2_y > 0) {
                    obstacle2_x = obstacle2_x+0.25;
                    obstacle2_y = obstacle2_y+0.25;
                    //obstacle_x++;
                    //obstacle_y++;
                }

                else if (obstacle2_x > 0 && obstacle2_y < 0) {
                    obstacle2_x = obstacle2_x+0.25;
                    obstacle2_y = obstacle2_y-0.25;
                    //obstacle_x++;
                    //obstacle_y--;
                }

                else if (obstacle2_x < 0 && obstacle2_y > 0) {
                    obstacle2_x = obstacle2_x-0.25;
                    obstacle2_y = obstacle2_y+0.25;
                    //obstacle_x--;
                    //obstacle_y++;
                }

                else if (obstacle2_x < 0 && obstacle2_y < 0) {
                    obstacle2_x = obstacle2_x-0.25;
                    obstacle2_y = obstacle2_y-0.25;
                    //obstacle_x--;
                    //obstacle_y--;
                }


                executed_1 = true;
                prev_b = b;

            }

            // check collision with player and obstacle

            sf::FloatRect player_box = player.getGlobalBounds();
            sf::FloatRect obstacle_box = obstacle.getGlobalBounds();

            if (player_box.intersects(obstacle_box)) {
                //std::cout << "intersected\n";
                intersected1 = true;

                //window.close();
            }

            // check collision with player and obstacle2

            sf::FloatRect obstacle2_box = obstacle2.getGlobalBounds();

            if (player_box.intersects(obstacle2_box)) {
                //std::cout << "intersected\n";
                intersected1 = true;

                //window.close();
            }


            // check collision with obstacle and wall1

            sf::FloatRect wall1_box = wall1.getGlobalBounds();

            if (obstacle_box.intersects(wall1_box)) {
                obstacle.setPosition(obstacle.getPosition().x, obstacle.getPosition().y-3);
                obstacle_y = -obstacle_y;
            }

            // check collision with obstacle and wall2

            sf::FloatRect wall2_box = wall2.getGlobalBounds();

            if (obstacle_box.intersects(wall2_box)) {
                obstacle.setPosition(obstacle.getPosition().x, obstacle.getPosition().y+3);
                obstacle_y = -obstacle_y;
            }

            // check collision with player and wall1

            if (player_box.intersects(wall1_box)) {
                player.move(player_position.x-player_position.x, -10);
            }

            // check collision with player and wall1

            if (player_box.intersects(wall2_box)) {
                player.move(player_position.x-player_position.x, 10);
            }

            // check collision with obstacle1 and obstacle2

            if (obstacle_box.intersects(obstacle2_box) && timer_2 >= 100 && no_o_collision == false) {
                std::cout << "collided" << std::endl;
                std::cout << "obstacle position: " << obstacle.getPosition().x << ", " << obstacle.getPosition().y << std::endl;
                std::cout << "obstacle2 position: " << obstacle2.getPosition().x << ", " << obstacle2.getPosition().y << std::endl;
                std::cout << "\n";

                auto o_r = obstacle.getPosition().x+20;
                auto o_l = obstacle.getPosition().x-20;

                std::cout << "obstacle right side: " << o_r << std::endl;
                std::cout << "obstacle left side: " << o_l << std::endl;

                std::cout << "\n";

                auto o2_r = obstacle2.getPosition().x+20;
                auto o2_l = obstacle2.getPosition().x-20;

                std::cout << "obstacle2 right side: " << o2_r << std::endl;
                std::cout << "obstacle2 left side: " << o2_l << std::endl;

                std::cout << "obstacle left side - obstacle2 right side: " << std::abs(o_l - o2_r) << std::endl;
                std::cout << "obstacle right side - obstacle2 left side: " << std::abs(o_r - o2_l) << std::endl;

                if (std::abs(o_l-o2_r) <= 10 || std::abs(o_r-o2_l) <= 10) {
                    std::cout << "move x\n";
                    obstacle_x = -obstacle_x;
                    obstacle2_x = -obstacle2_x;
                }
                else {
                    std::cout << "move y\n";
                    obstacle_y = -obstacle_y;
                    obstacle2_y = -obstacle2_y;
                }

                //if ()
                //obstacle.setPosition(obstacle.getPosition().x+1, obstacle.getPosition().y+1);
                //obstacle2.setPosition(obstacle2.getPosition().x+1, obstacle2.getPosition().y+1);
                //auto obstacle_position = obstacle.getPosition();

                std::cout  << "obstacle global bounds top: " << obstacle.getGlobalBounds().top << std::endl;

            }

            if (timer_start2)
                timer_2++;

            // wall move timer

            //std::cout << timer_2 << std::endl;

            // duplicate obstacle

            if (b >= 30 && obstacle.getPosition().x > 290 && obstacle.getPosition().x < 350 && obstacle.getPosition().y > 210 && obstacle.getPosition().y < 270 && duplicate_done == false) {
                obstacle2.setPosition(obstacle.getPosition());
                obstacle_x = 5;
                obstacle_y = 5;
                obstacle2_x = obstacle_x;
                obstacle2_y = obstacle_y;
                o2_start_moving = true;
                //new_obstacle2 = true;
                timer_start2 = true;


                if (timer_2 >= 60) {
                    new_obstacle2 = true;
                    o2_start_moving = false;
                    duplicate_done = true;
                    //std::cout << "reached 60, start moving" << std::endl;
                }
            }
            /*
            if (b >= 1 && wall1.getPosition().y > 480 && obstacle.getPosition().y == 320)
                wall1.move(0, -60);

            if (b >= 1 && wall2.getPosition().y < 0 && obstacle.getPosition().y == 320)
                wall2.move(0, 40);
            */
        }

        window.clear(sf::Color::Black);
        window.draw(game_background);
        window.draw(player);
        window.draw(obstacle);
        window.draw(wall1);
        window.draw(wall2);
        if (new_obstacle2 == true)
            window.draw(obstacle2);
        if (intersected1 == true)
            window.draw(again_text);
        window.draw(bcounter_text);
        if (game_start == false) {
            window.draw(menu);
            window.draw(menu_button1);
            window.draw(menu_button2);
        }

        window.display();

        }
    return 0;

}

