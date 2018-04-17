/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Curse.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamoza <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 10:56:06 by skamoza           #+#    #+#             */
/*   Updated: 2018/04/08 17:58:17 by skamoza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <curses.h>
#include <iostream>
#include <string>
#include "Vec2.hpp"

class Curse {
    int _width;
    int _height;

   public:
    Curse();
    Curse(const Curse& other);
    ~Curse();
    Curse& operator=(const Curse& other);
    void curse_init(void);
    void resize(void);
    void clear(void);
    void background(void);
    void refresh(void);
    int getWidth(void);
    int getHeight(void);
	void putchar(Vec2 pos, char c);
};
