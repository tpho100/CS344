#ifndef _integer_h_
#define _integer_h_

class Integer
{
	public:
		//constructors
		Integer(){count = 0; value = 0;};
		Integer(int v) {count = 0; value = v;}
		
		//getters
		int get_value() const;
		int get_count() const;

		//member operators
		bool operator<(const Integer &i);
		bool operator<=(const Integer &i);

	private:
		int value, count;
};

#endif
