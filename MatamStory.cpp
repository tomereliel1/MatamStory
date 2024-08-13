
#include "MatamStory.h"

#include "Utilities.h"

#include <fstream>
#include <sstream>

MatamStory::MatamStory(std::istream& eventsStream, std::istream& playersStream)
    : m_turnIndex(1), jobFactory(), characterFactory(), eventFactory() {

    while (playersStream) {
         std::shared_ptr<Player> player = createPlayer(playersStream);
        if (player) {
            m_players.push_back(player);
        }
    }

    while (eventsStream) {
        std::unique_ptr<Event> event = createEvent(eventsStream);
        if (event) {
            m_events.push_back(event);
        }
    }
}


std::shared_ptr<Player> MatamStory::createPlayer(std::istream& playersStream) {
    string name, jobType, characterType;
    int level, force;

    playersStream >> name >> jobType >> characterType >> level >> force;

    std::shared_ptr<Job> job = jobFactory.create(jobType);
    std::shared_ptr<Character> character = characterFactory.create(characterType);

    return std::make_shared<Player>(name, job, character);
}


std::unique_ptr<Event> MatamStory::createEvent(std::istream& eventsStream) {
    return eventFactory.create(eventsStream);
}

/*
MatamStory::MatamStory(std::istream& eventsStream, std::istream& playersStream) {

    /*===== TODO: Open and read events file =====*/

    /*==========================================*/


    /*===== TODO: Open and Read players file =====*/

    /*============================================*/

/*
    this->m_turnIndex = 1;
}
*/


void MatamStory::playTurn(Player& player) {

    /**
     * Steps to implement (there may be more, depending on your design):
     * 1. Get the next event from the events list
     * 2. Print the turn details with "printTurnDetails"
     * 3. Play the event
     * 4. Print the turn outcome with "printTurnOutcome"
    */

    m_turnIndex++;
}

void MatamStory::playRound() {

    printRoundStart();

    /*===== TODO: Play a turn for each player =====*/

    /*=============================================*/

    printRoundEnd();

    printLeaderBoardMessage();

    /*===== TODO: Print leaderboard entry for each player using "printLeaderBoardEntry" =====*/

    /*=======================================================================================*/

    printBarrier();
}

bool MatamStory::isGameOver() const {
    /*===== TODO: Implement the game over condition =====*/
    return false; // Replace this line
    /*===================================================*/
}

void MatamStory::play() {
    printStartMessage();
    /*===== TODO: Print start message entry for each player using "printStartPlayerEntry" =====*/

    /*=========================================================================================*/
    printBarrier();

    while (!isGameOver()) {
        playRound();
    }

    printGameOver();
    /*===== TODO: Print either a "winner" message or "no winner" message =====*/

    /*========================================================================*/
}
