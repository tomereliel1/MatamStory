
#include "MatamStory.h"

#include "Utilities.h"

#include <algorithm>
#include <fstream>
#include <sstream>

MatamStory::MatamStory(std::istream& eventsStream, std::istream& playersStream)
    : m_turnIndex(1), jobFactory(), characterFactory(), eventFactory() {
    int playersNum = 0;
    try {
        while (playersStream) {
            std::shared_ptr<Player> player = createPlayer(playersStream);
            if (player) {
                m_players.push_back(player);
                playersNum++;
            }
        }

        if (playersNum < 2 || playersNum > 6) {
            throw std::runtime_error("Invalid Event File");
        }

        while (eventsStream) {
            std::unique_ptr<Event> event = createEvent(eventsStream);
            if (event) {
                m_events.push_back(std::move(event));
            }
        }
    }
    catch(const std::runtime_error& error) {
        throw error;
    }
}

std::shared_ptr<Player> MatamStory::createPlayer(std::istream& playersStream) {
    string name, jobType, characterType;

    try {
        playersStream >> name >> jobType ;

        std::shared_ptr<Job> job = jobFactory.create(jobType);
        std::shared_ptr<Character> character = characterFactory.create(characterType);

        return std::make_shared<Player>(name, job, character);
    } catch(const std::runtime_error& error) {
        throw error;
    }

}

std::unique_ptr<Event> MatamStory::createEvent(std::istream& eventsStream) {
    try {
        return eventFactory.create(eventsStream);
    }  catch(const std::runtime_error& error) {
        throw error;
    }
}


void MatamStory::playTurn(Player& player) {

    if (m_events.empty()) {
        // end the game
        return;
    }

    std::unique_ptr<Event>& currentEvent = m_events[m_turnIndex % m_events.size()];

    printTurnDetails(m_turnIndex, player, *currentEvent);

    string outcome = currentEvent->playEvent(player);

    printTurnOutcome(outcome);

    m_turnIndex++;
}

/**
 * Steps to implement (there may be more, depending on your design):
 * 1. Get the next event from the events list
 * 2. Print the turn details with "printTurnDetails"
 * 3. Play the event
 * 4. Print the turn outcome with "printTurnOutcome"
*/


void MatamStory::playRound() {

    printRoundStart();

    /*===== TODO: Play a turn for each player =====*/
    for (shared_ptr<Player>& player : m_players) {
        if (player->getHealthPoints()!= 0){
            playTurn(*player);
            m_turnIndex++;
        }
    }
    /*=============================================*/
    printRoundEnd();
    std::sort(m_leaderBoard.begin(), m_leaderBoard.end());
    printLeaderBoardMessage();
    int i = 1;
    for (shared_ptr<Player>& player : m_leaderBoard) {
        printLeaderBoardEntry(i, *player);
    }
    /*===== TODO: Print leaderboard entry for each player using "printLeaderBoardEntry" =====*/

    /*=======================================================================================*/
    printBarrier();
}

bool MatamStory::isGameOver() const {
    bool allHpZeros = true;
    for (const shared_ptr<Player>& player : m_players) {
        if (player->getLevel() == 10){
            return true;
        }
        if (player->getHealthPoints() != 0){
            allHpZeros = false;
        }
    }
    return allHpZeros;
}

void MatamStory::play() {

    printStartMessage();

    for (int i = 0 ; i < m_players.size() ; i++) {
        printStartPlayerEntry(i+1,*m_players[i]);
    }

    printBarrier();

    while (!isGameOver()) {
        playRound();
    }

    printGameOver();

    if (hasWinner()) {
        printWinner(*getWinner());
    } else {
        printNoWinners();
    }

}

bool MatamStory::hasWinner() const {}

std::shared_ptr<Player> MatamStory::getWinner() const {}



