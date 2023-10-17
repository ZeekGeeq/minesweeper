//
// Created by zeekd on 4/19/2023.
//

#ifndef MINESWEEPER_STORAGE_SPACE_H
#define MINESWEEPER_STORAGE_SPACE_H
//
//
////
//// Created by zeekd on 4/17/2023.
////
//#include<vector>
//#include<SFML/Graphics.hpp>
//#include<fstream>
//#include<string>
//#include<cstdlib>
//#ifndef MINESWEEPER_TILE_H
//#define MINESWEEPER_TILE_H
//
//struct Tile{
//public:
//    bool is_mine;
//    bool is_number;
//    sf::Sprite sprite;
//    sf::Sprite tile_cover;
//    std::vector<Tile> neighboring_tiles;
//
//};
//
//class GameTiles{
//public:
//    std::vector<Tile> tiles;
//    int num_mines, num_rows,num_columns;
//    GameTiles(){
//        std::string buffer;
//        std::fstream file("files/board_config.cfg", std::ios_base::in);
//        getline(file,buffer);
//        num_columns = stoi(buffer);
//        getline(file,buffer);
//        num_rows = stoi(buffer);
//        getline(file,buffer);
//        num_mines  = stoi(buffer);
//
//        int minecounter = 0;
//        sf::Texture texture;
//        int spacing_counter = 0;
//        for(int p =0; p< num_columns*num_rows; p++){
//            if(p % num_columns == 0){
//                std::cout<<std::endl;
//            }
//            int random_num = rand();
//
//            Tile tile;
//
//            tiles.push_back(tile);
//            if(random_num%2==0 && spacing_counter % 7==0){
//                if(minecounter == num_mines){
//                    std::cout<<"1";
//                    tiles[p].is_mine = false;
//                    tiles[p].is_number = true;
//                    texture.loadFromFile("files/images/mine.png");
//                    tiles[p].sprite.setTexture(texture);
//                }
//                else{
//                    std::cout<<"0";
//                    minecounter ++;
//                    tiles[p].is_mine = true;
//                    tiles[p].is_number = false;
//                }
//            }
//            else{
//                std::cout<<"1";
//                tiles[p].is_mine = false;
//                tiles[p].is_number = true;
//                spacing_counter++;
//            }
//            tiles[p].neighboring_tiles.reserve(8);
//        }
//        if(num_mines - minecounter != 0){
//
//        }
//        std::cout<<std::endl<<minecounter<<std::endl;
////        for(int m = 0; m<num_rows*num_columns;m++){
////            if (tiles[m].is_mine){
////                continue;
////            }
////            else{
////                if ((m == 0) || (m== num_columns-1) || (m == ((num_rows-1) * num_columns) + 1 || (m == num_columns*num_rows - 1))){
////                    count_corner_mines(m);
////                }
////                else if((m%num_columns == 0) || (m < (num_columns-1)) || (m > num_columns*(num_rows-1)) || (m % num_columns == num_columns-1)){
////                    if(tiles[m].neighboring_tiles.empty()){
////                        count_edge_mines(m);
////                    }
////                }
////                else{
////                    if(tiles[m].neighboring_tiles.empty()){
////                        count_interior(m);
////                    }
////                }
////            }
////        }
//        std::cout<<tiles.size()<<std::endl;
//    }
//
//    void create_tiles_corner(){
//
//    }
//    void create_tiles_edges(){
//
//    }
//    void creat_tiles_interior(){
//
//    }
//
//
//
//    void count_corner_mines(int tile_index){
//        int mine_counter = 0;
//        sf::Texture textu;
//        std::string filepath = "files/images/number_";
//        std::string extension = ".png";
//        std::string number;
//        if(tile_index == 0){
//            tiles[0].neighboring_tiles.push_back(tiles[1]);
//            tiles[0].neighboring_tiles.push_back(tiles[num_columns]);
//            tiles[0].neighboring_tiles.push_back(tiles[num_columns+1]);
//        }
//        else if(tile_index == num_columns-1){
//            tiles[tile_index].neighboring_tiles.push_back(tiles[num_columns-2]);
//            tiles[tile_index].neighboring_tiles.push_back(tiles[num_columns*2-1]);
//            tiles[tile_index].neighboring_tiles.push_back(tiles[num_columns*2-2]);
//        }
//        else if(tile_index == (num_rows-1) * num_columns){
//            tiles[tile_index].neighboring_tiles.push_back(tiles[num_columns*(num_rows-1)+1]);
//            tiles[tile_index].neighboring_tiles.push_back(tiles[num_columns*(num_rows-2)]);
//            tiles[tile_index].neighboring_tiles.push_back(tiles[num_columns*(num_rows-2)+1]);
//        }
//        else if(tile_index == num_rows*num_columns - 1){
//            tiles[tile_index].neighboring_tiles.push_back(tiles[num_columns*num_rows - 2]);
//            tiles[tile_index].neighboring_tiles.push_back(tiles[(num_rows-1)*num_columns - 1]);
//            tiles[tile_index].neighboring_tiles.push_back(tiles[(num_rows-1)*num_columns - 2]);
//        }
//        for(int t = 0; t<3;t++){
//            if(tiles[t].is_mine){
//                mine_counter++;
//            }
//        }
//        number = std::to_string(mine_counter);
//        if(mine_counter == 0){
//            textu.loadFromFile("files/images/tile_revealed.png");
//            tiles[tile_index].sprite.setTexture(textu);
//        }
//        else{
//            textu.loadFromFile(filepath+number+extension);
//            tiles[tile_index].sprite.setTexture(textu);
//        }
//    }
//    void count_edge_mines(int tile_index){
//        int mine_counter = 0;
//        sf::Texture textu;
//        std::string filepath = "files/images/number_";
//        std::string extension = ".png";
//        std::string number;
//        if(tile_index % num_columns == 0){
//            tiles[tile_index].neighboring_tiles.push_back(tiles[tile_index-num_columns]);
//            tiles[tile_index].neighboring_tiles.push_back(tiles[tile_index-num_columns+1]);
//            tiles[tile_index].neighboring_tiles.push_back(tiles[tile_index+1]);
//            tiles[tile_index].neighboring_tiles.push_back(tiles[tile_index+num_columns]);
//            tiles[tile_index].neighboring_tiles.push_back(tiles[tile_index+num_columns+1]);
//        }
//        else if(tile_index < (num_columns-1)){
//            tiles[tile_index].neighboring_tiles.push_back(tiles[tile_index+1]);
//            tiles[tile_index].neighboring_tiles.push_back(tiles[tile_index-1]);
//            tiles[tile_index].neighboring_tiles.push_back(tiles[tile_index+num_columns]);
//            tiles[tile_index].neighboring_tiles.push_back(tiles[tile_index+num_columns+1]);
//            tiles[tile_index].neighboring_tiles.push_back(tiles[tile_index+num_columns-1]);
//        }
//        else if(tile_index > num_columns*(num_rows-1)){
//            tiles[tile_index].neighboring_tiles.push_back(tiles[tile_index+1]);
//            tiles[tile_index].neighboring_tiles.push_back(tiles[tile_index-1]);
//            tiles[tile_index].neighboring_tiles.push_back(tiles[tile_index-num_columns]);
//            tiles[tile_index].neighboring_tiles.push_back(tiles[tile_index-num_columns+1]);
//            tiles[tile_index].neighboring_tiles.push_back(tiles[tile_index-num_columns-1]);
//        }
//        else if(tile_index % num_columns == num_columns - 1){
//            tiles[tile_index].neighboring_tiles.push_back(tiles[tile_index-1]);
//            tiles[tile_index].neighboring_tiles.push_back(tiles[tile_index-num_columns]);
//            tiles[tile_index].neighboring_tiles.push_back(tiles[tile_index-num_columns-1]);
//            tiles[tile_index].neighboring_tiles.push_back(tiles[tile_index+num_columns]);
//            tiles[tile_index].neighboring_tiles.push_back(tiles[tile_index+num_columns-1]);
//        }
//        for(int t = 0; t<5;t++){
//            if(tiles[t].is_mine){
//                mine_counter++;
//            }
//        }
//        number = std::to_string(mine_counter);
//        if(mine_counter == 0){
//            textu.loadFromFile("files/images/tile_revealed.png");
//            tiles[tile_index].sprite.setTexture(textu);
//        }
//        else{
//            textu.loadFromFile(filepath+number+extension);
//            tiles[tile_index].sprite.setTexture(textu);
//        }
//    }
//    void count_interior(int tile_index){
//        int mine_counter = 0;
//        sf::Texture textu;
//        std::string number;
//        tiles[tile_index].neighboring_tiles.push_back(tiles[tile_index+1]);
//        tiles[tile_index].neighboring_tiles.push_back(tiles[tile_index-1]);
//
//        tiles[tile_index].neighboring_tiles.push_back(tiles[tile_index-num_columns]);
//        tiles[tile_index].neighboring_tiles.push_back(tiles[tile_index-num_columns+1]);
//        tiles[tile_index].neighboring_tiles.push_back(tiles[tile_index-num_columns-1]);
//
//        tiles[tile_index].neighboring_tiles.push_back(tiles[tile_index+num_columns]);
//        tiles[tile_index].neighboring_tiles.push_back(tiles[tile_index+num_columns+1]);
//        tiles[tile_index].neighboring_tiles.push_back(tiles[tile_index+num_columns-1]);
//        for(int t = 0; t<8;t++){
//            if(tiles[t].is_mine){
//                mine_counter++;
//            }
//        }
//        number = std::to_string(mine_counter);
//        if(mine_counter == 0){
//            textu.loadFromFile("files/images/tile_revealed.png");
//            tiles[tile_index].sprite.setTexture(textu);
//        }
//        else{
//            textu.loadFromFile("files/images/number_"+number+".png");
//            tiles[tile_index].sprite.setTexture(textu);
//        }
//    }
//};
//


