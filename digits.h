//
// Created by zeekd on 4/26/2023.
//

#include <SFML/Graphics.hpp>
#include<string>
#include<fstream>
#ifndef MINESWEEPER_DIGITS_H
#define MINESWEEPER_DIGITS_H

std::vector<int> get_time(int seconds_p){
    std::vector<int> times;
    if (seconds_p < 10){
        times.push_back(0);
        times.push_back(0);
        times.push_back(0);
        times.push_back(seconds_p);
        return times;
    }

    else if(seconds_p < 60){
        times.push_back(0);
        times.push_back(0);
        times.push_back((seconds_p/10)%10);
        times.push_back(seconds_p%10);
        return times;
    }
    else{
        int minutes_p = floor(seconds_p/60);
        times.push_back((minutes_p/10)%10);
        times.push_back(minutes_p%10);
        times.push_back(((seconds_p%60)/10)%10);
        times.push_back(seconds_p%10);
        return times;
    }

}
std::vector<int> get_flag_count(int num_flags){
    std::vector<int> flags;
    flags.push_back((num_flags/100)%10);
    flags.push_back((num_flags/10)%10);
    flags.push_back((num_flags%10));
    return flags;
}



std::vector<std::string> set_strings(std::string file_name){
    std::vector<std::string> people;
    std::string temp;
    std::fstream inFile(file_name, std::ios_base::in);
    for(int i =0; i<5;i++){
        std::getline(inFile, temp, ',');
        people.push_back(temp);
        inFile>>temp;
        people.push_back(temp);
    }
    return people;
}

//std::vector<std::string> create_leader_board_string(std::vector<std::string> strings){
//    std::string resultant_string = "";
//    std::vector<std::string> formatted_names;
//    resultant_string ="1.     "+strings[0]+"     "+strings[1]+"\n\n";
//    formatted_names.push_back(resultant_string);
//    resultant_string ="2.     "+strings[2]+"     "+strings[3]+"\n\n";
//    formatted_names.push_back(resultant_string);
//    resultant_string ="3.     "+strings[4]+"     "+strings[5]+"\n\n";
//    formatted_names.push_back(resultant_string);
//    resultant_string ="4.     "+strings[6]+"     "+strings[7]+"\n\n";
//    formatted_names.push_back(resultant_string);
//    resultant_string ="5.     "+strings[8]+"     "+strings[9];
//    formatted_names.push_back(resultant_string);
//    return formatted_names;
//}


#endif //MINESWEEPER_DIGITS_H
