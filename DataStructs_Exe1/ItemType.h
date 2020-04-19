#pragma once
class ItemType
{
private:
	int chosenComputerId;

public:
	ItemType() {}
	ItemType(int computerId) {
		this->chosenComputerId = computerId;
	}

	~ItemType() {}

	int getChosenComputerId() {
		return chosenComputerId;
	}

	void setChosenComputerId(int computerId) {
		this->chosenComputerId = computerId;
	}
};

