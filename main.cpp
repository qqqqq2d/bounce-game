#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <iterator>
#include <random>
#include <string>
#include <cmath>
#include <format>

bool intersected1 = false;
bool o2_start_moving = false;
bool player_wall1_move = true;
float timer_2 = 1;
bool timer_start2 = false;
float wall_timer = 1;
bool wall_timer_start = false;
float wall_timer2 = 1;
bool wall_timer_start2 = false;
float timer_4 = 1; // used for button
float timer_5 = 1;
float timer_6 = 1;
float timer_7 = 1;
float timer_8 = 1;
float timer_9 = 1;
float timer_10 = 2; // used for button
bool timer_start4 = false;
bool timer_start5 = false;
bool timer_start6 = false;
bool timer_start7 = false;
bool timer_start8 = false;
bool timer_start9 = false;
bool timer_start10 = false;
bool new_obstacle2 = false;
bool duplicate_done = false;
bool no_o_collision = false;
bool game_start = false;
bool wall_move_done = false;
bool wall_move_done2 = false;
bool menu_screen2 = false;
int selected_menu_item = 1;
int lowest_selected = 1;
int highest_selected = 3;
float wall_alpha = 20.0;
float wall_alpha2 = 20.0;
float flashwall_alpha = 50.0;
float wall_alpha_test = 50;
int b_a = 20;
int b_a2 = 30;
float mp = 62.5; //62.5
int window_res = 0;
int s_i = 10;
bool window_res_on;
bool button_toggle = false;
bool audio_button_toggle = true;
bool multiplayer_mode;
float x = 320;
float y = 240;
float x2, y2;
int b = 0;
int prev_b = 0;
float obstacle_x = 5;
float obstacle_y = 5;
float obstacle2_x = obstacle_x;
float obstacle2_y = obstacle_y;
float obstacle3_x = obstacle_x;
float obstacle3_y = obstacle_y;
int window_x = 640;
int window_y = 480;
int playerspeed = 3;
bool show_fps = false;
bool player_invincibility = false;
bool pos_x_move_done = false;
bool pos_y_move_done = false;
bool neg_x_move_done = false;
bool neg_y_move_done = true;
bool x_move_condition1 = false;
bool make_white_box_called = false;
int n = -1;
int m = -1;
bool diagonal_rotating = true;
bool small_obstacle_movement = true;
bool found_diagonal = false;
bool search_diagonal = false;
int b_m = 0;
bool obstacle3_collision = false;
int player_move_timer = 60;
bool player_move_timer_start = false;
bool wasd_movement = true;
bool arrow_movement = false;
float obstacle3_speed = 3.0;
int obstacle3_shot = 0;
bool search_condition = false;
bool initialized = false;
bool initialized2 = false;
bool player1_dead = false;
bool player2_dead = false;
float player1_alpha = 255;
float player2_alpha = 255;
bool end_sound_played = false;
bool flash_walls = true;
bool flash1_done = false;
bool flash2_done = true;
bool sound_on = true;
float background_alpha = 255;
float player_x;
bool music_timer_start = true;
float music_timer = 0;
bool music_played = false;
int detected_counter = 0;
int detected_counter1 = 0;
int intersect_count = 0;

// textures

sf::Texture player_texture;
sf::Texture player2_texture;
sf::Texture obstacle_texture;
sf::Texture background_texture;
sf::Texture menu_texture;
sf::Texture menu_button1_texture;
sf::Texture menu_button2_texture;
sf::Texture menu_button3_texture;
sf::Texture menu_button1_texture_diff;
sf::Texture menu_button2_texture_diff;
sf::Texture menu_button3_texture_diff;
sf::Texture menu_button4_texture;
sf::Texture menu_button4_texture_diff;
sf::Texture menu_button_blank_texture;
sf::Texture menu_button_blank_texture_diff;
sf::Texture menu_button_blank_texture_on;
sf::Texture menu_button_2players_texture;
sf::Texture menu_button_2players_texture_on;
sf::Texture menu_button_2players_texture_diff;
sf::Texture menu_button_resize_texture;
sf::Texture menu_button_resize_texture_diff;
sf::Texture obstacle_small_texture;
sf::Texture white_rectangle;
sf::Font arial_font;
sf::Font bitmap_font;
sf::Texture audio_button_on;
sf::Texture audio_button_diff;
sf::Texture audio_button1;
sf::Texture audio_button2;
sf::Texture menu_button_2players_texture_on_diff;
sf::Texture game_title;

void reset_variables() {
    intersected1 = false;
    o2_start_moving = false;
    player_wall1_move = true;
    timer_2 = 1;
    timer_start2 = false;
    wall_timer = 1;
    wall_timer_start = false;
    wall_timer2 = 1;
    wall_timer_start2 = false;
    //timer_4 = 1;
    timer_5 = 1;
    timer_6 = 1;
    timer_start4 = false;
    timer_start5 = false;
    new_obstacle2 = false;
    duplicate_done = false;
    no_o_collision = false;
    wall_move_done = false;
    wall_move_done2 = false;
    b_a = 20;
    b_a2 = 30;
    s_i = 10;
    x = 320;
    y = 240;
    b = 0;
    obstacle_x = 5;
    obstacle_y = 5;
    obstacle2_x = obstacle_x;
    obstacle2_y = obstacle_y;
    player_invincibility = false;
    diagonal_rotating = true;
    small_obstacle_movement = true;
    found_diagonal = false;
    search_diagonal = false;
    timer_7 = 1;
    timer_start7 = false;
    b_m = 0;
    obstacle3_collision = false;
    obstacle3_speed = 3.0;
    obstacle3_shot = 0;
    search_condition = false;
    initialized = false;
    initialized2 = false;
    player1_dead = false;
    player2_dead = false;
    player1_alpha = 255;
    player2_alpha = 255;
    end_sound_played = false;
    timer_9 = 1;
    flash1_done = false;
    flash2_done = true;
    flash_walls = true;
}

void load_textures() {
    if (!player_texture.loadFromFile("../images/player_white.png"))
        std::cout << "error loading player image\n";
    if (!player2_texture.loadFromFile("../images/player_purple.png"))
        std::cout << "error loading player2 image\n";
    if (!obstacle_texture.loadFromFile("../images/obstacle_red.png"))
        std::cout << "error loading obstacle image\n";
    if (!background_texture.loadFromFile("../images/game_background_blue2.png"))
        std::cout << "error loading background image\n";
    if (!arial_font.loadFromFile("../fonts/Arial.otf"))
        std::cout << "error loading font\n";
    if (!bitmap_font.loadFromFile("../fonts/joystix_monospace.otf"))
        std::cout << "error loading bitmap font\n";
    if (!menu_texture.loadFromFile("../images/game_menu2.png"))
        std::cout << "error loading game menu image\n";
    if (!menu_button1_texture.loadFromFile("../images/menu_button_play.png"))
        std::cout << "error loading menu image\n";
    if (!menu_button2_texture.loadFromFile("../images/menu_button_other.png"))
        std::cout << "error loading menu image\n";
    if (!menu_button3_texture.loadFromFile("../images/menu_button_quit.png"))
        std::cout << "error loading menu image\n";
    if (!menu_button1_texture_diff.loadFromFile("../images/menu_button_play_deselected.png"))
        std::cout << "error loading menu image\n";
    if (!menu_button2_texture_diff.loadFromFile("../images/menu_button_other_deselected.png"))
        std::cout << "error loading menu image\n";
    if (!menu_button3_texture_diff.loadFromFile("../images/menu_button_quit_deselected.png"))
        std::cout << "error loading menu image\n";
    if (!menu_button_blank_texture.loadFromFile("../images/menu_button_blank.png"))
        std::cout << "error loading menu image\n";
    if (!menu_button_blank_texture_diff.loadFromFile("../images/menu_button_blank_deselected.png"))
        std::cout << "error loading menu image\n";
    if (!menu_button_blank_texture_on.loadFromFile("../images/menu_button_blank_on.png"))
        std::cout << "error loading menu image\n";
    if (!menu_button_2players_texture.loadFromFile("../images/menu_button_2players.png"))
        std::cout << "error loading menu image\n";
    if (!menu_button_2players_texture_on.loadFromFile("../images/menu_button_2players_on.png"))
        std::cout << "error loading menu image\n";
    if (!menu_button_2players_texture_diff.loadFromFile("../images/menu_button_2players_deselected.png"))
        std::cout << "error loading menu image\n";
    if (!obstacle_small_texture.loadFromFile("../images/obstacle_red_small.png"))
        std::cout << "error loading small obstacle image\n";
    if (!white_rectangle.loadFromFile("../images/white_rectangle.png"))
        std::cout << "error loading white rectangle image\n";
    if (!menu_button_resize_texture.loadFromFile("../images/menu_button_resize.png"))
        std::cout << "error loading menu image\n";
    if (!menu_button_resize_texture_diff.loadFromFile("../images/menu_button_resize_deselected.png"))
        std::cout << "error loading menu image\n";
    if (!audio_button_on.loadFromFile("../images/audio_button_on.png"))
        std::cout << "error loading menu image\n";
    if (!audio_button_diff.loadFromFile("../images/audio_button_deselected.png"))
        std::cout << "error loading menu image\n";
     if (!audio_button1.loadFromFile("../images/audio_button.png"))
        std::cout << "error loading menu image\n";
    if (!audio_button2.loadFromFile("../images/audio_button_on_on.png"))
        std::cout << "error loading menu image\n";
    if (!menu_button_2players_texture_on_diff.loadFromFile("../images/menu_button_2players_on_on.png"))
        std::cout << "error loading menu image\n";
    if (!game_title.loadFromFile("../images/game_title2.png"))
        std::cout << "error loading menu image\n";
}

