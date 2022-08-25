/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyokim <jiyokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:22:37 by jiyokim           #+#    #+#             */
/*   Updated: 2022/07/28 15:22:59 by jiyokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

# define FORK "has taken a \x1b[33mfork\x1b[0m"
# define EAT "is \x1b[32meating\x1b[0m"
# define SLEEP "is sleeping"
# define THINK "\x1b[34mis thinking\x1b[0m"
# define DIED "\x1b[31mdied\x1b[0m"

typedef struct s_rules
{
	int				philos_num;
	int				time2die;
	int				time2eat;
	int				time2slp;
	int				must_eat;
	int				die_flag;
	int				end_people;
	long long		start;
	pthread_t		monitor_thread;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print_mtx;
	pthread_mutex_t	end_mtx;
	pthread_mutex_t	die_mtx;
}			t_rules;

typedef struct s_philo
{
	pthread_t		th;
	int				id;
	int				lfork;
	int				rfork;
	int				cnt;
	long long		last_eat;
	t_rules			*rules;
	pthread_mutex_t	philomtx;
}				t_philo;

/*parsing.c*/
int			parsing(int argc, char **argv, t_rules *rules);

/*initialize.c*/
int			initialize(t_philo *p, t_rules *r);
long long	getcurtime(void);

/*simulation.c*/
int			simulation(t_philo *p, t_rules *r);

/*utils.c*/
void		print_status(t_philo *p, char *status);
void		*monitor(void *philos);
int			is_finished(t_philo *p);
void		sleep_ms(long long ms, long long start);
int			dieflag(t_philo *p);
long long	get_last_eat(t_philo *p);

#endif
