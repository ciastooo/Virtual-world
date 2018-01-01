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
			if (search->getNext() != nullptr) {
				search->getNext()->setPrev(newItem);
				newItem->setNext(search->getNext());
			}
			search->setNext(newItem);
			newItem->setPrev(search);
		}
		else {
			if (search->getPrev() != nullptr) {
				search->getPrev()->setNext(newItem);
				newItem->setPrev(search->getPrev());
			}
			else {
				head = newItem;
			}
			newItem->setNext(search);
			search->setPrev(newItem);
		}

	}
}
void OrganismList::doAction() {
	OrganismListItem *current = head;
	while (current != nullptr) {
		if (current->getOrganism()->getToDelete()) {
			OrganismListItem *toRemove = current;
			current = current->getNext();
			this->remove(toRemove);
		}
		else {
			current->getOrganism()->action();
			current = current->getNext();
		}
	}
}
void OrganismList::drawAll() {
	OrganismListItem *current = head;
	while (current != nullptr) {
		if (current->getOrganism()->getToDelete()) {
			OrganismListItem *toRemove = current;
			current = current->getNext();
			this->remove(toRemove);
		}
		else {
			current->getOrganism()->draw();
			current = current->getNext();
		}
	}
}
void OrganismList::remove(OrganismListItem *toRemove) {
	OrganismListItem *tmpPrev = toRemove->getPrev();
	OrganismListItem *tmpNext = toRemove->getNext();
	if (tmpNext == nullptr && tmpPrev == nullptr) {
		head = nullptr;
	}
	else {
		if (tmpPrev != nullptr) {
			tmpPrev->setNext(tmpNext);
		}
		if (tmpNext != nullptr) {
			tmpNext->setPrev(tmpPrev);
			if (head == toRemove) {
				head = tmpNext;
			}
		}
	}
	delete toRemove;
}
OrganismListItem* OrganismList::search(int x, int y) {
	OrganismListItem *search = head;
	while (search != nullptr) {
		Organism *searchOrganism = search->getOrganism();
		if (searchOrganism->getToDelete()) {
			OrganismListItem *toRemove = search;
			search = search->getNext();
			this->remove(toRemove);
		}
		else {
			if (searchOrganism->getX() == x && searchOrganism->getY() == y) {
				return search;
			}
			else {
				search = search->getNext();
			}
		}
	}
	return nullptr;
}
void OrganismList::refreshMove() {
	OrganismListItem *current = head;
	while (current != nullptr) {
		current->getOrganism()->setCanMove(true);
		current = current->getNext();
	}
}
void OrganismList::writeToFile(ofstream &file) {
	OrganismListItem *current = head;
	while (current != nullptr) {
		Organism *currentOrganism = current->getOrganism();
		file << currentOrganism->getSymbol() << endl;
		file << currentOrganism->getX() << endl;
		file << currentOrganism->getY() << endl;
		current = current->getNext();
	}
}