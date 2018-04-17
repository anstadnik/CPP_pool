/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scene.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamoza <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 14:32:41 by skamoza           #+#    #+#             */
/*   Updated: 2018/04/08 20:54:32 by skamoza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Player.hpp"
#include "Bullet.hpp"
#include "Enemy.hpp"

class Scene {
	Curse	_curse;
	Player	_player;
	Enemy	*_earr[1000];
	Bullet	*_barr[1000];

	void	_shoot(void);
	void	_shoot_enemy(Enemy *);
   public:
	bool	end;

    Scene();
    Scene(const Scene& other);
    ~Scene();
    Scene& operator=(const Scene& other);
	void getInput(void);
    void update(void);
    void draw(void);
};
