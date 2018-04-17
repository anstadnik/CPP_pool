/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamoza <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 12:58:34 by skamoza           #+#    #+#             */
/*   Updated: 2018/04/08 19:00:20 by skamoza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bullet.hpp"

Bullet::Bullet() {}
Bullet::Bullet(const Bullet& other)
	: _position(other._position), _speed(other._speed), _delay(0) {}
	Bullet::~Bullet() {}
	Bullet& Bullet::operator=(const Bullet& other) {
		_position = other._position;
		return (*this);
	}

Bullet::Bullet(Vec2 pos) : _position(pos), _speed(0, -1), _delay(0) {}
Bullet::Bullet(Vec2 pos, Vec2 speed)
	: _position(pos), _speed(speed), _delay(0) {}

	void Bullet::update(void) {
		if (++this->_delay == 10) {
			this->_delay = 0;
			_position += _speed;
		}
	}

void Bullet::move(Vec2 dot) {
	_position = dot;
}

void Bullet::push(Vec2 dir) {
	_speed = dir;
}

void Bullet::draw(Curse& curse) const {
	attron(COLOR_PAIR(3 + _speed.getY()));
	curse.putchar(_position, '0');
	attron(COLOR_PAIR(1));
}

Vec2 Bullet::getSize(void) const {
	return (Vec2(1, 1));
}

Vec2 Bullet::getSpeed(void) const {
	return (_speed);
}

Vec2 Bullet::getPosition(void) const {
	return (_position);
}
