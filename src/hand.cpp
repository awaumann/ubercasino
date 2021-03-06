/*
 * File: hand.cpp
 */

#include "hand.h"

Hand::Hand()
{
    m_size = 0;
    m_points = 0;
}

int Hand::size() const { return m_size; }

Card Hand::card( int index ) const
{
    if( index < m_size )
        return m_cards[index];

    // TODO: create invalid card
    return Card( suit_t::hearts, rank_t::two );
}

/*
 * Function: points
 *
 * Gets the highest possible point count for the hand.
 *
 * @returns: hand point count
 */
int Hand::points() const
{
    int points = m_points;
    int n = m_size;
    for( int i = 0; i < n; ++i )
        if( m_cards[i].ace() )
            if( (points + 10) <= 21 )
                points += 10;

    return points;
}

/*
 * Function: blackjack
 *
 * Determines if the hand is a blackjack. Hand must have an
 * "ace" and a card of rank 10 (2 cards total) to be considered
 * a blackjack.
 *
 * @returns: true if hand is blackjack
 *           false otherwise
 */
bool Hand::blackjack() const
{
    if( m_size == 2 && m_points == 11 )
        return true;

    return false;
}

/*
 * Function: bust
 *
 * Determines if a hand is a bust.
 *
 * @ returns: true if hand busts
 *            false otherwise
 */
bool Hand::bust() const
{
    if( points() > 21 )
        return true;

    return false;
} 

/*
 * Function: add_card
 *
 * Adds a card to the hand and updates the hand point count.
 * Note: "ace" is always treated as 1 point here.
 *
 * @param card: card to be added to hand
 *
 * @returns true if successful
 *          false otherwise
 */
bool Hand::add_card( Card card )
{
    if( m_size < MAX_CARDS_PER_PLAYER )
    {
        m_cards[m_size++] = card;
        m_points = m_points + card.rank();
        return true;
    }

    return false;
}

/*
 * Function: reset
 *
 * Resets the hand.
 */
void Hand::reset()
{
    m_size = 0;
    m_points = 0;
}

