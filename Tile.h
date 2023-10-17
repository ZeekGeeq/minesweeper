//
// Created by zeekd on 4/17/2023.
//
#include<vector>
#include<SFML/Graphics.hpp>
#include<fstream>
#include<string>
#include<cstdlib>
#include<algorithm>
#ifndef MINESWEEPER_TILE_H
#define MINESWEEPER_TILE_H

struct Tile{
public:
    char tile_type;
    int surrounding_mines = 0;
    bool is_zero;
    std::vector<Tile>neighboring_tiles;
};

class GameTiles{
public:
    std::vector<Tile> tiles;
    std::vector<int>covered_indexes;
    int num_mines, num_rows,num_columns;
    GameTiles() {
        std::string buffer;
        std::fstream file("files/board_config.cfg", std::ios_base::in);
        getline(file, buffer);
        num_columns = stoi(buffer);
        getline(file, buffer);
        num_rows = stoi(buffer);
        getline(file, buffer);
        num_mines = stoi(buffer);
    }

    void create_tile_plane(){
        tiles.reserve(num_rows*num_columns);
        Tile element;
        for (int i = 0; i < num_columns*num_rows; i++){
            tiles.push_back(element);
            if(i == 0 || i == num_columns-1 || i == num_columns*num_rows -1 || i == num_columns* (num_rows-1)){
                tiles[i].tile_type = 'C';
            }
            else if(i % num_columns ==0 || i < num_columns-1 || i > num_columns*(num_rows-1) || i  % num_columns == num_columns - 1){
                tiles[i].tile_type = 'E';
            }
            else{
                tiles[i].tile_type = 'I';
            }
            //USED FOR DEBUGGING
//            if( i % 25 == 0 && i != 0){
//                std::cout<<std::endl;
//            }
//            std::cout<< tiles[i].tile_type << " ";
        }
    }
    void add_mines(){
        int mines_allocated = 0;
        std::vector<int> mine_locations;
        int randNum;
        std::cout<<"STARTING WHILE LOOP"<<std::endl;
        while(mines_allocated != num_mines){
            //the top left corner is left blank and will be the space to move a mine if the player clicks on one
            randNum = rand()%((num_rows*num_columns-1)-1 + 1) + 1;
            if(std::binary_search(mine_locations.begin(), mine_locations.end(), randNum)){
                continue;
            }
            else{
                mine_locations.push_back(randNum);
                mines_allocated++;
            }

        }
        std::cout<<"ENDING WHILE LOOP"<<std::endl;
        std::sort(mine_locations.begin(),mine_locations.end());
        int index;
        for(int ting = 0; ting < mine_locations.size(); ting++) {
            index = mine_locations[ting];
            if (tiles[index].tile_type == 'C') {
                if (index == 0) {
                    tiles[1].surrounding_mines++;
                    tiles[index + num_columns].surrounding_mines++;
                    tiles[index + num_columns + 1].surrounding_mines++;
                } else if (index == num_columns - 1) {
                    tiles[index - 1].surrounding_mines++;
                    tiles[index + num_columns].surrounding_mines++;
                    tiles[index + num_columns - 1].surrounding_mines++;
                } else if (index == (num_rows - 1) * num_columns) {
                    tiles[index + 1].surrounding_mines++;
                    tiles[index - num_columns].surrounding_mines++;
                    tiles[index - num_columns + 1].surrounding_mines++;
                } else if (index == num_rows * num_columns - 1) {
                    tiles[index - 1].surrounding_mines++;
                    tiles[index - num_columns].surrounding_mines++;
                    tiles[index - num_columns - 1].surrounding_mines++;
                }
            } else if (tiles[index].tile_type == 'E') {
                if (index < (num_columns - 1)) {
                    tiles[index - 1].surrounding_mines++;
                    tiles[index + 1].surrounding_mines++;

                    tiles[index + num_columns].surrounding_mines++;
                    tiles[index + num_columns + 1].surrounding_mines++;
                    tiles[index + num_columns - 1].surrounding_mines++;
                } else if (index > num_columns * (num_rows - 1)) {
                    tiles[index - 1].surrounding_mines++;
                    tiles[index + 1].surrounding_mines++;

                    tiles[index - num_columns].surrounding_mines++;
                    tiles[index - num_columns - 1].surrounding_mines++;
                    tiles[index - num_columns + 1].surrounding_mines++;
                } else if (index % num_columns == num_columns - 1) {
                    tiles[index - 1].surrounding_mines++;

                    tiles[index - num_columns - 1].surrounding_mines++;
                    tiles[index - num_columns].surrounding_mines++;

                    tiles[index + num_columns].surrounding_mines++;
                    tiles[index + num_columns - 1].surrounding_mines++;
                } else if (index % num_columns == 0) {
                    tiles[index + 1].surrounding_mines++;

                    tiles[index - num_columns].surrounding_mines++;
                    tiles[index - num_columns + 1].surrounding_mines++;

                    tiles[index + num_columns].surrounding_mines++;
                    tiles[index + num_columns + 1].surrounding_mines++;
                }
            } else if (tiles[index].tile_type == 'I') {
                tiles[index + 1].surrounding_mines++;
                tiles[index - 1].surrounding_mines++;

                tiles[index - num_columns].surrounding_mines++;
                tiles[index - num_columns - 1].surrounding_mines++;
                tiles[index - num_columns + 1].surrounding_mines++;

                tiles[index + num_columns].surrounding_mines++;
                tiles[index + num_columns + 1].surrounding_mines++;
                tiles[index + num_columns - 1].surrounding_mines++;
            }

            tiles[index].tile_type = 'M';
            //we will determine the type of tile C E I, and then add 1 to all surrounding tiles accordingly
        }
        for (int i = 0; i < num_columns*num_rows; i++){
           if(tiles[i].surrounding_mines ==0 && tiles[i].tile_type!= 'M'){
               tiles[i].is_zero = true;
           }
           else{
               tiles[i].is_zero = false;
           }
        }
    }
    void reveal_nearby_zeros(std::vector<bool> &booleans, int starting_index){
        if(std::find(covered_indexes.begin(), covered_indexes.end(), starting_index) != covered_indexes.end()){
            //Do nothing
        }
        else if(tiles[starting_index].surrounding_mines >=1){
            std::cout<<"number detected"<<std::endl;
            booleans[starting_index]=false;
            covered_indexes.push_back(starting_index);
        }
        else if(tiles[starting_index].tile_type == 'M'){
            covered_indexes.push_back(starting_index);
        }
        else if(tiles[starting_index].is_zero||tiles[starting_index].surrounding_mines>0){
            covered_indexes.push_back(starting_index);
            if(tiles[starting_index].tile_type == 'C'){
                if (starting_index == 0) {
                    if(tiles[1].is_zero){booleans[1] = false; reveal_nearby_zeros(booleans, 1);}
                    if(tiles[starting_index + num_columns].is_zero){booleans[starting_index+num_columns]=false; reveal_nearby_zeros(booleans,starting_index + num_columns);};
                    if(tiles[starting_index + num_columns + 1].is_zero){booleans[starting_index+num_columns+1] = false; reveal_nearby_zeros(booleans, starting_index + num_columns + 1);};
                } else if (starting_index == num_columns - 1) {
                    if(tiles[starting_index - 1].is_zero){booleans[starting_index - 1]=false; reveal_nearby_zeros(booleans,starting_index - 1);}
                    if(tiles[starting_index + num_columns].is_zero){booleans[starting_index + num_columns]=false; reveal_nearby_zeros(booleans,starting_index + num_columns);}
                    if(tiles[starting_index + num_columns - 1].is_zero){booleans[starting_index + num_columns - 1]=false;reveal_nearby_zeros(booleans,starting_index + num_columns - 1);}
                } else if (starting_index == (num_rows - 1) * num_columns) {
                    if(tiles[starting_index + 1].is_zero){booleans[starting_index + 1]=false;reveal_nearby_zeros(booleans, starting_index + 1);}
                    if(tiles[starting_index - num_columns].is_zero){booleans[starting_index - num_columns] = false;reveal_nearby_zeros(booleans,starting_index - num_columns);}
                    if(tiles[starting_index - num_columns + 1].is_zero){booleans[starting_index - num_columns + 1]=false;reveal_nearby_zeros(booleans,starting_index - num_columns + 1);}
                } else if (starting_index == num_rows * num_columns - 1) {
                    if(tiles[starting_index - 1].is_zero){booleans[starting_index - 1]=false;reveal_nearby_zeros(booleans,starting_index - 1);}
                    if(tiles[starting_index - num_columns].is_zero){booleans[starting_index - num_columns]=false;reveal_nearby_zeros(booleans,starting_index - num_columns);}
                    if(tiles[starting_index - num_columns - 1].is_zero){booleans[starting_index - num_columns - 1]=false;reveal_nearby_zeros(booleans,starting_index - num_columns - 1);}
                }
            }
            else if(tiles[starting_index].tile_type == 'E'){
                if (starting_index < (num_columns - 1)) {
                    if(tiles[starting_index - 1].is_zero){booleans[starting_index - 1]=false;reveal_nearby_zeros(booleans,starting_index-1);}
                    else if(tiles[starting_index-1].surrounding_mines>0){booleans[starting_index-1]=false;}
                    if(tiles[starting_index + 1].is_zero){booleans[starting_index+1]=false;reveal_nearby_zeros(booleans,starting_index+1);}
                    else if(tiles[starting_index+1].surrounding_mines>0){booleans[starting_index+1]=false;}

                    if(tiles[starting_index + num_columns].is_zero){booleans[starting_index + num_columns]=false;reveal_nearby_zeros(booleans,starting_index + num_columns);}
                    else if(tiles[starting_index + num_columns].surrounding_mines>0){booleans[starting_index + num_columns]=false;}
                    if(tiles[starting_index + num_columns + 1].is_zero){booleans[starting_index + num_columns + 1]=false;reveal_nearby_zeros(booleans,starting_index + num_columns + 1);}
                    if(tiles[starting_index + num_columns - 1].is_zero){booleans[starting_index + num_columns - 1]=false;reveal_nearby_zeros(booleans,starting_index + num_columns - 1);}
                } else if (starting_index > num_columns * (num_rows - 1)) {
                    if(tiles[starting_index - 1].is_zero){booleans[starting_index - 1]=false;reveal_nearby_zeros(booleans,starting_index - 1);}
                    else if(tiles[starting_index-1].surrounding_mines>0){booleans[starting_index-1]=false;}
                    if(tiles[starting_index + 1].is_zero){booleans[starting_index + 1]=false;reveal_nearby_zeros(booleans,starting_index + 1);}
                    else if(tiles[starting_index+1].surrounding_mines>0){booleans[starting_index+1]=false;}

                    if(tiles[starting_index - num_columns].is_zero){booleans[starting_index - num_columns]=false;reveal_nearby_zeros(booleans,starting_index - num_columns);}
                    else if(tiles[starting_index - num_columns].surrounding_mines>0){booleans[starting_index - num_columns]=false;}
                    if(tiles[starting_index - num_columns - 1].is_zero){booleans[starting_index - num_columns - 1]=false;reveal_nearby_zeros(booleans,starting_index - num_columns - 1);}
                    if(tiles[starting_index - num_columns + 1].is_zero){booleans[starting_index - num_columns + 1]=false;reveal_nearby_zeros(booleans,starting_index - num_columns + 1);}
                } else if (starting_index % num_columns == num_columns - 1) {
                    if(tiles[starting_index - 1].is_zero){booleans[starting_index - 1]=false;reveal_nearby_zeros(booleans,starting_index - 1);}
                    else if(tiles[starting_index-1].surrounding_mines>0){booleans[starting_index-1]=false;}

                    if(tiles[starting_index - num_columns - 1].is_zero){booleans[starting_index - num_columns - 1]=false;reveal_nearby_zeros(booleans, starting_index - num_columns - 1);}

                    if(tiles[starting_index - num_columns].is_zero){booleans[starting_index - num_columns]=false;reveal_nearby_zeros(booleans, starting_index - num_columns);}
                    else if(tiles[starting_index - num_columns].surrounding_mines>0){booleans[starting_index - num_columns]=false;}

                    if(tiles[starting_index + num_columns].is_zero){booleans[starting_index + num_columns]=false;reveal_nearby_zeros(booleans, starting_index + num_columns);}
                    else if(tiles[starting_index + num_columns].surrounding_mines>0){booleans[starting_index + num_columns]=false;}

                    if(tiles[starting_index + num_columns - 1].is_zero){booleans[starting_index + num_columns - 1]=false;reveal_nearby_zeros(booleans, starting_index + num_columns - 1);}
                } else if (starting_index % num_columns == 0) {
                    if(tiles[starting_index + 1].is_zero){booleans[starting_index + 1]=false;reveal_nearby_zeros(booleans,starting_index + 1);}
                    else if(tiles[starting_index+1].surrounding_mines>0){booleans[starting_index+1]=false;}

                    if(tiles[starting_index - num_columns].is_zero){booleans[starting_index - num_columns]=false;reveal_nearby_zeros(booleans,starting_index - num_columns);}
                    else if(tiles[starting_index-num_columns].surrounding_mines>0){booleans[starting_index-num_columns]=false;}
                    if(tiles[starting_index - num_columns + 1].is_zero){booleans[starting_index - num_columns + 1]=false;reveal_nearby_zeros(booleans,starting_index - num_columns + 1);}

                    if(tiles[starting_index + num_columns].is_zero){booleans[starting_index + num_columns]=false;reveal_nearby_zeros(booleans,starting_index + num_columns);}
                    else if(tiles[starting_index+num_columns].surrounding_mines>0){booleans[starting_index+num_columns]=false;}
                    if(tiles[starting_index + num_columns + 1].is_zero){booleans[starting_index + num_columns + 1]=false;reveal_nearby_zeros(booleans, starting_index + num_columns + 1);}
                }
            }
            else if(tiles[starting_index].tile_type == 'I'){
                if(tiles[starting_index + 1].is_zero){booleans[starting_index + 1]=false;reveal_nearby_zeros(booleans,starting_index + 1);}
                else if(tiles[starting_index+1].surrounding_mines>0){booleans[starting_index+1]=false;}
                if(tiles[starting_index - 1].is_zero){booleans[starting_index - 1]=false;reveal_nearby_zeros(booleans,starting_index - 1);}
                else if(tiles[starting_index-1].surrounding_mines>0){booleans[starting_index-1]=false;}

                if(tiles[starting_index - num_columns].is_zero){booleans[starting_index - num_columns]=false;reveal_nearby_zeros(booleans,starting_index - num_columns);}
                else if(tiles[starting_index - num_columns].surrounding_mines>0){booleans[starting_index - num_columns]= false;}
                if(tiles[starting_index - num_columns - 1].is_zero){booleans[starting_index - num_columns-1]=false;reveal_nearby_zeros(booleans,starting_index - num_columns-1);}
                else if(tiles[starting_index-num_columns-1].surrounding_mines>0){booleans[starting_index - num_columns-1]=false;}
                if(tiles[starting_index - num_columns + 1].is_zero){booleans[starting_index - num_columns + 1]=false;reveal_nearby_zeros(booleans,starting_index - num_columns + 1);}
                else if(tiles[starting_index - num_columns+1].surrounding_mines>0){booleans[starting_index - num_columns+1]=false;}

                if(tiles[starting_index + num_columns].is_zero){booleans[starting_index + num_columns]=false;reveal_nearby_zeros(booleans,starting_index + num_columns);}
                else if(tiles[starting_index + num_columns].surrounding_mines>0){booleans[starting_index + num_columns]=false;}
                if(tiles[starting_index + num_columns + 1].is_zero){booleans[starting_index + num_columns + 1]=false;reveal_nearby_zeros(booleans,starting_index + num_columns + 1);}
                else if(tiles[starting_index + num_columns + 1].surrounding_mines>0){booleans[starting_index + num_columns + 1]=false;}
                if(tiles[starting_index + num_columns - 1].is_zero){booleans[starting_index + num_columns - 1]=false;reveal_nearby_zeros(booleans,starting_index + num_columns - 1);}
                else if(tiles[starting_index + num_columns - 1].surrounding_mines>0){booleans[starting_index + num_columns - 1]=false;}
            }
        }
    }
};
#endif //MINESWEEPER_TILE_H
