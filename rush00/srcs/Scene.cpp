/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scene.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamoza <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 14:49:35 by skamoza           #+#    #+#             */
/*   Updated: 2018/04/08 20:54:33 by skamoza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scene.hpp"

Scene::Scene()
	: _player(Vec2(_curse.getWidth() / 2 - 5, _curse.getHeight() - 12)),
	end(false) {
		for (int i = 0; i < 1000; i++) {
			this->_earr[i] = nullptr;
			this->_barr[i] = nullptr;
		}
		std::srand(std::clock());
	}

Scene::Scene(const Scene& other) : _player(other._player) {
	for (int i = 0; i < 1000; i++) {
		this->_earr[i] = other._earr[i];
		this->_barr[i] = other._barr[i];
	}
}

Scene::~Scene() {
	for (int i = 0; i < 1000; i++) {
		if (_earr[i])
			delete (_earr[i]);
		if (_barr[i])
			delete (_barr[i]);
	}
}

Scene& Scene::operator=(const Scene& other) {
	this->_player = other._player;
	for (int i = 0; i < 1000; i++) {
		if (_earr[i])
			delete (_earr[i]);
		if (_barr[i])
			delete (_barr[i]);
	}
	for (int i = 0; i < 1000; i++) {
		this->_earr[i] = other._earr[i];
		this->_barr[i] = other._barr[i];
	}
	return (*this);
}

void Scene::_shoot(void) {
	int i = 0;
	Vec2 pos = _player.getPosition();

	pos += Vec2(1, -2);

	while (i < 1000 && _barr[i])
		i++;
	_barr[i] = new Bullet(pos);
	++i;
	pos += Vec2(3, 0);
	while (i < 1000 && _barr[i])
		i++;
	_barr[i] = new Bullet(pos);
}

void Scene::_shoot_enemy(Enemy* enemy) {
	int i = 0;
	Vec2 pos = enemy->getPosition();

	pos += Vec2(0, 5);
	while (i < 1000 && _barr[i])
		i++;
	_barr[i] = new Bullet(pos, Vec2(0, 1));
}

static bool check(Entity* e1, Entity* e2) {
	return ((((
			   e2->getPosition().getX() - e1->getPosition().getX() >= 0) &&
	 		  (e2->getPosition().getX() - e1->getPosition().getX() <=
	 		   e1->getSize().getX())) ||
			 ((e1->getPosition().getX() - e2->getPosition().getX() >= 0) &&
		      (e1->getPosition().getX() - e2->getPosition().getX() <=
			   e2->getSize().getX()))) &&  // X overlaps
			(((e2->getPosition().getY() - e1->getPosition().getY() >= 0) &&
			  (e2->getPosition().getY() - e1->getPosition().getY() <=
			   e1->getSize().getY())) ||
			 ((e1->getPosition().getY() - e2->getPosition().getY() >= 0) &&
			  (e1->getPosition().getY() - e2->getPosition().getY() <=
			   e2->getSize().getY())))) /* Y overlaps */;
}

void Scene::getInput(void) {
	int key = getch();
	switch (key) {
		case KEY_DOWN:
		case 'j':
			_player.push(Vec2(0, 1));
			break;
		case KEY_UP:
		case 'k':
			_player.push(Vec2(0, -1));
			break;
		case KEY_LEFT:
		case 'h':
			_player.push(Vec2(-1, 0));
			break;
		case KEY_RIGHT:
		case 'l':
			_player.push(Vec2(1, 0));
			break;
		case ' ':
			_shoot();
			break;
		case 'q':
			end = true;
			break;
		default:
			_player.push(Vec2(0, 0));
			break;
	}
	Vec2 pos = _player.getPosition();

	if (pos.getX() > _curse.getWidth() - 8)
		_player.push(Vec2(-1, 0));
	if (pos.getX() < 2)
		_player.push(Vec2(1, 0));
	if (pos.getY() > _curse.getHeight() - 8)
		_player.push(Vec2(0, -1));
	if (pos.getY() < 2)
		_player.push(Vec2(0, 1));
}

void Scene::update(void) {
	static int c = 0;
	static int t = 100;
	if (++c == t) {
		c = 0;
		if (t > 20)
			t -= 10;
		int i = 0;
		while (_earr[i])
			if (i++ == 1000) {
				i = -1;
				break;
			}
		if (i != -1)
			_earr[i] = new Enemy(Vec2(std::rand() % 5 - 2, 1),
					Vec2(std::rand() % (_curse.getWidth()),
						-20));
	}
	for (int j = 0; j < 1000; j++) {
		if (_earr[j] && check(&this->_player, this->_earr[j]))
			end = true;
		if (_barr[j] && check(&this->_player, this->_barr[j]) &&
				_barr[j]->getSpeed().getY() > 0)
			end = true;
	}
	for (int i = 0; i < 1000; i++) {
		if (!_earr[i])
			continue;
		if (_earr[i]->getPosition().getX() < -2 ||
			_earr[i]->getPosition().getX() > this->_curse.getWidth() + 2 ||
			_earr[i]->getPosition().getY() > this->_curse.getHeight()) {
			delete _earr[i];
			_earr[i] = nullptr;
			continue;
		}
		for (int j = 0; j < 1000; j++) {
			if (!_barr[j])
				continue;
			if (check(_earr[i], _barr[j])) {
				delete _earr[i];
				delete _barr[j];
				_earr[i] = nullptr;
				_barr[j] = nullptr;
				break;
			}
		}
	}
	for (int i = 0; i < 1000; i++) {
		if (!_barr[i])
			continue;
		if (_barr[i]->getPosition().getY() < 0 ||
			_barr[i]->getPosition().getY() > this->_curse.getHeight()) {
			delete _barr[i];
			_barr[i] = nullptr;
			continue;
		}
		for (int j = i + 1; j < 1000; j++) {
			if (_barr[j] && check(_barr[i], _barr[j]) &&
				_barr[i]->getSpeed().getY() != _barr[j]->getSpeed().getY()) {
				delete _barr[i];
				delete _barr[j];
				_barr[i] = nullptr;
				_barr[j] = nullptr;
				break;
			}
		}
	}
	_player.update();
	for (int i = 0; i < 1000; i++) {
		if (this->_earr[i]) {
			if (!(std::rand() % 500))
				_shoot_enemy(_earr[i]);
			this->_earr[i]->update();
		}
		if (this->_barr[i])
			this->_barr[i]->update();
	}
}

void Scene::draw(void) {
	_curse.background();
	_player.draw(this->_curse);
	for (int i = 0; i < 1000; i++) {
		if (this->_earr[i])
			this->_earr[i]->draw(this->_curse);
		if (this->_barr[i])
			this->_barr[i]->draw(this->_curse);
	}
	border(0, 0, 0, 0, 0, 0, 0, 0);
	refresh();
}
