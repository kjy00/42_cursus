#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie {
	private:
		std::string _name;
	public:
		void	announce(void);
		Zombie();
		Zombie(std::string name);
		~Zombie();
};

#endif
