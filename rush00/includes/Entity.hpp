/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Entity.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamoza <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 11:21:15 by skamoza           #+#    #+#             */
/*   Updated: 2018/04/07 18:45:29 by skamoza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Curse.hpp"
#include "Vec2.hpp"

class Entity {
   public:
    virtual ~Entity(void) = 0;
    virtual void update(void) = 0;
    virtual void move(Vec2) = 0;
    virtual void push(Vec2) = 0;
    virtual void draw(Curse& curse) const = 0;
    virtual Vec2 getSize(void) const = 0;
    virtual Vec2 getSpeed(void) const = 0;
    virtual Vec2 getPosition(void) const = 0;
};

Curse& operator<<(Curse& lhs, const Entity& rhs);
