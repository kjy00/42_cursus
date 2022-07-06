/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyokim <jiyokim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:40:48 by jiyokim           #+#    #+#             */
/*   Updated: 2022/06/19 20:03:51 by jiyokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libft.h"
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_info
{
	unsigned char	*str;
	pid_t			server_pid;
}				t_info;

void	ft_error(const char *str);

#endif
