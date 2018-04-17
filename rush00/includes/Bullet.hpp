/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamoza <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 12:05:45 by skamoza           #+#    #+#             */
/*   Updated: 2018/04/08 18:52:43 by skamoza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Entity.hpp"

class Bullet : public Entity {
    Vec2 _position;
    Vec2 _speed;
	int	_delay;

   public:
    Bullet();
    Bullet(const Bullet& other);
    ~Bullet();
    Bullet& operator=(const Bullet& other);
	Bullet(Vec2 pos, Vec2 speed);
    Bullet(Vec2 pos);
    void update(void);
    void move(Vec2 dot);
    void push(Vec2 dot);
    void draw(Curse& curse) const;
    Vec2 getSize(void) const;
    Vec2 getSpeed(void) const;
    Vec2 getPosition(void) const;
};
