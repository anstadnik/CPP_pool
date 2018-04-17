/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vec.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamoza <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 13:09:31 by skamoza           #+#    #+#             */
/*   Updated: 2018/04/08 17:41:47 by skamoza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class Vec2 {
    int _x;
    int _y;

   public:
    Vec2();
    Vec2(int x, int y);
    Vec2(const Vec2&);
    ~Vec2();
    Vec2& operator=(const Vec2&);
    Vec2 operator+(Vec2& rhs);
    Vec2& operator+=(Vec2 rhs);
    Vec2 operator-(Vec2 rhs);
    void setX(int x);
    void setY(int y);
    int getX(void) const;
    int getY(void) const;
};
