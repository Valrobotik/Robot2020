#include "type.h"
#include <stdlib.h>
class coorTab {
	public: 
		coorTab();
		void add(Point *coor);
		Point* remove();
		Point* get(int index);
		Point* last();
		Point* first();
		void test();
		int size();
	private:
		Point **m_coor;
		int m_size;
};
