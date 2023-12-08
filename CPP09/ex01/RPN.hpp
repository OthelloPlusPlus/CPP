/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RPN.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohengelm <ohengelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/08 19:20:17 by ohengelm      #+#    #+#                 */
/*   Updated: 2023/12/08 19:20:17 by ohengelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

class RPN
{
	private:

	protected:

	public:
		RPN(void);
		RPN(const RPN &src);
		~RPN(void);

		RPN	&operator=(const RPN &src);
};

#endif
