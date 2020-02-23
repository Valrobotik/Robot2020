#include "coorTab.h"
coorTab::coorTab() {
	this->m_size = 0;
}

/*
 * ajoute une coordonnée à la fin du tableau
 */
void coorTab::add(Point *coor) {
	//recalcule lindex du tableaux de coordonnées
	Point **temp;
	int k;
	
	temp = (Point**)malloc(sizeof(Point*) * (this->size()+1));
	k = 0;
	while (k < this->size())
	{
		temp[k] = this->m_coor[k];
		k++;
	}
  Point *new_ = (Point*)malloc(sizeof(Point));
  new_ = coor;
  temp[k] = new_;
	//temp[k] = coor;
	if (this->m_coor != NULL)
		free(this->m_coor);
	this->m_coor = temp;
	this->m_size++;
}


/*
 * supprime la première coordonnée du tableau
 */
Point* coorTab::remove() {
	int k;
	Point *ret;
	ret = this->m_coor[0];
	//free(this->m_coor[0]);
	k = 0;
	while (k < this->size() - 1)
	{
		this->m_coor[k] = this->m_coor[k + 1];
		k++;
	}
  
	this->m_size--;
	return (ret);
}


Point* coorTab::get(int index) {
	//return le pointeur de la coordonnée souhaitée
	return this->m_coor[index];
}
Point* coorTab::last() {
	Point *ret;
	if(this->size()==0) {
		Point a;a.x=-1;a.y=-1;
		ret = &a;
	}else{
	 ret = this->get(this->size() - 1);
	}	
return ret;
}
Point* coorTab::first() {
	return this->get(0);
}
int coorTab::size() {
	return this->m_size;
	
}
void coorTab::test() {
	
}
	
