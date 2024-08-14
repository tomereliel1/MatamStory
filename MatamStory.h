
#pragma once

#include <iostream>
#include <vector>
#include <memory>


#include "Players/Player.h"
#include "Events/Event.h"
#include "Players/JobFactory.h"
#include "Players/CharacterFactory.h"
#include "Events/EventFactory.h"


using std::shared_ptr;
using std::unique_ptr;
using std::string;


class MatamStory{
private:
    unsigned int m_turnIndex;

    //Factories
    JobFactory jobFactory;
    CharacterFactory characterFactory;
    EventFactory eventFactory;

    //Data storages
    std::vector<std::shared_ptr<Player>> m_players;
    std::vector<std::unique_ptr<Event>> m_events;
    std::vector<std::shared_ptr<Player>> m_leaderBoard;


    /**
     * Creates a player by reading from the input stream.
     *
     * @param playersStream - input stream to read player's data from.
     * @return - shared pointer to the created Player object.
     */
    std::shared_ptr<Player> createPlayer(std::istream& playersStream);


    /**
     * Creates a event by reading from the input stream.
     *
     * @param eventsStream - input stream to read events data from.
     * @return - uniqe pointer to the created event object.
     */
    std::unique_ptr<Event> createEvent(std::istream& eventsStream);


    /**
     * Playes a single turn for a player
     *
     * @param player - the player to play the turn for
     *
     * @return - void
    */
    void playTurn(Player& player);


    /**
     * Plays a single round of the game
     *
     * @return - void
    */
    void playRound();


    /**
     * Checks if the game is over
     *
     * @return - true if the game is over, false otherwise
    */
    bool isGameOver() const;

public:
    /**
     * Constructor of MatamStory class
     *
     * @param eventsStream - events input stream (file)
     * @param playersStream - players input stream (file)
     *
     * @return - MatamStory object with the given events and players
     *
    */
    MatamStory(std::istream& eventsStream, std::istream& playersStream);


    /**
     * Plays the entire game
     *
     * @return - void
    */
    void play();


    /**
     * checks if there is a winner
     *
     * @return - true if there is a winner false otherwise
     *
    */
    bool hasWinner() const;


    /**
     * return the winner if there is one
     *
     * @return - shared pointer to the winner player
     *
    */
    std::shared_ptr<Player> getWinner() const;
};