//wall_y = 480..400
//470..460 2
//459..410 3
//410..371 4
//370..331 3
//320..310 2

//20
//10
//7.5
//5
//7.5
//10
//20
int get_wall_step(const float wall_y) {
    if(wall_y <= 460 && wall_y >= 450) {
        return  2;
    }
    if(wall_y <= 449 && wall_y >= 444) {
        return  3;
    }
    if(wall_y <= 443 && wall_y >= 440) {
        return  4;
    }
    if(wall_y <= 439 && wall_y >= 431) {
        return  3;
    }
    if(wall_y <= 430 && wall_y >= 411) {
        return  2;
    }
    return 1;
}

//-20

//20

int get_wall_step2(const float wall_x) {
    if(wall_x <= -10 && wall_x >= -1) {
        return  2;
    }
    if(wall_x <= 0 && wall_x >= 5) {
        return  3;
    }
    if(wall_x <= 6 && wall_x >= 7) {
        return  4;
    }
    if(wall_x <= 8 && wall_x >= 10) {
        return  3;
    }
    if(wall_x <= 11 && wall_x >= 14) {
        return  2;
    }
    return 1;
}

sf::Vector2f prev_obstacle_pos;
sf::Vector2f prev_small_obstacle_pos;

sf::Sprite createbox() {
    sf::Sprite box;
    box.setOrigin(5,5);
    box.setTexture(white_rectangle);
    box.setScale(2,2);
    //std::cout << "box made" << std::endl;
    return box;
}

std::vector<sf::Sprite> create_white_boxes(const int count) {
    std::vector<sf::Sprite> result;
    result.reserve(count);
    for (int i = 0; i < count; i++) {
        result.push_back(createbox());
    }
    return result;
}

sf::Sound bounce_sound;
sf::Sound end_sound;

sf::SoundBuffer buffer;
sf::SoundBuffer buffer2;


void bouncesound(){
    if (sound_on){
        bounce_sound.setBuffer(buffer);
        bounce_sound.play();
    }
    detected_counter = 10;
    detected_counter1 = 10;
    
}

void endsound(){
    if (sound_on){
        end_sound_played = true;
        end_sound.setBuffer(buffer2);
        end_sound.play();
    }
}

std::random_device seed;
std::mt19937 gen{seed()};

std::uniform_int_distribution<> dist{100, 540};
std::uniform_int_distribution<> dist1{100, 340};
std::uniform_int_distribution<> dist2{0, 1};

std::uniform_int_distribution<> musicdist{1, 10};

int music_multiplier = musicdist(gen);
int choose_music = dist2(gen);

