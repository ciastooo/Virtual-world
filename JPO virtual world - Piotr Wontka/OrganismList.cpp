#include "OrganismList.h"

OrganismList::OrganismList() {
	this->head = nullptr;
}
OrganismList::~OrganismList() {

}
void OrganismList::insert(Organism *data) {
	OrganismListItem *newItem = new OrganismListItem(data);
	if (this->head == nullptr) {
		head = newItem;
	}
	else {
		OrganismListItem* search = head;
		while (search->getOrganism()->getInitiative() > data->getInitiative()) {
			if (search->getNext() == nullptr) {
				break;
			}
			else {
				search = search->getNext();
			}
		}
		newItem->setPrev(search->getPrev());
		newItem->setNext(search->getNext());
		search->setPrev(newItem);
		if (newItem->getPrev() != nullptr) {
			search = newItem->getPrev();
			search->setNext(newItem);
		}
	}
}