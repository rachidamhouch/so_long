/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 21:44:14 by ramhouch          #+#    #+#             */
/*   Updated: 2022/11/26 22:35:54 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	win(void)
{
	putstr("\n\n##    ##  #######  ##     ##    ##      ## #### ##    ##\n\
 ##  ##  ##     ## ##     ##    ##  ##  ##  ##  ###   ##\n \
 ####   ##     ## ##     ##    ##  ##  ##  ##  ####  ##\n \
  ##    ##     ## ##     ##    ##  ##  ##  ##  ## ## ##\n \
  ##    ##     ## ##     ##    ##  ##  ##  ##  ##  ####\n \
  ##    ##     ## ##     ##    ##  ##  ##  ##  ##   ###\n \
  ##     #######   #######      ###  ###  #### ##    ## \n");
	exit(0);
}

void	printrror(void)
{
	putstr("Error\n");
	putstr("\n\n##     ##    ###    ########     ####  ######\
     ##    ##  #######  ########    ##     ##    ###    ##       #### ########  \n\
###   ###   ## ##   ##     ##     ##  ##    ##    ###   ## #\
      ##    ##       ##     ##   ## ##   ##        ##  ##     ## \n\
#### ####  ##   ##  ##     ##     ##  ##          ####  ## ##\
     ##    ##       ##     ##  ##   ##  ##        ##  ##     ## \n\
## ### ## ##     ## ########      ##   ######     ## ## ## ##\
     ##    ##       ##     ## ##     ## ##        ##  ##     ## \n\
##     ## ######### ##            ##        ##    ##  #### ##\
     ##    ##        ##   ##  ######### ##        ##  ##     ## \n\
##     ## ##     ## ##            ##  ##    ##    ##   ###\
 ##     ##    ##         ## ##   ##     ## ##        ##  ##     ## \n\
##     ## ##     ## ##           ####  ######     ##    ##\
  #######     ##          ###    ##     ## ######## #### ########  \n");
	exit(1);
}