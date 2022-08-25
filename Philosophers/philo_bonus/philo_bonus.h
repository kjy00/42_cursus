/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyokim <jiyokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 17:52:34 by jiyokim           #+#    #+#             */
/*   Updated: 2022/08/08 17:52:35 by jiyokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <semaphore.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <signal.h>

# define FORK "has taken a \x1b[33mfork\x1b[0m"
# define EAT "is \x1b[32meating\x1b[0m"
# define SLEEP "is sleeping"
# define THINK "\x1b[34mis thinking\x1b[0m"
# define DIED "\x1b[31mdied\x1b[0m"

typedef struct s_rules
{
	int			*pid;
	int			philos_num;
	int			time2die;
	int			time2eat;
	int			time2slp;
	int			must_eat;
	long long	start;
	pthread_t	mnt_flag;
	pthread_t	mnt_endppl;
	sem_t		*fork;
	sem_t		*print;
	sem_t		*end_flag;
	sem_t		*end_people;
}			t_rules;

typedef struct s_philo
{
	int				id;
	int				cnt;
	long long		last_eat;
	t_rules			*r;
	pthread_t		mnt_die;
	pthread_mutex_t	mtx;
}			t_philo;

/*parsing.c*/
int			parsing(int argc, char **argv, t_rules *rules);

/*initialize.c*/
void		initialize(t_rules *rules, t_philo *philos);

/*simulation.c*/
void		simulation(t_rules *rules, t_philo *philos);

/*dining.c*/
void		get_fork(t_rules *rules, t_philo *philo);
void		eating(t_rules *rules, t_philo *philo);
void		sleeping(t_rules *rules, t_philo *philo);
void		thinking(t_rules *rules, t_philo *philo);

/*utils.c*/
long long	getcurtime(void);
void		print_stat(t_rules *rules, t_philo *p, char *stat);
void		sleep_ms(long long ms, long long start);

#endif
