/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sprite.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamoza <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 12:09:38 by skamoza           #+#    #+#             */
/*   Updated: 2018/04/07 16:50:28 by skamoza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Curse.hpp"
#include "Vec2.hpp"

template <int width, int height>
class Sprite {
   private:
    unsigned char _array[height][width];

   public:
    Sprite() {}

    Sprite(const Sprite& other) {
	for (int i = 0; i < height; ++i)
	    for (int j = 0; j < width; ++j) {
		_array[i][j] = other._array[i][j];
	    }
    }

    Sprite(const char** ptr) {
	for (int i = 0; i < height; ++i)
	    for (int j = 0; j < width; ++j) {
		_array[i][j] = ptr[i][j];
	    }
    }
    ~Sprite() {}
    Sprite& operator=(const Sprite& other);
    void draw(const Vec2& offs, Curse& curse) const {
	for (int i = 0; i < height; ++i)
	    for (int j = 0; j < width; ++j) {
		curse.putchar(Vec2(offs.getX() + j, offs.getY() + i),
			      _array[i][j]);
	    }
    }
};
