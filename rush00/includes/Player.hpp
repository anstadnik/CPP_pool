/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamoza <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 11:42:08 by skamoza           #+#    #+#             */
/*   Updated: 2018/04/07 21:48:44 by skamoza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Entity.hpp"
#include "Sprite.hpp"

class Player : public Entity {
    Vec2 _position;
    Vec2 _speed;
	Sprite<6, 6> _sprite;

   public:
    Player();
    Player(Vec2 pos);
    Player(const Player& other);
    ~Player();
    Player& operator=(const Player& other);
    void update(void);
    void move(Vec2);
    void push(Vec2);
    void draw(Curse& curse) const;
    Vec2 getSize(void) const;
    Vec2 getSpeed(void) const;
    Vec2 getPosition(void) const;
};
