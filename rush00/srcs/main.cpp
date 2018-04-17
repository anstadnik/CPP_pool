/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamoza <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 12:46:08 by skamoza           #+#    #+#             */
/*   Updated: 2018/04/08 20:52:24 by skamoza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <unistd.h>
#include "Curse.hpp"
#include "Player.hpp"
#include "Scene.hpp"

int main(void) {
	{
		Scene scene;
		while (!scene.end) {
			scene.getInput();
			scene.update();
			scene.draw();
			usleep(10000);
		}
	}
	std::cout << "THANK YOU FOR PLAYING" << std::endl;
}
