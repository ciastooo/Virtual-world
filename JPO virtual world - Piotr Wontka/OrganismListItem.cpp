#include "OrganismListItem.h"

OrganismListItem::OrganismListItem(Organism *src) {
	this->organism = src;
	this->next = nullptr;
	this->prev = nullptr;
}
OrganismListItem::~OrganismListItem() {
	delete this->organism;
}
void OrganismListItem::setNext(OrganismListItem *newNext) {
	this->next = newNext;
}
void OrganismListItem::setPrev(OrganismListItem *newPrev) {
	this->prev = newPrev;
}
OrganismListItem* OrganismListItem::getNext() {
	return this->next;
}
OrganismListItem* OrganismListItem::getPrev() {
	return this->prev;
}
Organism* OrganismListItem::getOrganism() {
	return this->organism;
}
