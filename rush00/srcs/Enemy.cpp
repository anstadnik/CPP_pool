#include "Enemy.hpp"

const char* enemy_sprite[][2] = {
	{	"<@>",
		" | "
	},
	{	"\\@/",
		" | "
	},
	{	" W ",
		"|M|"
	},
	{	"|^|",
		">M<"
	},
};

Enemy::Enemy() {}
Enemy::Enemy(const Enemy& other)
	: _position(other._position),
	_speed(other._speed),
	_sprite(enemy_sprite[std::rand() % 4]) {}
	Enemy::~Enemy() {}
	Enemy& Enemy::operator=(const Enemy& other) {
		_position = other._position;
		return (*this);
	}

Enemy::Enemy(Vec2 speed, Vec2 position)
	: _position(position),
	_speed(speed),
	_sprite(enemy_sprite[std::rand() % 4]) {}

Enemy::Enemy(Vec2 position, const char** sprite)
	: _position(position), _sprite(sprite) {}

	void Enemy::update(void) {
		if (++this->_delay == 15) {
			this->_delay = 0;
			_position += _speed;
		}
	}

void Enemy::move(Vec2 dot) {
	_position = dot;
}

void Enemy::push(Vec2 dir) {
	_speed = dir;
}

void Enemy::draw(Curse& curse) const {
	_sprite.draw(_position, curse);
}

Vec2 Enemy::getSize(void) const {
	return (Vec2(3, 2));
}
Vec2 Enemy::getSpeed(void) const {
	return (_speed);
}
Vec2 Enemy::getPosition(void) const {
	return (_position);
}
