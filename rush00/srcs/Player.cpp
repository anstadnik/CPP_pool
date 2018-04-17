/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamoza <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 11:54:32 by skamoza           #+#    #+#             */
/*   Updated: 2018/04/08 18:50:12 by skamoza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"

const char* player_sprite[] = {
    " |  | ",
	"-||||-", 
	"-|  |-",
	"-|  |-", 
	"-||||-", 
	" |  | "
};

Player::Player() : _sprite(player_sprite){}

Player::Player(const Player& other)  {
    *this = other;
}

Player::Player(Vec2 pos)
    : _position(pos), _sprite(player_sprite) {}

Player::~Player() {}

Player& Player::operator=(const Player& other) {
    _position = other._position;
    return (*this);
}

void Player::update(void) {
    _position += _speed;
}

void Player::push(Vec2 dir) {
    _speed = dir;
}

void Player::move(Vec2 point) {
    _position = point;
}

void Player::draw(Curse& curse) const {
    _sprite.draw(_position, curse);
}

Vec2 Player::getSize(void) const {
    return (Vec2(6, 6));
}

Vec2 Player::getSpeed(void) const {
    return (_speed);
}

Vec2 Player::getPosition(void) const {
    return (_position);
}
