/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleon-go@student.42malaga.co <eleon-go>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 19:23:37 by eleon-go@st       #+#    #+#             */
/*   Updated: 2023/08/03 16:07:36 by eleon-go@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Indicamos que LIBFT_H no esta definido de serie, para definirlo nosotros*/
#ifndef LIBFT_H
# define LIBFT_H

/*Incluimos las librerias necesarias para nuestras funciones*/
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

/*Indicamos el tipo de estructura de s_list y que es un valor void*/
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/* -V- Ahora vamos a integrar las funciones que componen esta libreria	-V- */

/* -V-							PRIMERA PARTE 							-V- */

/*Esta funcion devuelve "1" si cumple que el imput sea un caracter alfabetico*/
int		ft_isalpha(int c);

/*Esta funcion devuelve "1" si cumple que el imput sea un numero (0-9)*/
int		ft_isdigit(int c);

/*Esta funcion devuelve "1" si cumple que el imput sea un numero o letra*/
int		ft_isalnum(int c);

/*Esta funcion devuelve "1" si cumple que el imput sea un ASCII*/
int		ft_isascii(int c);

/*Esta funcion devuelve "1" si cumple que el imput sea imprimible*/
int		ft_isprint(int c);

/* Esta función cuenta los caracteres del imput y devuelve la longitud*/
size_t	ft_strlen(const char *s);

/*Este codigo convierte las minusculas en mayuscula, todo un lujo...*/
int		ft_toupper(int c);

/*Este codigo convierte las mayusculas en minusculas, UP2u*/
int		ft_tolower(int c);

/*Esta funcion escribe 0 bytes en el espacio n, si n es 0, no hace nada 
utilizamos*/
void	ft_bzero(void *s, size_t n);

/*copia el caracter c (un char sin signo) a los primeros n caracteres de str*/
void	*ft_memset(void *b, int c, size_t len);

/*Se utiliza para copiar una cantidad especificada de bytes de una ubicación de 
memoria a otra*/
void	*ft_memcpy(void *dst, const void *src, size_t n);

/*se usa para mover un bloque de memoria de una ubicación a otra sin interferir 
con los datos que contiene*/
void	*ft_memmove(void *dst, const void *src, size_t len);

/*se usa para copiar una cadena de caracteres de una ubicación a otra*/
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

/*Se usa para concatenar una cadena de caracteres a otra*/
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

/*Devuelve un puntero a la primera ubicacion del string*/
char	*ft_strchr(const char *s, int c);

/*Devuelve un puntero a la ultima ubicacion del string*/
char	*ft_strrchr(const char *s, int c);

/*Compara dos cadenas de string*/
int		ft_strncmp(const char *s1, const char *s2, size_t size);

/*Compara los Bytes de memoria de dos valores de memoria*/
void	*ft_memchr(const void *s, int c, size_t n);

/*Compara los Bytes de memoria de dos strings*/
int		ft_memcmp(const void *s1, const void *s2, size_t n);
/*A*/
char	*ft_strnstr(const char *big, const char *little, size_t len);

/*A*/
int		ft_atoi(const char *nptr);

/*A*/
void	*ft_calloc(size_t nmemb, size_t size);

/*A*/
char	*ft_strdup(const char *s);

/* -V-							SEGUNDA PARTE 							-V- */

/*A*/
char	*ft_substr(char const *s, unsigned int start, size_t len);

/*A*/
char	*ft_strjoin(char const *s1, char const *s2);

/*A*/
char	*ft_strtrim(char const *s1, char const *set);

/*A*/
char	**ft_split(char const *s, char c);

/*A*/
char	*ft_itoa(int n);

/*A*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/*A*/
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

/*Funcion para imprimir en pantalla :)*/
void	ft_putchar_fd(char c, int fd);

/*A*/
void	ft_putstr_fd(char *s, int fd);

/*A*/
void	ft_putendl_fd(char *s, int fd);

/*A*/
void	ft_putnbr_fd(int n, int fd);

/* -V-							PARTE DE BONUS 							-V- */

/*A*/
t_list	*ft_lstnew(void *content);

/*A*/
void	ft_lstadd_front(t_list **lst, t_list *new);

/*A*/
int		ft_lstsize(t_list *lst);

/*A*/
t_list	*ft_lstlast(t_list *lst);

/*A*/
void	ft_lstadd_back(t_list **lst, t_list *new);

/*A*/
void	ft_lstdelone(t_list *lst, void (*del)(void *));

/*A*/
void	ft_lstclear(t_list **lst, void (*del)(void *));

/*A*/
void	ft_lstiter(t_list *lst, void (*f)(void *));

/*A*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/* -V-							PRINTF FUNUCIONES 						-V- */

/*A*/
int		ft_printf(const char *str, ...);

/*A*/
int		ft_putnbr(long num);

/*A*/
int		ft_putchar(int c);

/*A*/
int		ft_putstr(char *str);

/*A*/
int		ft_saver(unsigned int long ptr);

/*A*/
int		ft_unsigned_int(unsigned int long num);

/*A*/
int		ft_hexadecimal(unsigned int num, char c);

#endif