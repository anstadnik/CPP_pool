/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamoza <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 12:01:23 by skamoza           #+#    #+#             */
/*   Updated: 2018/04/08 18:52:42 by skamoza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Entity.hpp"
#include "Sprite.hpp"

class Enemy : public Entity {
    Vec2 _position;
    Vec2 _speed;
    Sprite<3, 2> _sprite;
	int	_delay;

   public:
    Enemy();
    Enemy(Vec2 speed, Vec2 position);
    Enemy(Vec2 position, const char** sprite);
    Enemy(const Enemy& other);
    ~Enemy();
    Enemy& operator=(const Enemy& other);
    void update(void);
    void move(Vec2 dot);
    void push(Vec2 dot);
    void draw(Curse& curse) const;
    Vec2 getSize(void) const;
    Vec2 getSpeed(void) const;
    Vec2 getPosition(void) const;
};