int main() {

    load_textures();

    // sounds


    if (sound_on) {
        if (!buffer.loadFromFile("../sounds/bouncesound.wav"))
            return -1;
    }
    if (false) {
        if (!buffer2.loadFromFile("../sounds/blipSelect.wav"))
        return -1;
    }
    sf::Sound end_sound;

    /*//music
    sf::Music music;
    if (!music.openFromFile("../sounds/gamebackgroundmusic.wav"))
        return -1;*/

    //music
    
    sf::Music musictrack1;
    if (!musictrack1.openFromFile("../sounds/bouncegametrack1.wav"))
        return -1;

    sf::Music musictrack2;
    if (!musictrack2.openFromFile("../sounds/bouncegametrack2.wav"))
        return -1;

    bounce_sound.setPitch(1.2f);
    bounce_sound.setVolume(25.f);

    musictrack1.setVolume(80.f);
    musictrack2.setVolume(80.f);


    // float x = 320;
    // float y = 240;
    // int x2, y2;

    while (true) {
    x2 = dist(gen);
    y2 = dist1(gen);
        if (x2 <= 100 || x2 >= 540)
            break;
    }
    int randomside = dist2(gen);

    /*
    int b = 0;
    int prev_b = 0;

    int playerspeed = 3;
    float obstacle_x = 5;
    float obstacle_y = 5;
    float obstacle2_x = obstacle_x;
    float obstacle2_y = obstacle_y;

    int window_x = 640;
    int window_y = 480;*/

    // create window
    //sf::RenderWindow window(sf::VideoMode(640, 480),"My window", sf::Style::Close);
    sf::RenderWindow window(sf::VideoMode(window_x, window_y),"Bounce game", sf::Style::Titlebar | sf::Style::Close);
    window.setPosition(sf::Vector2i(50, 50));

    // player1 rectangle
    sf::Sprite player;
    player.setTexture(player_texture);
    player.setOrigin(10, 10);
    player.setPosition(320, 240);
    player.setColor(sf::Color(255,255,255,player1_alpha));

    // player2 rectangle

    sf::Sprite player2;
    player2.setTexture(player2_texture);
    player2.setOrigin(10, 10);
    player2.setPosition(320, 300);
    player2.setColor(sf::Color(255,255,255,player2_alpha));

    // obstacle rectangle
    sf::Sprite obstacle;
    obstacle.setTexture(obstacle_texture);
    obstacle.setOrigin(20, 20);
    obstacle.setPosition(x2, y2);
    //obstacle.setFillColor(sf::Color(255, 0, 0));

    // obstacle rectangle 2
    sf::Sprite obstacle2;
    obstacle2.setOrigin(20, 20);
    obstacle2.setTexture(obstacle_texture);
    obstacle2.setPosition(-20, -20);

    // small obstacle rectangle
    sf::Sprite obstacle3;
    obstacle3.setOrigin(10, 10);
    obstacle3.setScale(2, 2);
    obstacle3.setTexture(obstacle_small_texture);
    obstacle3.setPosition(x2-30, y2-30);
    obstacle3.setColor(sf::Color(0,0,0,0));

    //obstacle3.setPosition(-20, 0);

    // white rectangle
    auto white_boxes = create_white_boxes(50);

    auto box_renderer = [&]() {
        window.draw(createbox());
        std::cout << "box rendered" << std::endl;
    };

    // game walls

    // wall 1
    sf::RectangleShape wall1(sf::Vector2f(640.0f, 20.0f));
    wall1.setOrigin(0, 0);
    wall1.setPosition(0, 480); // + 40
    wall1.setFillColor(sf::Color(255, 0, 0, wall_alpha)); // wall_alpha

    // wall 2
    sf::RectangleShape wall2(sf::Vector2f(640.0f, 20.0f));
    wall2.setOrigin(0,0);
    wall2.setPosition(0, -20);
    wall2.setFillColor(sf::Color(255, 0, 0, wall_alpha)); // wall_alpha

    // 400 60

    // wall 3
    sf::RectangleShape wall3(sf::Vector2f(20.0f, 480.0f));
    wall3.setOrigin(0,0);
    wall3.setPosition(-20, 0); // -20 0
    wall3.setFillColor(sf::Color(255, 0, 0, wall_alpha2));

    // wall 4
    sf::RectangleShape wall4(sf::Vector2f(20.0f, 480.0f));
    wall4.setOrigin(0,0);
    wall4.setPosition(640, 0); //
    wall4.setFillColor(sf::Color(255, 0, 0, wall_alpha2));


    //flash walls

    sf::RectangleShape flashwall1(sf::Vector2f(640.0f, 20.0f));
    flashwall1.setOrigin(0, 0);
    flashwall1.setPosition(0, 480);

    sf::RectangleShape flashwall2(sf::Vector2f(640.0f, 20.0f));
    flashwall2.setOrigin(0, 0);
    flashwall2.setPosition(0, -20);

    sf::RectangleShape flashwall3(sf::Vector2f(20.0f, 480.0f));
    flashwall3.setOrigin(0, 0);
    flashwall3.setPosition(-20, 0);

    sf::RectangleShape flashwall4(sf::Vector2f(20.0f, 480.0f));
    flashwall4.setOrigin(0, 0);
    flashwall4.setPosition(640, 0);

    // again text

    sf::Text again_text;
    again_text.setFont(arial_font);
    again_text.setString("GAME OVER");
    again_text.setCharacterSize(50);
    again_text.setFillColor(sf::Color::Red);
    again_text.setOrigin(0,0);
    again_text.setPosition(170, 180);

    // bounce counter

    std::string counter_text = "COUNTER: ";
    //std::string str = std::to_string(b);
    sf::Text bcounter_text;

    bcounter_text.setFont(arial_font);

    //
    bcounter_text.setPosition(0, 0);
    bcounter_text.setCharacterSize(20);
    bcounter_text.setFillColor(sf::Color::White);
    //bcounter_text.setOutlineThickness(0.5f);

    // fps counter

    std::string fps_counter_text = "FPS: ";
    sf::Text fps_text;
    fps_text.setFont(arial_font);

    fps_text.setPosition(470, 0);
    fps_text.setCharacterSize(20);
    fps_text.setFillColor(sf::Color::White);

    // menu screen

    sf::Sprite menu;
    menu.setTexture(menu_texture);
    menu.setScale(sf::Vector2f(8, 8));

    // menu screen 2

    sf::RectangleShape menu2(sf::Vector2f(640, 480));
    menu2.setFillColor(sf::Color(15, 15, 15));

    // button 1

    sf::Vector2f button_scale = sf::Vector2f(8, 8);


    sf::Sprite menu_button1;
    // if (selected_menu_item == 1)
    //     menu_button1.setTexture(menu_button1_texture);
    // else
    //     menu_button1.setTexture(menu_button1_texture_other);

    int inc = 40;

    menu_button1.setPosition(0, 120+inc);
    menu_button1.setScale(sf::Vector2f(button_scale.x, button_scale.y));

    // button 2

    sf::Sprite menu_button2;
    menu_button2.setPosition(0, 220+inc);
    menu_button2.setScale(sf::Vector2f(button_scale.x, button_scale.y));

    // button 3

    sf::Sprite menu_button3;
    menu_button3.setPosition(0, 320+inc);
    menu_button3.setScale(sf::Vector2f(button_scale.x, button_scale.y));

    // button 4

    sf::Sprite menu_button4;
    menu_button4.setPosition(0, 120);
    menu_button4.setScale(sf::Vector2f(button_scale.x, button_scale.y));

    // button 5

    sf::Sprite menu_button5;
    menu_button5.setPosition(0, 220);
    menu_button5.setScale(sf::Vector2f(button_scale.x, button_scale.y));

    sf::Sprite game_background;
    game_background.setTexture(background_texture);
    game_background.setScale(sf::Vector2f(8, 8));
    game_background.setColor(sf::Color(255,255,255, background_alpha));

    sf::Sprite audio_button;
    audio_button.setTexture(audio_button_on);
    audio_button.setPosition(0, 320);
    audio_button.setScale(sf::Vector2f(button_scale.x, button_scale.y));

    //game title
    sf::Sprite game_title_sprite;
    game_title_sprite.setTexture(game_title);
    game_title_sprite.setPosition(0, 5);
    game_title_sprite.setScale(button_scale.x, button_scale.y);

    sf::Clock clock;

    sf::View view = window.getDefaultView();

    while (window.isOpen()) {

        detected_counter--;
        detected_counter1--;

        //update flashwall color
        flashwall1.setFillColor(sf::Color(255, 0, 0, flashwall_alpha));
        flashwall2.setFillColor(sf::Color(255, 0, 0, flashwall_alpha));
        flashwall3.setFillColor(sf::Color(255, 0, 0, flashwall_alpha));
        flashwall4.setFillColor(sf::Color(255, 0, 0, flashwall_alpha));

        game_background.setColor(sf::Color(255,255,255, background_alpha));

        // fps calculation
        float current_time = clock.restart().asSeconds();
        float fps = 1.0 / current_time;

        //std::cout << "FPS: " << std::setprecision(4) << fps << std::endl;

        //std::cout << timer_5 << std::endl;

        float a_m = current_time * mp;

        //debug2

        window.setKeyRepeatEnabled(false);
        //std::cout << "selected menu item: " << selected_menu_item << std::endl;
        //std::cout << "button toggle: " << button_toggle << std::endl;
        //std::cout << "timer 10: " << timer_10 << std::endl;
        //std::cout << "current time: " << current_time << std::endl;
        //std::cout << music.getStatus() << std::endl;
        //std::cout << "music timer: " << music_timer << std::endl;
        //std::cout << 200*music_multiplier << std::endl;
        //std::cout << choose_music << std::endl;


        window.setFramerateLimit(360);
        //window.setVerticalSyncEnabled(true);

        sf::Event event;

        // timer 4

        if (timer_start4 && timer_4 < 2)
            //timer_4++;
            timer_4 = timer_4 + a_m;

        if (timer_start10 && timer_10 < 2)
            timer_10 = timer_10 + a_m;


        if (timer_start5 && timer_5 < 2)
            //timer_4++;
            timer_5 = timer_5 + a_m;

        if (timer_start6)
            timer_6 = timer_6 + a_m;

        if (player_move_timer_start)
            player_move_timer = player_move_timer - a_m;
        
        //music timer
        if (music_timer_start) {
            music_timer = music_timer + a_m;
        }

        //music start
        if (music_timer > 200*music_multiplier && !music_played){
        //std::cout << "play music" << std::endl;
        
            if (choose_music == 1){
                musictrack1.play();
            }

            else {
                musictrack2.play();
            }

            music_played = true;
            music_timer_start = false;
            music_timer = 0;
        }

        if (((musictrack1.getStatus() == 0) && (musictrack2.getStatus() == 0)) && music_played){
            music_played = false;
            music_timer_start = true;
            music_multiplier = musicdist(gen);
        }

        if (!sound_on){
            musictrack1.setVolume(0);
            musictrack2.setVolume(0);
        }
        else {
            musictrack1.setVolume(20.f);
            musictrack2.setVolume(20.f);
        }


        // debug key

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::T)) {
            //std::cout << "speed up game" << std::endl;
            mp = 400;
        }
        else
            mp = 62.5;

        // if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
        //     show_fps = true;
        // }
        //if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))


        while (window.pollEvent(event)) {

            /*if (event.type == sf::Event::Resized) {
                view.setSize(event.size.width, event.size.height);
                window.setView(view);
            }
            */

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F) {
                timer_start4 = true;
                show_fps = true;
            }

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F && timer_4 > 1) {
                show_fps = false;
                timer_start4 = false;
                timer_4 = 1;
            }

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::I) {
                timer_start4 = true;
                player_invincibility = true;
                player.setColor(sf::Color(255, 255, 255, 64));
                //std::cout << "player invincibility on" << std::endl;
            }

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::I && timer_4 > 1) {
                player_invincibility = false;
                timer_start4 = false;
                timer_4 = 1;
                player.setColor(sf::Color(255, 255, 255, 255));
                //std::cout << "player invincibility off" << std::endl;
            }

            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Q)//(sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
                window.close();

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return && !menu_screen2 && selected_menu_item == 1)
                game_start = true;

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return && selected_menu_item == 2) {
                timer_start5 = true;

                menu_screen2 = true;
                highest_selected = 6;
                lowest_selected = 4;
                selected_menu_item = 4;
            }
            // if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && menu_screen2 == true) {
            //
            //     window.setSize(sf::Vector2u(window_x++, window_y++));
            // }

            // if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && menu_screen2 == true) {
            //     window.setSize(sf::Vector2u(window_x--, window_y--));
            // }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return && selected_menu_item == 3)
                window.close();

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down && selected_menu_item != highest_selected)// && !menu_screen2)
                selected_menu_item++;
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up && selected_menu_item != lowest_selected)// && !menu_screen2)
                selected_menu_item--;

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                timer_5 = 1;
                timer_start5 = false;
                menu_screen2 = false;
                highest_selected = 3;
                lowest_selected = 1;
                selected_menu_item = 1;
            }

            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Return) && !button_toggle && menu_screen2 && selected_menu_item == 5) {
                timer_start4 = true;
                //std::cout << "toggled button" << std::endl;
                //std::cout << "button on: " << button_toggle << std::endl;
                button_toggle = true;
                multiplayer_mode = true;
            }

            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Return) && selected_menu_item == 5 && timer_4 > 1) {
                button_toggle = false;
                //std::cout << "toggled off" << std::endl;
                timer_start4 = false;
                timer_4 = 1;
                multiplayer_mode = false;
            }

            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Return) && !audio_button_toggle && menu_screen2 && selected_menu_item == 6) {
                timer_start10 = true;
                //std::cout << "toggled button" << std::endl;
                //std::cout << "button on: " << button_toggle << std::endl;
                audio_button_toggle = true;
                sound_on = true;
            }

            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Return) && selected_menu_item == 6 && timer_10 > 1) {
                audio_button_toggle = false;
                //std::cout << "toggled off" << std::endl;
                timer_start10 = false;
                timer_10 = 1;
                sound_on = false;
            }

            //std::cout << "window res: " << window_res << std::endl;

            //resize window

            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Return) && menu_screen2 && selected_menu_item == 4 && (timer_5 > 1)) {
                window.setSize(sf::Vector2u(window_x = window_x+window_x*0.25, window_y = window_y+window_y*0.25));
                window_res++;
                timer_start5 = false;
                //bcounter_text.setCharacterSize(static_cast<unsigned int>(window.getSize().y / 40));

            }

            if (window_res == 6) {
                window.setSize(sf::Vector2u(window_x = 480, window_y = 360));
                window.setPosition(sf::Vector2i(50, 50));
                window_res = 0;
            }

            if (menu_screen2)
                window_res_on = true;
            else
                window_res_on = false;

            // restart game

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Backspace && intersected1 == true) {
                reset_variables();
                obstacle.setPosition(x2, y2);
                obstacle3.setPosition(x2-30, y2-30);
                player.setPosition(x, y);
                wall1.setPosition(0, 480);
                wall2.setPosition(0, -20);
                wall3.setPosition(-20, 0);
                wall4.setPosition(640, 0);
                flashwall1.setPosition(0, 480);
                flashwall2.setPosition(0, -20);
                flashwall3.setPosition(-20, 0);
                flashwall4.setPosition(640, 0);
                randomside = dist2(gen);
                while (true) {
                    x2 = static_cast<float>(dist(gen));
                    y2 = static_cast<float>(dist1(gen));
                    if (x2 <= 100 || x2 >= 540)
                        break;
                }
                obstacle2.setPosition(-40, -40);
                player2.setPosition(320, 300);
                obstacle3.setColor(sf::Color(0,0,0,0));
                player.setColor(sf::Color(255,255,255,player1_alpha));
                player2.setColor(sf::Color(255,255,255,player2_alpha));
                /*x = 320;
                y = 240;
                intersected1 = false;
                o2_start_moving = false;
                obstacle.setPosition(x2, y2);
                player.setPosition(x, y);
                b = 0;
                obstacle_x = 5, obstacle_y = 5;
                wall1.setPosition(0, 480);
                wall2.setPosition(0, -20);
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
                timer_3 = 1;
                obstacle2.setPosition(-40, -40);
                timer_start2 = false;
                timer_start3 = false;
                wall_move_done = false;
                player2.setPosition(320, 300);
                b_a = 20;
                obstacle2_x = obstacle_x;
                obstacle2_y = obstacle_y;
                s_i = 10;*/

                //std::cout << "x:" << x << "y:" << y << "x2: " << x2 << "y2: " << y2 << std::endl;
            }

        }

        // update bounce counter string

        std::string str = std::to_string(b);
        bcounter_text.setString(counter_text + str);

        // update fps counter string

        auto fps_str = std::format("{:.2f}", fps);
        fps_text.setString(fps_counter_text + fps_str);

        //std::cout << x << ", " << y << std::endl;

        // update menu button textures

        if (selected_menu_item == 1) {
            menu_button1.setTexture(menu_button1_texture);
        }
        else {
            menu_button1.setTexture(menu_button1_texture_diff);
        }
        if (selected_menu_item == 2) {
            menu_button2.setTexture(menu_button2_texture);
        }
        else {
            menu_button2.setTexture(menu_button2_texture_diff);
        }
        if (selected_menu_item == 3) {
            menu_button3.setTexture(menu_button3_texture);
        }
        else {
            menu_button3.setTexture(menu_button3_texture_diff);
        }
        if (selected_menu_item == 4) {
            menu_button4.setTexture(menu_button_resize_texture);
        }
        else {
            menu_button4.setTexture(menu_button_resize_texture_diff);
        }
        if (selected_menu_item == 5 && !button_toggle) {
            menu_button5.setTexture(menu_button_2players_texture);
        }
        else {
            menu_button5.setTexture(menu_button_2players_texture_diff);
        }
        if (button_toggle) {
            menu_button5.setTexture(menu_button_2players_texture_on);
        }
        if (selected_menu_item == 5 && button_toggle){
            menu_button5.setTexture(menu_button_2players_texture_on_diff);
        }
        if (selected_menu_item == 6 && !audio_button_toggle){
            audio_button.setTexture(audio_button1);
        }
        else {
            audio_button.setTexture(audio_button_diff);
        }
        if (audio_button_toggle){
            audio_button.setTexture(audio_button_on);
        }
        if (selected_menu_item == 6 && audio_button_toggle){
            audio_button.setTexture(audio_button2);
        }

        // print out player position

        sf::Vector2f player_position(player.getPosition());
        sf::Vector2f player2_position(player2.getPosition());

        //std::cout << player_position.x << ", " << player_position.y << std::endl;


        //if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Space) && menu_screen2 && selected_menu_item == 4) {
        //    window.setSize(sf::Vector2u(window_x = window_x+window_x*2, window_y = window_y+window_y*2));
        //}

        //if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace) && menu_screen2 && selected_menu_item == 4) {
        //    window.setSize(sf::Vector2u(window_x = window_x-4, window_y = window_y-4));
        //}

        if (game_start == true) {

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                reset_variables();
                game_start = false;
                obstacle.setPosition(x2, y2);
                obstacle3.setPosition(x2-30, y2-30);
                player.setPosition(x, y);
                wall1.setPosition(0, 480);
                wall2.setPosition(0, -20);
                wall3.setPosition(-20, 0);
                wall4.setPosition(640, 0);
                flashwall1.setPosition(0, 480);
                flashwall2.setPosition(0, -20);
                flashwall3.setPosition(-20, 0);
                flashwall4.setPosition(640, 0);
                randomside = dist2(gen);
                while (true) {
                    x2 = static_cast<float>(dist(gen));
                    y2 = static_cast<float>(dist1(gen));
                    if (x2 <= 100 || x2 >= 540)
                        break;
                }
                obstacle2.setPosition(-40, -40);
                player2.setPosition(320, 300);
                obstacle3.setColor(sf::Color(0,0,0,0));
                player.setColor(sf::Color(255,255,255,player1_alpha));
                player2.setColor(sf::Color(255,255,255,player2_alpha));
            }

            if (intersected1 == false) {

                // return to menu

                /*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                    reset_variables();
                    game_start = false;
                    obstacle.setPosition(x2, y2);
                    obstacle3.setPosition(x2-40, y2);
                    player.setPosition(x, y);
                    wall1.setPosition(0, 480);
                    wall2.setPosition(0, -20);
                    randomside = dist2(gen);
                    while (true) {
                        x2 = static_cast<float>(dist(gen));
                        y2 = static_cast<float>(dist1(gen));
                        if (x2 <= 100 || x2 >= 540)
                            break;
                    }
                    obstacle2.setPosition(-40, -40);
                    player2.setPosition(320, 300);
                }*/

                auto key_pressed = [](const sf::Keyboard::Key key) -> bool {

                    return sf::Keyboard::isKeyPressed(key);
                };

                // player movement
                if (!multiplayer_mode) {
                    if ((key_pressed(sf::Keyboard::W) || key_pressed(sf::Keyboard::Up)) && (player_position.y >= 0 + player.getOrigin().y + playerspeed))
                        player.move(0, -playerspeed * a_m);
                    if ((key_pressed(sf::Keyboard::S) || key_pressed(sf::Keyboard::Down)) && (player_position.y <= 460 + player.getOrigin().y - playerspeed))
                        player.move(0, playerspeed * a_m);
                    if ((key_pressed(sf::Keyboard::A) || key_pressed(sf::Keyboard::Left)) &&(player_position.x >= 0 + player.getOrigin().x + playerspeed))
                        player.move(-playerspeed * a_m, 0);
                    if ((key_pressed(sf::Keyboard::D) || key_pressed(sf::Keyboard::Right)) && (player_position.x <= 620 + player.getOrigin().x - playerspeed))
                        player.move(playerspeed * a_m, 0);
                }

                if (multiplayer_mode == true) {

                    if (!player1_dead) {
                        if (key_pressed(sf::Keyboard::W) && (player_position.y >= 0 + player.getOrigin().y + playerspeed))
                            player.move(0, -playerspeed * a_m);
                        if (key_pressed(sf::Keyboard::S) && (player_position.y <= 460 + player.getOrigin().y - playerspeed))
                            player.move(0, playerspeed * a_m);
                        if (key_pressed(sf::Keyboard::A) &&(player_position.x >= 0 + player.getOrigin().x + playerspeed))
                            player.move(-playerspeed * a_m, 0);
                        if (key_pressed(sf::Keyboard::D) && (player_position.x <= 620 + player.getOrigin().x - playerspeed))
                            player.move(playerspeed * a_m, 0);
                    }
                    if (!player2_dead) {
                        if (key_pressed(sf::Keyboard::Up) && (player2_position.y >= 0 + player.getOrigin().y + playerspeed))
                            player2.move(0, -playerspeed * a_m);
                        if (key_pressed(sf::Keyboard::Down) && (player2_position.y <= 460 + player.getOrigin().y - playerspeed))
                            player2.move(0, playerspeed * a_m);
                        if (key_pressed(sf::Keyboard::Left) &&(player2_position.x >= 0 + player.getOrigin().x + playerspeed))
                            player2.move(-playerspeed * a_m, 0);
                        if (key_pressed(sf::Keyboard::Right) && (player2_position.x <= 620 + player.getOrigin().x - playerspeed))
                            player2.move(playerspeed * a_m, 0);
                    }
                }

                // sleep 1

                // obstacle moving

                if (o2_start_moving == false) {

                    if (randomside == 1) {
                        obstacle.move(obstacle_x * a_m, obstacle_y * a_m);
                        if (small_obstacle_movement)
                            obstacle3.move(obstacle_x * a_m, obstacle_y * a_m);
                    }
                    else {
                        obstacle.move(-obstacle_x * a_m, -obstacle_y * a_m);
                        if (small_obstacle_movement)
                            obstacle3.move(-obstacle_x * a_m, -obstacle_y * a_m);
                    }

                }

                // obstacle2 moving

                if (new_obstacle2 == true) {
                    if (randomside == 0)
                        obstacle2.move(obstacle2_x * a_m, obstacle2_y * a_m);
                    else
                        obstacle2.move(-obstacle2_x * a_m, -obstacle2_y * a_m);
                }


                // obstacle bouncing
                if (detected_counter <= 0)
                {
                    if (obstacle.getPosition().y > 460) {
                        obstacle_y = -obstacle_y;
                        obstacle3_y = -obstacle3_y;
                        b++;
                        bouncesound();
                        //timer_start = true;
                    }
                    if (obstacle.getPosition().x > 620) {
                        obstacle_x = -obstacle_x;
                        obstacle3_x = -obstacle3_x;
                        b++;
                        bouncesound();
                    }
                    if (obstacle.getPosition().y < 0 + obstacle.getOrigin().y) {
                        obstacle_y = -obstacle_y;
                        obstacle3_y = -obstacle3_y;
                        b++;
                        bouncesound();
                        //timer_start = true;
                    }
                    if (obstacle.getPosition().x < 0 + obstacle.getOrigin().x) {
                        obstacle_x = -obstacle_x;
                        obstacle3_x = -obstacle3_x;
                        b++;
                        bouncesound();
                    }
                }
                // small obstacle bouncing

                /*if (obstacle3.getPosition().y > 460) {
                    obstacle3_y = -obstacle3_y;
                    //timer_start = true;
                }
                if (obstacle3.getPosition().x > 620) {
                    obstacle3_x = -obstacle3_x;
                }
                if (obstacle3.getPosition().y < 0 + obstacle3.getOrigin().y) {
                    obstacle3_y = -obstacle3_y;
                    //timer_start = true;
                }
                if (obstacle3.getPosition().x < 0 + obstacle3.getOrigin().x) {
                    obstacle3_x = -obstacle3_x;
                }*/

                // obstacle2 bouncing

                if (detected_counter1 <= 0) {

                    if (new_obstacle2 == true) {

                        if (obstacle2.getPosition().y > 460) {
                            obstacle2_y = -obstacle2_y;
                            b++;
                            bouncesound();
                            //timer_start = true;
                        }
                        if (obstacle2.getPosition().x > 620) {
                            obstacle2_x = -obstacle2_x;
                            b++;
                            bouncesound();
                        }
                        if (obstacle2.getPosition().y < 0 + obstacle2.getOrigin().y) {
                            obstacle2_y = -obstacle2_y;
                            b++;
                            bouncesound();
                            //timer_start = true;
                        }
                        if (obstacle2.getPosition().x < 0 + obstacle2.getOrigin().x) {
                            obstacle2_x = -obstacle2_x;
                            b++;
                            bouncesound();
                        }
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
            //std::cout << "wall alpha: " << wall_alpha << std::endl;
            //std::cout << "b_a: "<< b_a << std::endl;
            //std::cout << "walls y positions: " << wall1.getPosition().y << ", " << wall2.getPosition().y << std::endl;
            //std::cout << "current time: " << current_time << std::endl;
            //std::cout << timer_9 << std::endl;
            //std::cout << obstacle3_shot << std::endl;
            //std::cout << "obstacle3 speed: " << obstacle3_speed << std::endl;
            //std::cout << "obstacle3 shot: " << obstacle3_shot << std::endl;
            //std::cout << "player1 alpha: " << player1_alpha << std::endl;
            //std::cout << "player2 alpha: " << player2_alpha << std::endl;
            //std::cout << "wall3 position: " << wall3.getPosition().x << std::endl;
            //std::cout << "wall4 position: " << wall4.getPosition().x << ", " << wall4.getPosition().y << std::endl;
            //std::cout << "wall alpha 2: " << wall_alpha2 << std::endl;
            //std::cout << "wall alpha 1: " << wall_alpha << std::endl;
            //std::cout << b_a2 << std::endl;
            //std::cout << "flash wall alpha: " << flashwall_alpha << std::endl;
            //std::cout << "flashwall3 position: " << flashwall3.getPosition().x << std::endl;
            //std::cout << player.getPosition().x << std::endl;


            // increase obstacle speed

            if (prev_b!=b && b%s_i==0 && b!=0) {
                //std::cout << "speed increased" << std::endl;

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

                prev_b = b;

            }

            // check collision
            //
            // with player and obstacle

            sf::FloatRect player_box = player.getGlobalBounds();
            sf::FloatRect obstacle_box = obstacle.getGlobalBounds();
            sf::FloatRect player2_box = player2.getGlobalBounds();

            // check collision with player and small obstacle

            for (auto & box: white_boxes) {
                sf::FloatRect box_box = box.getGlobalBounds();
                if (search_diagonal) {
                    //initialized = false;
                    //initialized2 = false;

                    if ((box_box.intersects(player_box) || (box_box.intersects(player2_box) && multiplayer_mode) && obstacle3.getPosition()-prev_small_obstacle_pos != obstacle.getPosition()-prev_obstacle_pos)) {
                        //std::cout << "player collided" << std::endl;
                        diagonal_rotating = false;
                        small_obstacle_movement = false;
                        found_diagonal = true;
                        search_diagonal = false;
                        //if (obstacle3.getPosition().x > 0 || obstacle3.getPosition().y > 0 || obstacle3.getPosition().x < 640 || obstacle3.getPosition().y < 480) {
                        //     obstacle3.move(n*a_m, m*a_m);
                        //     diagonal_rotating = false;
                        //}

                    }
                }
            }

            if (found_diagonal)
                if (obstacle3.getPosition().x > 0 || obstacle3.getPosition().y > 0 || obstacle3.getPosition().x < 640 || obstacle3.getPosition().y < 480) {
                    obstacle3.move(n*a_m*obstacle3_speed, m*a_m*obstacle3_speed);
                    //std::cout << "shoot" << std::endl;
                    timer_start7 = true;


                    //static bool initialized;
                    if (!initialized) {
                        initialized = true;
                        //std::cout << "increase obstacle3 shot" << std::endl;
                        obstacle3_shot++;
                        //obstacle3_speed++;
                    }
                }

            if (timer_7 >= 200 && found_diagonal) {
                //obstacle3.setPosition(x2-30, y2-30);
                obstacle3.setPosition(obstacle.getPosition().x-30, obstacle.getPosition().y-30);
                diagonal_rotating = true;
                small_obstacle_movement = true;
                found_diagonal = false;
                timer_7 = 1;
                timer_start7 = false;
                b_m = b;
                initialized = false;
                initialized2 = false;

                //std::cout << obstacle3.getPosition().x << ", " << obstacle3.getPosition().y << std::endl;
            }



            if (player_box.intersects(obstacle_box) && !player_invincibility) {
                //std::cout << "intersected\n";
                if (multiplayer_mode) {
                    player1_dead = true;
                }
                else {
                intersected1 = true;
                }

                //window.close();
            }

            // check collision with player2 and obstacle
            if (player2_box.intersects(obstacle_box) && multiplayer_mode) {
                if (multiplayer_mode) {
                    player2_dead = true;
                }
                else {
                    intersected1 = true;
                }
            }

            // check collision with player and obstacle2

            sf::FloatRect obstacle2_box = obstacle2.getGlobalBounds();

            if (player_box.intersects(obstacle2_box) && !player_invincibility) {
                //std::cout << "intersected\n";
                if (multiplayer_mode) {
                    player1_dead = true;
                }
                else {
                    intersected1 = true;
                }
                //window.close();
            }

            // check collision with player2 and obstacle2

            if (player2_box.intersects(obstacle2_box) && multiplayer_mode) {
                if (multiplayer_mode) {
                    player2_dead = true;
                }
                else {
                    intersected1 = true;
                }
            }

            sf::FloatRect wall1_box = wall1.getGlobalBounds();
            sf::FloatRect wall2_box = wall2.getGlobalBounds();
            sf::FloatRect wall3_box = wall3.getGlobalBounds();
            sf::FloatRect wall4_box = wall4.getGlobalBounds();

            // check collision with player and walls

            if ((((player_box.intersects(wall1_box) || player_box.intersects(wall2_box)) && b>b_a-1) || ((player_box.intersects(wall3_box) || player_box.intersects(wall4_box)) && b>b_a2-1)) && wall_move_done && !player_invincibility) {
                if (multiplayer_mode) {
                    player1_dead = true;
                }
                else {

                    //std::cout << "intersects" << std::endl;

                    intersected1 = true;
                }
            }


            //test

            /*if ((((player_box.intersects(wall1_box) || player_box.intersects(wall2_box)) && b>b_a-1) || ((player_box.intersects(wall3_box) || player_box.intersects(wall4_box)) && b>b_a2-1)) && wall12_on) {
                if (multiplayer_mode) {
                    player1_dead = true;
                }
                else {
                    intersect_count++;
                    std::cout << "intersects" << intersect_count << std::endl;

                    //intersected1 = true;
                }
            }

            std::cout << "wall12_on: " << wall12_on << std::endl;
            */


            if ((((player2_box.intersects(wall1_box) || player2_box.intersects(wall2_box)) && b>b_a-1) || ((player2_box.intersects(wall3_box) || player2_box.intersects(wall4_box)) && b>b_a2-1)) && wall_move_done && !player_invincibility) {
                 if (multiplayer_mode) {
                     player2_dead = true;
                 }
                 else {
                     intersected1 = true;
                 }
             }

            // check collision with obstacle1 and obstacle2

            if (obstacle_box.intersects(obstacle2_box) && timer_2 >= 100 && no_o_collision == false) {
                // std::cout << "collided" << std::endl;
                // std::cout << "obstacle position: " << obstacle.getPosition().x << ", " << obstacle.getPosition().y << std::endl;
                // std::cout << "obstacle2 position: " << obstacle2.getPosition().x << ", " << obstacle2.getPosition().y << std::endl;
                // std::cout << "\n";

                auto o_r = obstacle.getPosition().x+20;
                auto o_l = obstacle.getPosition().x-20;

                // std::cout << "obstacle right side: " << o_r << std::endl;
                // std::cout << "obstacle left side: " << o_l << std::endl;

                //std::cout << "\n";

                auto o2_r = obstacle2.getPosition().x+20;
                auto o2_l = obstacle2.getPosition().x-20;

                // std::cout << "obstacle2 right side: " << o2_r << std::endl;
                // std::cout << "obstacle2 left side: " << o2_l << std::endl;
                //
                // std::cout << "obstacle left side - obstacle2 right side: " << std::abs(o_l - o2_r) << std::endl;
                // std::cout << "obstacle right side - obstacle2 left side: " << std::abs(o_r - o2_l) << std::endl;

                //bounce left or right
                if (std::abs(o_l-o2_r) <= 20 || std::abs(o_r-o2_l) <= 20) {
                    //std::cout << "move x\n";
                    obstacle_x = -obstacle_x;
                    if (obstacle.getPosition().x > prev_obstacle_pos.x) {
                        obstacle.setPosition(obstacle.getPosition().x-5, obstacle.getPosition().y);
                    }
                    else {
                        obstacle.setPosition(obstacle.getPosition().x+5, obstacle.getPosition().y);
                    }
                    obstacle2_x = -obstacle2_x;
                    //obstacle2.setPosition(obstacle2.getPosition().x-2, obstacle2.getPosition().y);
                }
                //bounce up or down
                else {
                    //std::cout << "move y\n";
                    obstacle_y = -obstacle_y;
                    if (obstacle.getPosition().y > prev_obstacle_pos.y) {
                        obstacle.setPosition(obstacle.getPosition().x, obstacle.getPosition().y-5);
                    }
                    else {
                        obstacle2.setPosition(obstacle2.getPosition().x, obstacle2.getPosition().y+5);
                    }
                    obstacle2_y = -obstacle2_y;
                }

                //if ()
                //obstacle.setPosition(obstacle.getPosition().x+1, obstacle.getPosition().y+1);
                //obstacle2.setPosition(obstacle2.getPosition().x+1, obstacle2.getPosition().y+1);
                //auto obstacle_position = obstacle.getPosition();

                //std::cout  << "obstacle global bounds top: " << obstacle.getGlobalBounds().top << std::endl;

                bouncesound();
                //bounce_sound.setBuffer(buffer);
                //bounce_sound.play();
            }

            // check collision with player and player2

            if (player_box.intersects(player2_box) && multiplayer_mode) {
                intersected1 = true;
            }

            // check collision with player and obstacle3
            sf::FloatRect obstacle3_box = obstacle3.getGlobalBounds();
            if (player_box.intersects(obstacle3_box) && obstacle3_collision && !player_invincibility) {
                if (multiplayer_mode) {
                    player1_dead = true;
                }
                else {
                    intersected1 = true;
                }
            }
            // check collision with player2 and obstacle3
            if (player2_box.intersects(obstacle3_box) && obstacle3_collision && multiplayer_mode) {
                if (multiplayer_mode) {
                    player2_dead = true;
                }
                else {
                    intersected1 = true;
                }
            }
            //move player out of game
            if (player1_dead) {
                if (player1_alpha > 0) {
                    player1_alpha = player1_alpha - 3;
                    player.setColor(sf::Color(255,255,255,player1_alpha));
                    //std::cout << "player1 alpha: " << player1_alpha << std::endl;
                }
                if (player1_alpha < 100) {
                    player.setPosition(-1000, 0);
                    //std::cout << "player1 moved" << std::endl;

                }
            }

            if (player2_dead) {
                if (player2_alpha > 0) {
                    player2_alpha = player2_alpha - 3;
                    player2.setColor(sf::Color(255,255,255,player2_alpha));

                }
                if (player2_alpha < 100) {
                    player2.setPosition(-1000, 0);
                }

            }

            //end game if both players dead
            if (player1_dead && player2_dead) {
                intersected1 = true;
            }

            if (intersected1 && !end_sound_played) {
                endsound();
            }

            //if ()

            if (timer_start2)
                //timer_2++;
                timer_2 = timer_2 + a_m;

            if (wall_timer_start) // && b < 20
                //timer_3++;
                wall_timer = wall_timer + a_m;

            if (wall_timer_start2)
                wall_timer2 = wall_timer2 + a_m;

            if (timer_start7)
                timer_7 = timer_7 + a_m;

            if (timer_start8)
                timer_8 = timer_8 + a_m;

            if (timer_start9)
                timer_9 = timer_9 + a_m;

            // wall move timer

            //std::cout << "timer_3: " << timer_3 << std::endl;

            //increase obstacle3 speed
            if (obstacle3_shot%1 == 0 && !initialized2 && found_diagonal) {
                initialized2 = true;
                obstacle3_speed = obstacle3_speed + 0.2;
                //std::cout << "increase speed" << std::endl;
            }

            // walls 1, 2 danger indicator

            if (b >= b_a-3 && !wall_move_done) {
                wall_alpha = 30;
                wall1.setFillColor(sf::Color(255, 0, 0, wall_alpha));
                wall2.setFillColor(sf::Color(255, 0, 0, wall_alpha));
                //std::cout << "wall danger indicator" << std::endl;
                wall_timer_start = true;
                //std::cout << "timer start: " << wall_timer_start << std::endl;
                wall1.setPosition(0, 400);
                wall2.setPosition(0, 60);

                if (wall_timer >= 30) {
                    //std::cout << "move walls" << std::endl;
                    wall1.setPosition(0, 480);
                    wall2.setPosition(0, -20);
                    //wall_move_done = true;
                }
                if (wall_timer >= 60) {
                    wall1.setPosition(0, 400);
                    wall2.setPosition(0, 60);

                }
                if (wall_timer >= 90) {
                    wall1.setPosition(0, 480);
                    wall2.setPosition(0, -20);
                }
                if (wall_timer >= 120) {
                    //std::cout << "walls move done" << std::endl;
                    wall_timer_start = false;
                    wall_timer = 1;
                    wall_move_done = true;
                    //std::cout << "walls 1, 2 ON" << std::endl;
                }
            }
            // walls 3, 4 danger indicator

            if (b >= b_a2-3 && !wall_move_done2) {
                wall_alpha2 = 30;
                wall3.setFillColor(sf::Color(255, 0, 0, wall_alpha2));
                wall4.setFillColor(sf::Color(255, 0, 0, wall_alpha2));
                //std::cout << "wall danger indicator" << std::endl;
                wall_timer_start2 = true;
                //std::cout << "timer start2: " << wall_timer_start2 << std::endl;
                wall3.setPosition(20, 0);
                wall4.setPosition(600, 0);

                if (wall_timer2 >= 30) {
                    //std::cout << "move walls" << std::endl;
                    wall3.setPosition(-20, 0);
                    wall4.setPosition(640, 0);
                    //wall_move_done = true;
                }
                if (wall_timer2 >= 60) {
                    wall3.setPosition(20, 0);
                    wall4.setPosition(600, 0);
                }
                if (wall_timer2 >= 90) {
                    wall3.setPosition(-20, 0);
                    wall4.setPosition(640, 0);
                }
                if (wall_timer2 >= 120) {
                    //std::cout << "walls move done" << std::endl;
                    wall_timer_start2 = false;
                    wall_timer2 = 1;
                    wall_move_done2 = true;
                    
                    //std::cout << "walls 3, 4 ON" << std::endl;
                }
            }

            // walls 1, 2 appearance

            if (b >= b_a) {

                //std::cout << "walls 1, 2 appearance" << std::endl;

                //std::cout << "moving walls" << std::endl;
                const auto wall1_y = wall1.getPosition().y;
                const auto wall2_y = wall2.getPosition().y;

                if ((wall1_y > 400) && (wall2_y < 60)) {
                    const auto wall1_step = get_wall_step(wall1_y);
                    //std::cout << "wall step" << -wall1_step << std::endl;
                    wall1.move(0, -wall1_step * a_m);
                    wall2.move(0, wall1_step * a_m);

                    flashwall1.setPosition(wall1.getPosition());
                    flashwall2.setPosition(wall2.getPosition());

                    //flashwall1.move(0, -wall1_step * a_m);
                    //flashwall2.move(0, wall1_step * a_m);
                    //std::cout << "walls ON" << std::endl;
                }

                //
                if (b >= b_a+20 && wall_alpha > 0) {
                    wall1.setFillColor(sf::Color(255, 0, 0, wall_alpha = wall_alpha - 0.5));
                    wall2.setFillColor(sf::Color(255, 0, 0, wall_alpha = wall_alpha - 0.5));
                    //wall_alpha_test = 0;
                    //std::cout << "fading walls" << std::endl;

                }
                if (b >= b_a+20 && wall_alpha == 0) { // b_a < b_a+20 && wall_alpha == 0 && !add_b_a
                    //std::cout << "set walls positions " << std::endl;
                    wall1.setPosition(0, 480);
                    wall2.setPosition(0, -20);

                    flashwall1.setPosition(wall1.getPosition());
                    flashwall2.setPosition(wall2.getPosition());

                    //flashwall1.setPosition(0, 480);
                    //flashwall2.setPosition(0, -20);

                    b_a = b_a + 40;
                    wall_move_done = false;
                }
            }
            // walls 3, 4 appearance

            if (b >= b_a2) {

                //std::cout << "walls 3, 4 appearance" << std::endl;

                const auto wall3_x = wall3.getPosition().x;
                const auto wall4_x = wall4.getPosition().x;

                if ((wall3_x < 20) && (wall4_x > 600)) {
                    const auto wall3_step = get_wall_step(wall3_x);
                    wall3.move(wall3_step*a_m, 0);
                    wall4.move(-wall3_step*a_m, 0);

                    flashwall3.setPosition(wall3.getPosition());
                    flashwall4.setPosition(wall4.getPosition());

                    //flashwall3.move(wall3_step*a_m, 0);
                    //flashwall4.move(-wall3_step*a_m, 0);
                }

                if (b >= b_a2+20 && wall_alpha2 > 0) {
                    wall3.setFillColor(sf::Color(255, 0, 0, wall_alpha2 = wall_alpha2 - 0.5));
                    wall4.setFillColor(sf::Color(255, 0, 0, wall_alpha2 = wall_alpha2 - 0.5));
                    //wall_alpha2 = wall_alpha2 - 0.5;
                }
                if (b >= b_a2+20 && wall_alpha2 == 0) {
                    wall3.setPosition(-20, 0);
                    wall4.setPosition(640, 0);

                    flashwall3.setPosition(wall3.getPosition());
                    flashwall4.setPosition(wall4.getPosition());

                    //flashwall3.setPosition(-20, 0);
                    //flashwall4.setPosition(640, 0);

                    b_a2 = b_a2 + 40;
                    wall_move_done2 = false;
                }

            }

            //walls flashing

            if (flash_walls) {
                if (flashwall_alpha > 30 && !flash1_done) {
                    flashwall_alpha=flashwall_alpha-0.1;
                }
                if (flashwall_alpha < 30) {
                    flash1_done = true;
                    timer_start9 = true;
                    if (timer_9 > 30) {
                        timer_start9 = false;
                        flash2_done = false;
                    }
                }
                if (flashwall_alpha < 50 && !flash2_done) {
                    flashwall_alpha=flashwall_alpha+0.1;
                }
                if (flashwall_alpha == 50) {
                    flash1_done = false;
                    flash2_done =  true;
                }
            }

            /*if (player.getPosition().x < player_x) {
                std::cout << "decreasing" << std::endl;
            }
            */
            //change background alpha depending on player position

            // duplicate obstacle

            if (b >= 100 && obstacle.getPosition().x > 290 && obstacle.getPosition().x < 350 && obstacle.getPosition().y > 210 && obstacle.getPosition().y < 270 && duplicate_done == false) {
                obstacle2.setPosition(obstacle.getPosition());
                if (randomside == 1) {
                    //obstacle_x = 5;
                    //obstacle_y = 5;
                }
                else {
                    //obstacle_x = 5;
                    //obstacle_y = -5;
                }

                obstacle2_x = obstacle_x;
                obstacle2_y = obstacle_y;

                o2_start_moving = true;
                //new_obstacle2 = true;
                timer_start2 = true;

                //s_i = 40;

                if (timer_2 >= 60) {
                    new_obstacle2 = true;
                    o2_start_moving = false;
                    duplicate_done = true;
                    //std::cout << "reached 60, start moving" << std::endl;
                }
            }

            //small obstacle rotating

            timer_start6 = true;
            //std::cout << timer_6 << std::endl;

            //std::cout << "obstacle3: " << obstacle3.getPosition().x << std::endl;
            //std::cout << "obstacle + 50: " << obstacle.getPosition().x+50 << std::endl;

            //if (std::abs(obstacle3.getPosition().x-(obstacle.getPosition().x+50)) <= 3) {
            //    std::cout << "OBSTACLE3 WITHIN REACH" << std::endl;
            //}

            //std::cout << "diff: " << obstacle3.getPosition().x - (obstacle.getPosition().x+50) << std::endl;

            if (timer_6 > 0 && small_obstacle_movement) {
                // if (obstacle3.getPosition().x <= obstacle.getPosition().x+50 && !x_move_condition1 || obstacle3.getPosition().x <= obstacle.getPosition().x+50 && x_move_condition1 && std::abs(obstacle3.getPosition().y-(obstacle.getPosition().y-50)) <= 3) {
                //     obstacle3.move(2 * a_m,0);
                //     //std::cout << "moving pos x" << std::endl;
                // }
                if (!x_move_condition1) {
                    if (obstacle3.getPosition().x <= obstacle.getPosition().x+50) {
                        obstacle3.move(2 * a_m,0);
                    }
                }
                else {
                    if (x_move_condition1) {
                        if (obstacle3.getPosition().x <= obstacle.getPosition().x+50 && std::abs(obstacle3.getPosition().y-(obstacle.getPosition().y-30)) <= 3) {
                            obstacle3.move(2 * a_m,0);
                        }
                    }
                }

                if (obstacle3.getPosition().y <= obstacle.getPosition().y+50 && std::abs(
                        obstacle3.getPosition().x-(obstacle.getPosition().x+50)) <= 3) {
                    obstacle3.move(0,2 * a_m);
                    x_move_condition1 = true;
                    //std::cout << "moving pos y" << std::endl;
                        }
                if (obstacle3.getPosition().x >= obstacle.getPosition().x-30 && std::abs(
                        obstacle3.getPosition().y-(obstacle.getPosition().y + 50)) <= 3) {
                    obstacle3.move(-2 * a_m,0);
                    //std::cout << "move neg x" << std::endl;
                        }
                if (obstacle3.getPosition().y >= obstacle.getPosition().y-30 && std::abs(
                        obstacle3.getPosition().x-(obstacle.getPosition().x-30)) <= 3 ) {
                    obstacle3.move(0, -2 * a_m);
                }
            }

            //white_box.setPosition(obstacle3.getPosition()+sf::Vector2f(50, 50));

            int distance_max_x = std::abs(obstacle.getPosition().x - 640);
            int distance_max_y = std::abs(obstacle.getPosition().y - 480);
            int distance_min_x = std::abs(obstacle.getPosition().x - 0);
            int distance_min_y = std::abs(obstacle.getPosition().y - 0);

            //std::cout << distance_max_x << std::endl;
            //std::cout << "minimum distance: " << std::min(distance_max_x, distance_max_y, distance_min_x, distance_min_y) << std::endl;
            if (diagonal_rotating) {
                if (std::min({distance_max_x, distance_max_y, distance_min_x, distance_min_y}) == distance_max_x) {
                    n = -1;
                }
                if (std::min({distance_max_x, distance_max_y, distance_min_x, distance_min_y}) == distance_max_y) {
                    //std::cout << "max_y" << std::endl;
                    m = -1;
                }
                if (std::min({distance_max_x, distance_max_y, distance_min_x, distance_min_y}) == distance_min_x) {
                    //std::cout << "min_x" << std::endl;
                    n = 1;
                }
                if (std::min({distance_max_x, distance_max_y, distance_min_x, distance_min_y}) == distance_min_y) {
                    //std::cout << "min_y" << std::endl;
                    m = 1;
                }
            }

            //condition for object3 to start searching for diagonal

            if (b == 25 || (search_condition && b == b_m+5)) {
                 search_diagonal = true;
            }

            if (search_diagonal)
                search_condition = true;

            //condition for object3 to show up and act
            if (b == 20) {
                obstacle3.setColor(sf::Color(255,255,255,255));
                obstacle3_collision = true;
            }

            // makewhitebox(20);
            float i = 0.0;
            float j = 0.0;

            for (auto & box: white_boxes) {
                box.setPosition(obstacle3.getPosition()+sf::Vector2f(10*i*n, 10*j*m));
                i+=1.0;
                j+=1.0;
            }

            /*
            if (b >= 1 && wall1.getPosition().y > 480 && obstacle.getPosition().y == 320)
                wall1.move(0, -60);

            if (b >= 1 && wall2.getPosition().y < 0 && obstacle.getPosition().y == 320)
                wall2.move(0, 40);
            */
            prev_obstacle_pos = obstacle.getPosition();
            prev_small_obstacle_pos = obstacle3.getPosition();
        }

        window.clear(sf::Color::Black);
        window.draw(game_background);

        for (auto & box: white_boxes) {
            //window.draw(box);
        }

        window.draw(obstacle3);
        window.draw(player);
        window.draw(obstacle);
        window.draw(wall1);
        window.draw(wall2);
        window.draw(bcounter_text);
        window.draw(wall3);
        window.draw(wall4);
        window.draw(flashwall1);
        window.draw(flashwall2);
        window.draw(flashwall3);
        window.draw(flashwall4);

        //box_renderer();
        //window.draw();

        //window.draw()
        if (multiplayer_mode)
            window.draw(player2);
        if (new_obstacle2 == true)
            window.draw(obstacle2);
        if (intersected1 == true)
            window.draw(again_text);
        //window.draw(bcounter_text);

        if (show_fps == true)
            window.draw(fps_text);
        if (game_start == false) {
            window.draw(menu);
            window.draw(game_title_sprite);
            window.draw(menu_button1);
            window.draw(menu_button2);
            window.draw(menu_button3);
        }
        if (menu_screen2 == true) {
            window.draw(menu2);
            window.draw(menu_button4);
            window.draw(menu_button5);
            window.draw(audio_button);
        }

        window.display();

        }
    return 0;

}