//#endif //MINESWEEPER_TILE_H



////from main.cpp
//    int xcoord,ycoord,counter = 0;
//    for(int i = 0; i < game.tiles.size(); i++){
//        if(counter == game.num_columns){
//            counter = 0;
//            xcoord = 0;
//            ycoord = 0;
//        }
//        game.tiles[i].sprite.setOrigin(xcoord,ycoord);
//        game_window.draw(game.tiles[i].sprite);
//        xcoord = xcoord-10;
//        ycoord = ycoord-10;
//        counter ++;
//    }



#endif //MINESWEEPER_STORAGE_SPACE_H




//sf::RenderWindow welcome_window(sf::VideoMode(800, 600), "Minesweeper");
//sf::RectangleShape rectangle(sf::Vector2f(800, 600));
//rectangle.setFillColor(sf::Color(0,0,255,255));
//
//sf::Text text;
//sf::Font font;
//font.loadFromFile("files/font.ttf");
//text.setFont(font);
//text.setCharacterSize(24);
//text.setString("Welcome to Minesweeper");
//text.setFillColor(sf::Color::White);
//text.setOrigin(-230,-200);
//text.setPosition(2.0f,2.0f);
//text.setStyle(sf::Text::Bold | sf::Text::Underlined);
//
//sf::Text prompt;
//prompt.setFont(font);
//prompt.setString("Enter your name:");
//prompt.setCharacterSize(20);
//prompt.setFillColor(sf::Color::White);
//prompt.setOrigin(-300,-250);
//
//sf::Text name_text;
//name_text.setFont(font);
//name_text.setFillColor(sf::Color::Yellow);
//std::string input_string = "";
//name_text.setString(input_string);
//std::string suffix = "|";
//input_string = input_string + suffix;
//name_text.setOrigin(-400,-300);
//
//bool continue_to_game;
//
//while (welcome_window.isOpen())
//{
//sf::Event event;
//name_text.setString(input_string);
//while (welcome_window.pollEvent(event)) {
//welcome_window.clear(sf::Color(0, 0, 255, 255));
//if (event.type == sf::Event::Closed) {
//welcome_window.close();
//exit(0);
//}
//else if ((input_string.size() >= 2) && (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter))){
//welcome_window.close();
//continue_to_game = true;
//}
//else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter) && (input_string.size()  == 1)){
//welcome_window.close();
//exit(0);
//}
//if(event.type == sf::Event::TextEntered){
//
//if(input_string.size()==11){
//continue;
//}
//char x = event.text.unicode;
//int val = x;
//if((97 <= val && val <= 122) || (65 <= val && val <= 90)){
//input_string.pop_back();
//if(input_string.size() > 10){
//continue;
//}
//else {
//input_string = input_string + x + suffix;
//for(int i = 0; i < input_string.size()-1;i++){
//if(i==0){
//input_string[0] = toupper(input_string[0]);
//}
//else(input_string[i] = tolower(input_string[i]));
//}
//name_text.setString(input_string);
//int num = 10 * ( input_string.size()-1);
//name_text.setOrigin( -400 + num,-300);
//}
//}
//}
//}
//welcome_window.clear();
//welcome_window.draw(rectangle);
//welcome_window.draw(prompt);
//welcome_window.draw(text);
//welcome_window.draw(name_text);
//welcome_window.display();
//}
//
//
//
//
//
//GameTiles game;
//game.create_tile_plane();
//game.add_mines();
//sf::RenderWindow game_window(sf::VideoMode(game.num_columns*32, game.num_rows*32+100), "Minesweeper");
//sf::RectangleShape rectangle2(sf::Vector2f(game.num_columns*32, game.num_rows*32+100));
//rectangle.setFillColor(sf::Color(161,173,176));
//
//
//std::vector<sf::Sprite> digits;
//
//
//sf::Texture digit_0;
//digit_0.loadFromFile("files/images/digits.png", sf::IntRect(0,0,21,32));
//sf::Sprite zero;
//zero.setTexture(digit_0);
//digits.push_back(zero);
//
//sf::Texture one_text;
//one_text.loadFromFile("files/images/digits.png", sf::IntRect(21,0,21,32));
//sf::Sprite one;
//one.setTexture(one_text);
//digits.push_back(one);
//
//sf::Sprite two;
//sf::Texture two_text;
//two_text.loadFromFile("files/images/digits.png", sf::IntRect(42,0,21,32));
//two.setTexture(two_text);
//digits.push_back(two);
//
//sf::Sprite three;
//sf::Texture three_text;
//three_text.loadFromFile("files/images/digits.png", sf::IntRect(63,0,21,32));
//three.setTexture(three_text);
//digits.push_back(three);
//
//sf::Sprite four;
//sf::Texture four_text;
//four_text.loadFromFile("files/images/digits.png", sf::IntRect(84,0,21,32));
//four.setTexture(four_text);
//digits.push_back(four);
//
//sf::Sprite five;
//sf::Texture five_text;
//five_text.loadFromFile("files/images/digits.png", sf::IntRect(105,0,21,32));
//five.setTexture(five_text);
//digits.push_back(five);
//
//sf::Sprite six;
//sf::Texture six_text;
//six_text.loadFromFile("files/images/digits.png", sf::IntRect(126,0,21,32));
//six.setTexture(six_text);
//digits.push_back(six);
//
//sf::Sprite seven;
//sf::Texture seven_text;
//seven_text.loadFromFile("files/images/digits.png", sf::IntRect(147,0,21,32));
//seven.setTexture(seven_text);
//digits.push_back(seven);
//
//sf::Sprite eight;
//sf::Texture eight_text;
//eight_text.loadFromFile("files/images/digits.png", sf::IntRect(168,0,21,32));
//eight.setTexture(eight_text);
//digits.push_back(eight);
//
//sf::Sprite nine;
//sf::Texture nine_text;
//nine_text.loadFromFile("files/images/digits.png", sf::IntRect(189,0,21,32));
//nine.setTexture(nine_text);
//digits.push_back(nine);
//
//sf::Sprite minus;
//sf::Texture minus_text;
//minus_text.loadFromFile("files/images/digits.png", sf::IntRect(210,0,21,32));
//minus.setTexture(minus_text);
//digits.push_back(minus);
//
//
//
//
//
//sf::Texture flag_texture;
//flag_texture.loadFromFile("files/images/flag.png");
//sf::Sprite flag;
//flag.setTexture(flag_texture);
//
//std::map <int, bool> flag_position;
//
//
//sf::Sprite tile_cover;
//sf::Texture texture;
//sf::Texture tile_cover_texture;
//tile_cover_texture.loadFromFile("files/images/tile_hidden.png");
//tile_cover.setTexture(tile_cover_texture);
//texture.loadFromFile("files/images/tile_hidden.png");
//sf::Sprite sprite;
//sprite.setTexture(texture);
//std::vector<bool> tiles_covered;
//for (int i = 0; i< game.num_columns*game.num_rows;i++){
//tiles_covered.push_back(true);
//}
//float y = 0;
//bool Reveal_mines = false;
//float x = 0;
//sprite.setOrigin(x,y);
//int flag_counter = 0;
//int counter =0;
//int index;
//int position_x, position_y;
//int minutes;
//int seconds;
//int num_flags = game.num_mines;
//std::string number;
//
//sf::Texture mine_texture;
//mine_texture.loadFromFile("files/images/mine.png");
//sf::Sprite MINE;
//MINE.setTexture(mine_texture);
//
//
//sf::Texture happy_face_texture;
//happy_face_texture.loadFromFile("files/images/face_happy.png");
//
//sf::Texture win_face_texture;
//win_face_texture.loadFromFile("files/images/face_win.png");
//
//sf::Texture loose_face_texture;
//loose_face_texture.loadFromFile("files/images/face_lose.png");
//
//sf::Sprite face;
//face.setTexture(happy_face_texture);
////game.num_columns*32 / 2.0) * -32, -32*game.num_rows*32+100+0.5f
//face.setOrigin( (-1*game.num_columns*32/2)+32,-1*(game.num_rows*32+16));
//
//sf::Sprite play;
//sf::Texture play_button;
//play_button.loadFromFile("files/images/play.png"); play.setTexture(play_button);
//play.setOrigin((-1*game.num_columns*32/2)+32-224,-1*(game.num_rows*32+16));
//
//sf::Sprite pause;
//sf::Texture pause_button;
//pause_button.loadFromFile("files/images/pause.png"); pause.setTexture(pause_button);
//pause.setOrigin((-1*game.num_columns*32/2)+32-160,-1*(game.num_rows*32+16));
//int debug_x = (-1*game.num_columns*32/2)+32-160;
//int debug_y = -1*(game.num_rows*32+16);
//sf::Sprite debug;
//sf::Texture debug_button;
//debug_button.loadFromFile("files/images/debug.png"); debug.setTexture(debug_button);
//debug.setOrigin((-1*game.num_columns*32/2)+32-96,-1*(game.num_rows*32+16));
//
//std::cout<<debug_x*-1<<" "<<debug_y*-1<<std::endl;
//
//
//
//
//sf::RectangleShape rectangle45(sf::Vector2f(game.num_columns*32, game.num_rows*32+100));
//rectangle.setFillColor(sf::Color(168,173,176,255));
//rectangle45.setOrigin(0,0);
////    for (int i = 0; i < game.num_columns*game.num_rows; i++){
////        if( i % 25 == 0 && i != 0) {
////            std::cout << std::endl;
////        }
////        if(game.tiles[i].tile_type == 'M'){
////            std::cout<<"M ";
////        }
////        else{
////            std::cout<<game.tiles[i].surrounding_mines<<" ";
////        }
////    }
//
//std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
//std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
//
//std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
//std::cout<<time_span.count()<<std::endl;
//
//
////CREATING THE DIGITS AND THEIR PLACES
//auto minutes_tens = digits;
//auto minutes_ones = digits;
//auto seconds_tens = digits;
//auto seconds_ones = digits;
//
//auto counter_hundreds = digits;
//auto counter_tens = digits;
//auto counter_ones = digits;
//for(int i = 0; i< digits.size(); i++){
//counter_hundreds[i].setOrigin(-33,-1*(game.num_rows*32+16)-16);
//counter_tens[i].setOrigin(-54,-1*(game.num_rows*32+16)-16);
//counter_ones[i].setOrigin(-75,-1*(game.num_rows*32+16)-16);
//
//minutes_tens[i].setOrigin(-1*game.num_columns*32+97,-1*(game.num_rows*32+16)-16);
//minutes_ones[i].setOrigin(-1*game.num_columns*32+76,-1*(game.num_rows*32+16)-16);
//seconds_tens[i].setOrigin(-1*game.num_columns*32+54,-1*(game.num_rows*32+16)-16);
//seconds_ones[i].setOrigin(-1*game.num_columns*32+33,-1*(game.num_rows*32+16)-16);
//}
//
//
//while(game_window.isOpen()){
//sf::Event game_event;
//while(game_window.pollEvent(game_event)){
//if(game_event.type == sf::Event::EventType::Closed){
//game_window.close();
//}
//if(sf::Mouse::isButtonPressed(sf::Mouse::Right)){
//
//if(sf::Mouse::getPosition(game_window).y <= 32*game.num_rows){
//int f_index=floor((sf::Mouse::getPosition(game_window).x/32)+1)+(floor(sf::Mouse::getPosition(game_window).y/32))*game.num_columns-1;
//if(flag_position.find(f_index)!=flag_position.end() && flag_position[f_index]  && flag_counter <= 8) {
//flag_position[f_index]=false;
//}
//else if(!flag_position.find(f_index)->second){
//flag_position[f_index]=true;
//}
//}
//
//}
//if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
//std::cout<<"("<<(sf::Mouse::getPosition(game_window).x)<<", "<<(sf::Mouse::getPosition(game_window).y)<<")"<<std::endl;
//
//position_x = sf::Mouse::getPosition(game_window).x;
//position_y = sf::Mouse::getPosition(game_window).y;
//
//if(sf::Mouse::getPosition(game_window).y <= 32*game.num_rows){
//index = floor((sf::Mouse::getPosition(game_window).x/32)+1)+(floor(sf::Mouse::getPosition(game_window).y/32))*game.num_columns-1;
//if(flag_position.find(index)!=flag_position.end() && flag_position[index]){
//
//}
//else{
//tiles_covered[index] = false;
//game.reveal_nearby_zeros(tiles_covered,index);
//}
//
//}
//if(position_x <= debug_x*-1 && (debug_x*-1)-64<= position_x && position_y>= debug_y*-1 && position_y <= debug_y*-1+64){
//if(!Reveal_mines){
//Reveal_mines = true;
//}
//else if(Reveal_mines){
//Reveal_mines = false;
//}
//}
//
//
//}
////implement clicking
//}
//game_window.clear();
//game_window.draw(rectangle45);
//
//x=0,y = 0,counter = 0;
//for(int d = 0;d<game.num_columns*game.num_rows;d++){
//if(game.tiles[d].tile_type == 'M'){
//texture.loadFromFile("files/images/mine.png");
//sprite.setTexture(texture);
//}
//else{
//number = std::to_string(game.tiles[d].surrounding_mines);
//if(game.tiles[d].surrounding_mines == 0){
//texture.loadFromFile("files/images/tile_revealed.png");
//sprite.setTexture(texture);
//}
//else{
//texture.loadFromFile("files/images/number_"+number+".png");
//sprite.setTexture(texture);
//}
//}
//if(counter == game.num_columns-1){
//x = 0;
//y = y-32;
//counter =0;
//}
//else if (d != 0){
//x = x-32;
//counter ++;
//}
//sprite.setOrigin(x, y);
//game_window.draw(sprite);
//}
//x=0,y=0,counter=0;
//flag_counter=0;
//for(int i = 0; i < game.num_rows*game.num_columns;i++){
//if(counter == game.num_columns-1){
//x = 0;
//y = y-32;
//counter =0;
//}
//else if (i != 0){
//x = x-32;
//counter ++;
//}
//tile_cover.setOrigin(x, y);
//if(tiles_covered[i]){
//game_window.draw(tile_cover);
//}
//if(flag_position.find(i)!=flag_position.end() && flag_position[i] && tiles_covered[i] && flag_counter <= 8){
//flag_counter++;
//sf::Sprite sprite_flag_new = flag;
//sprite_flag_new.setOrigin(x,y);
//game_window.draw(sprite_flag_new);
//}
//if(Reveal_mines && game.tiles[i].tile_type == 'M'){
//sf::Sprite new_mine = MINE;
//new_mine.setOrigin(x,y);
//game_window.draw(new_mine);
//}
//}
//game_window.draw(counter_hundreds[0]);
//game_window.draw(counter_tens[0]);
//game_window.draw(counter_ones[0]);
//
//std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
//
//std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
//int tim_s = floor(time_span.count());
//std::vector<int> time_ele = get_time(tim_s);
//
//game_window.draw(minutes_tens[time_ele[0]]);
//game_window.draw(minutes_ones[time_ele[1]]);
//game_window.draw(seconds_tens[time_ele[2]]);
//game_window.draw(seconds_ones[time_ele[3]]);
//game_window.draw(debug);
//game_window.draw(play);
//game_window.draw(pause);
//game_window.draw(face);
//game_window.display();
//}