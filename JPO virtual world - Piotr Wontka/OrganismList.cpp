#include "OrganismList.h"

OrganismList::OrganismList() {
	this->head = nullptr;
}
OrganismList::~OrganismList() {
	if (head == nullptr) {
		return;
	}
	OrganismListItem *current = head;
	while (current->getNext() != nullptr) {
		current = current->getNext();
	}
	OrganismListItem *tmp;
	while (current->getPrev() != nullptr) {
		tmp = current->getPrev();
		delete current;
		current = tmp;
	}
	delete current;
}
void OrganismList::insert(Organism *data) {
	OrganismListItem *newItem = new OrganismListItem(data);
	if (this->head == nullptr) {
		head = newItem;
	}
	else {
		OrganismListItem* search = head;
		while (search->getOrganism()->getInitiative() >= data->getInitiative()) {
			if (search->getNext() == nullptr) {
				break;
			}
			else {
				search = search->getNext();
			}
		}
		if (search->getOrganism()->getInitiative() >= data->getInitiative()) {
			newItem->setNext(search->getNext());
			search->setNext(newItem);
			newItem->setPrev(search);			
		}
		else {
			newItem->setPrev(search->getPrev());
			newItem->setNext(search);
			search->setPrev(newItem);
			if (head == search) {
				head = newItem;
			}
		}
		
	}
}
void OrganismList::doAction() {
	OrganismListItem *current = head;
	while (current != nullptr) {
		current->getOrganism()->action();
		current = current->getNext();
	}
}
void OrganismList::drawAll() {
	OrganismListItem *current = head;
	while (current != nullptr) {
		current->getOrganism()->draw();
		current = current->getNext();
	}
}
void OrganismList::remove(Organism *toRemove) {
	OrganismListItem *current = head;
	while (current != nullptr && current->getOrganism() != toRemove) {
		current = current->getNext();
	}
	if (current->getOrganism() == toRemove) {
		OrganismListItem *tmpPrev = current->getPrev();
		OrganismListItem *tmpNext = current->getNext();
		if (tmpNext == nullptr && tmpPrev == nullptr) {
			head = nullptr;
		}
		else {
			if (tmpPrev != nullptr) {
				tmpPrev->setNext(tmpNext);
			}
			if (tmpNext != nullptr) {
				tmpNext->setPrev(tmpPrev);
				if (head == current) {
					head = tmpNext;
				}
			}
		}
		delete current;
	}
}