#include "game.hpp"

#include <sstream>

void Game::update(float dtAsSeconds) {
    
    Eigen::Vector2f player_position = player.getPositionVector();
    Eigen::Vector2f player_velocity = player.getVelocity();
    Eigen::Vector2f player_acceleration = player.getAcceleration();
    sf::Vector2f player_collision = player.getCollisions();
    std::stringstream ss;
    ss << "position: (" << player_position[0] << ", " << player_position[1] << ")\n";
    ss << "velocity: (" << player_velocity[0] << ", " << player_velocity[1] << ")\n";
    ss << "acceleration: (" << player_acceleration[0] << ", " << player_acceleration[1] << ")\n";
    ss << "collision: (" << player_collision.x << ", " << player_collision.y << ")";
    hud_debug.setString(ss.str());

    checkPlayerCollisions();
    player.update(dtAsSeconds);

}
