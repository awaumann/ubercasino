/*
 * Dealer.cpp
 * Created: 04/05/2018
 * Modified: 04/05/2018
 */

#include <string>
#include <iostream>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include "ccpp_ubercasino.h"

#include "card.h"

using namespace UberCasino;

int main( int argc, char ** argv )
{

    card somecard( suite_t::spades, card_kind::king, true );

    std::cout << "suit: " << somecard.suit() << std::endl
              << "rank: " << somecard.rank() << std::endl
              << "valid: " << somecard.valid() << std::endl;

    /*
    dealer d = dealer();
    PTR = &d;
    boost::uuids::uuid uid = boost::uuids::random_generator()();
    memcpy( d.dealer_struct.uid, &uid, sizeof( d.dealer_struct.uid ) );
    strncpy( d.dealer_struct.name, "Alejandro", sizeof( d.dealer_struct.name ) );

    boost::uuids::uuid game_uid = boost::uuids::random_generator()();
    memcpy( d.dealer_struct.game_uid, &game_uid, sizeof( d.dealer_struct.game_uid ) );

    std::cout << "UberCasino starting with an infinite deck." << std::endl;

    std::cout
        << "Dealer Name: Alejandro" << std::endl
        << "Dealer UID : " << uid << std::endl;

    std::cout
        << "Enter 'start' to begin an infinite shoe game" << std::endl
        << "Enter 'q' to exit" << std::endl;

    dealer_pub dp = dealer_pub();
    game_pub gp = game_pub();
    player_sub ps = player_sub();

    char user_input[100];
    while( std::cin.getline( user_input, sizeof( user_input ) ) )
    {
        if( user_input[0] == 'q' )
            break;

        // fltk callbacks will call this function with a string
        d.user_input( std::string( user_input ) );
    }
    */

    return 0;
}

