/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vec2.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamoza <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 13:12:43 by skamoza           #+#    #+#             */
/*   Updated: 2018/04/08 17:41:39 by skamoza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vec2.hpp"

Vec2::Vec2() : _x(0), _y(0) {}
Vec2::Vec2(int x, int y) : _x(x), _y(y) {}
Vec2::Vec2(const Vec2& other) : _x(other._x), _y(other._y) {}
Vec2::~Vec2() {}
Vec2& Vec2::operator=(const Vec2& other) {
	_x = other._x;
	_y = other._y;
	return (*this);
}

Vec2 Vec2::operator+(Vec2& rhs) {
    return (Vec2(_x + rhs._x, _y + rhs._y));
}
Vec2& Vec2::operator+=(Vec2 rhs) {
	_x += rhs._x;
	_y += rhs._y;
	return (*this);
}
Vec2 Vec2::operator-(Vec2 rhs) {
    return (Vec2(_x + rhs._x, _y + rhs._y));
}
void Vec2::setX(int x) {
    _x = x;
}
void Vec2::setY(int y) {
    _x = y;
}
int Vec2::getX(void) const {
    return _x;
}
int Vec2::getY(void) const {
    return _y;
}
