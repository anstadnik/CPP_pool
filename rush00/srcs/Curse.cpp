/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Curse.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamoza <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 10:59:21 by skamoza           #+#    #+#             */
/*   Updated: 2018/04/08 19:00:22 by skamoza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Curse.hpp"

const char background_sprite[] =
"              *               *                                           "
"*                                                                      *  "
"                                                                          "
"               *     *                                                    "
"                                                                          "
"*                       *                                      *          "
"                                                                          ";

Curse::Curse() {
	curse_init();
}

Curse::Curse(const Curse& other) {
	_width = other._width;
}

Curse::~Curse() {
	endwin();
}

Curse& Curse::operator=(const Curse& other) {
	_width = other._width;
	return (*this);
}

void Curse::curse_init(void) {
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	getmaxyx(stdscr, _height, _width);
	nodelay(stdscr, TRUE);
	start_color();
	init_pair(1, 2, 0);
	init_pair(2, 1, 0);
	init_pair(4, 3, 0);
	init_pair(3, 10, 0);
	attron(COLOR_PAIR(1));
	curs_set(0);
}

void Curse::resize(void) {
	getmaxyx(stdscr, _height, _width);
}

int Curse::getWidth(void) {
	return (_width);
}

int Curse::getHeight(void) {
	return (_height);
}

void Curse::refresh(void) {}

void Curse::putchar(Vec2 pos, char c) {
	mvaddch(pos.getY(), pos.getX(), c);
}

void Curse::clear(void) {
	move(0, 0);
	for (int i = 0; i < _width * _height; ++i)
		addch(' ');
}

void Curse::background(void) {
	resize();
	attron(COLOR_PAIR(3));
	move(0, 0);
	for (size_t i = 0; i < (_width * _height) / sizeof(background_sprite); ++i)
		printw(background_sprite);
	printw(background_sprite);
	attron(COLOR_PAIR(1));
}
