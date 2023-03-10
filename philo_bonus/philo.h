/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 10:57:15 by abouabra          #+#    #+#             */
/*   Updated: 2023/01/30 16:29:59 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <fcntl.h>
# include <limits.h>
# include <pthread.h>
# include <semaphore.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct t_args
{
	int				n_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				n_times_must_eat;

	time_t			initial_time;
	int				id;

	int				kill_yourself;
	long			eating_times;
	long			eating_duration;

	sem_t			*forks;
	sem_t			*print;
}					t_args;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

enum
{
	IS_TAKING_FORK,
	IS_EATING,
	IS_SLEEPING,
	IS_THINKING,
	IS_DEAD,
	IS_FULL,
};

int					ft_atoi(const char *str);
int					check_args(t_args *vars, char **av);
void				make_philos(t_args *vars);
void				*handle_philo(void *arg);
long				get_interval(time_t before, time_t after);
long				get_time(void);
void				ft_usleep(t_args *vars, int time);
int					is_full(t_args *vars);
void				print_status(t_args *vars, int status, int id);

char				*ft_strjoin_gnl(char *s1, char *s2);
char				*ft_itoa(int n);
int					is_every_one_ate(t_args *vars);
char				*ft_strjoin_gnl(char *s1, char *s2);
void				init_philos(t_args *vars);

void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstadd_back(t_list **lst, t_list *node);
t_list				*ft_lstnew(void *content);

void				*my_alloc(size_t size);
void				custom_exit(int exit_code);

#endif